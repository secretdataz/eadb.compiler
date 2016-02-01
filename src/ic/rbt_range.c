#include "rbt_range.h"

#define calloc_ptr(x)       (NULL == ((x) = calloc(1, sizeof(*(x)))))
#define free_ptr_null(x)    if(x) { free(x); (x) = NULL; }
#define free_ptr_call(x, y) if(x) { y(&x); }
#define is_nil(x)           ((x) == NULL)
#define is_ptr(x)           ((x) != NULL)
#define is_last(x)          ((x) == (x)->next)

#ifndef min
#define min(x, y)           ((x < y) ? x : y)
#endif

#ifndef max
#define max(x, y)           ((x < y) ? y : x)
#endif

#define get_min(x)          (((struct range *) ((x)->val))->min)
#define get_max(x)          (((struct range *) ((x)->val))->max)

int range_init(struct range ** range, int min, int max) {
    struct range * object = NULL;

    if( is_nil( range) ||
        is_ptr(*range) ||
        calloc_ptr(object) )
        return 1;

    object->min = min(min, max);
    object->max = max(min, max);
    *range = object;
    return 0;
}

int range_deit(struct range ** range) {
    struct range * object;

    if( is_nil( range) ||
        is_nil(*range) )
        return 1;

    object = *range;
    free_ptr_null(object);
    *range = object;
    return 0;
}

int rbt_range_init(struct rbt_range ** rbt_range, int min, int max, int flag) {
    struct rbt_range * object = NULL;

    if( is_nil( rbt_range) ||
        is_ptr(*rbt_range) ||
        calloc_ptr(object) )
        return 1;

    if( rbt_tree_init(&object->ranges) ||
        range_init(&object->global, min, max) )
        goto failed;

    if(!flag)
        if(rbt_range_add(object, min, max, NULL))
            goto failed;

    *rbt_range = object;
    return 0;

failed:
    rbt_range_deit(&object);
    return 1;
}

static int rbt_range_deit_(struct rbt_range * rbt_range) {
    struct rbt_node * r;
    struct rbt_tree * t;

    t = rbt_range->ranges;
    if(t->root) {
        while(!is_last(t->root)) {
            r = t->root;
            /* inefficient; require optimization */
            rbt_delete(t, r);
            free_ptr_call( (struct range *) r->val, range_deit);
            free_ptr_call(r, rbt_node_deit);
        }
        free_ptr_call((struct range *) t->root->val, range_deit);
        free_ptr_call(t->root, rbt_node_deit);
    }

    return 0;
}

int rbt_range_deit(struct rbt_range ** rbt_range) {
    struct rbt_range * object;

    if( is_nil( rbt_range) ||
        is_nil(*rbt_range) )
        return 1;

    object = *rbt_range;
    rbt_range_deit_(object);
    free_ptr_call(object->ranges, rbt_tree_deit);
    free_ptr_call(object->global, range_deit);
    free_ptr_null(object);
    *rbt_range = object;
    return 0;
}

int rbt_range_dump(struct rbt_range * rbt_range, char * tag) {
    rbt_node * i, * r;
    struct range * range;

    fprintf(stderr, "[%s] [Min: %d Max: %d]\n", tag,
    rbt_range->global->min, rbt_range->global->max);

    if(rbt_min(rbt_range->ranges, &r))
        return 1;

    i = r;
    do {
        range = i->val;
        fprintf(stderr, " -> %d - %d\n", range->min, range->max);
        i = i->next;
    } while(i != r);

    return 0;
}

int rbt_range_min(struct rbt_range * rbt_range, int * min) {
    rbt_node * i;

    if(rbt_min(rbt_range->ranges, &i))
        return 1;

    *min = ((struct range *) (i->val))->min;
    return 0;
}

int rbt_range_max(struct rbt_range * rbt_range, int * max) {
    rbt_node * i;

    if(rbt_max(rbt_range->ranges, &i))
        return 1;

    *max = ((struct range *) (i->val))->max;
    return 0;
}

int rbt_range_add(struct rbt_range * rbt_range, int min, int max, struct range ** result) {
    struct range * range = NULL;
    struct rbt_node * node = NULL;

    if( range_init(&range, min, max) ||
        rbt_node_init(&node, range->max, range) ||
        rbt_insert(rbt_range->ranges, node) ) {
        /* failed to insert range */
        free_ptr_call(range, range_deit);
        free_ptr_call(node, rbt_node_deit);
        return 1;
    }

    if(result)
        *result = range;
    return 0;
}

