#ifndef RBT_NAME_RANGE_H
#define RBT_NAME_RANGE_H
    #include "stdio.h"
    #include "string.h"
    #include "rbt_range.h"

    /* rbt_name_range's implementation is extremely
     * inefficient in certain cases where sub-trees
     * are copied many times over, but it is easier
     * to implement it this way.
     *
     * also this implementation uses excessive extra
     * and and or nodes to preserve the structure of
     * the logical expression, which is unnecessary,
     * but makes the implementation easier.
     * :D  */

    enum {
        var,
        and,
        or
    };

    struct rbt_logic {
        int type;               /* var, and, or */
        char * name;
        size_t length;
        rbt_range * range;
        struct rbt_logic * p; /* parent */
        struct rbt_logic * l; /* left */
        struct rbt_logic * r; /* right */
    };

    int rbt_logic_var_init(struct rbt_logic **, char *, rbt_range *);
    int rbt_logic_var_copy(struct rbt_logic **, struct rbt_logic *);
    int rbt_logic_init(struct rbt_logic **, struct rbt_logic *, struct rbt_logic *, int);
    int rbt_logic_deit(struct rbt_logic **);
    int rbt_logic_copy(struct rbt_logic **, struct rbt_logic *);
    int rbt_logic_dump(struct rbt_logic *);
    int rbt_logic_op(struct rbt_logic *, struct rbt_logic *, struct rbt_logic **, int);

    typedef struct rbt_logic rbt_logic;
#endif
