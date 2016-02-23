#ifndef RBT_NAME_RANGE_H
#define RBT_NAME_RANGE_H
    #include "rbt_range.h"

    enum {
        var,
        and,
        or
    };

    struct rbt_logic {
        int type;               /* cond, and, or */
        char * name;
        size_t length;
        rbt_range * range;
        struct rbt_logic * p; /* parent */
        struct rbt_logic * l; /* left */
        struct rbt_logic * r; /* right */
        struct rbt_logic * s; /* stack */
    };

    int rbt_logic_init(struct rbt_logic **, char *, rbt_range *);
    int rbt_logic_deit(struct rbt_logic **);

    typedef struct rbt_logic rbt_logic;
#endif