int rbt_range_dup(struct rbt_range * rbt_range_x, struct rbt_range ** rbt_range_y) {
    rbt_node * i, * r;
    struct rbt_range * object = NULL;

    if( rbt_min(rbt_range_x->ranges, &r) ||
        rbt_range_init(&object, rbt_range_x->global->min, rbt_range_x->global->max, FLAG_RBT_EMPTY) )
        goto failed;

    i = r;
    do {
        if(rbt_range_add(object, get_min(i), get_max(i), NULL))
            goto failed;
        i = i->next;
    } while(i != r);

    *rbt_range_y = object;
    return 0;

failed:
    rbt_range_deit(&object);
    return 1;
}

int rbt_range_neg(struct rbt_range * rbt_range_x, struct rbt_range ** rbt_range_y) {
    int min;
    int max;
    rbt_node * i, * r;
    struct rbt_range * object = NULL;

    min = rbt_range_x->global->max * -1;
    max = rbt_range_x->global->min * -1;

    if( rbt_min(rbt_range_x->ranges, &r) ||
        rbt_range_init(&object, min, max, FLAG_RBT_EMPTY) )
        goto failed;

    i = r;
    do {
        min = -1 * get_max(i);
        max = -1 * get_min(i);
        if(rbt_range_add(object, min, max, NULL))
            goto failed;
        i = i->prev;
    } while(i != r);

    *rbt_range_y = object;
    return 0;

failed:
    rbt_range_deit(&object);
    return 1;
}

typedef int (*rbt_range_merge_func) (struct rbt_range *, struct range **, struct range *);

static int rbt_range_merge(struct rbt_range * rbt_range, struct rbt_node * xr, struct rbt_node * yr, rbt_range_merge_func merge) {
    rbt_node * xi = xr;
    rbt_node * yi = yr;
    struct range * range_next = NULL;
    struct range * range_last = NULL;

    /* merge sort algorithm for merging ranges */
    while(xi && yi) {
        if(get_min(xi) < get_min(yi)) {
            range_next = xi->val;
            xi = xi->next;
            if(xi == xr)
                xi = NULL;
        } else {
            range_next = yi->val;
            yi = yi->next;
            if(yi == yr)
                yi = NULL;
        }

        if(merge(rbt_range, &range_last, range_next))
            return 1;
    }

    while(xi) {
        range_next = xi->val;
        xi = xi->next;
        if(xi == xr)
            xi = NULL;
        if(merge(rbt_range, &range_last, range_next))
            return 1;
    }

    while(yi) {
        range_next = yi->val;
        yi = yi->next;
        if(yi == yr)
            yi = NULL;

        if(merge(rbt_range, &range_last, range_next))
            return 1;
    }

    return 0;
}

static int rbt_range_or_next(struct rbt_range * rbt_range, struct range ** last, struct range * next) {
    if(is_nil(*last)) {
        if (rbt_range_add(rbt_range, next->min, next->max, last))
            return 1;
    } else {
        if(next->min > (*last)->max + 1) {
            if(rbt_range_add(rbt_range, next->min, next->max, last))
                return 1;
        } else {
            (*last)->min = min((*last)->min, next->min);
            (*last)->max = max((*last)->max, next->max);
        }
    }
    return 0;
}

int rbt_range_or(struct rbt_range * rbt_range_x, struct rbt_range * rbt_range_y, struct rbt_range ** rbt_range_z) {
    int min, max;
    rbt_node * xr;
    rbt_node * yr;
    struct rbt_range * object = NULL;

    if( is_nil(rbt_range_x) ||
        is_nil(rbt_range_y) )
        return 1;

    min = min(rbt_range_x->global->min, rbt_range_y->global->min);
    max = max(rbt_range_x->global->max, rbt_range_y->global->max);

    if( rbt_range_init(&object, min, max, FLAG_RBT_EMPTY) ||
        rbt_min(rbt_range_x->ranges, &xr) ||
        rbt_min(rbt_range_y->ranges, &yr) ||
        rbt_range_merge(object, xr, yr, rbt_range_or_next) )
        goto failed;

    *rbt_range_z = object;
    return 0;

failed:
    free_ptr_call(object, rbt_range_deit);
    return 1;
}

int rbt_range_and(struct rbt_range * rbt_range_x, struct rbt_range * rbt_range_y, struct rbt_range ** rbt_range_z) {

    return 0;
}
