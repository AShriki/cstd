#ifndef __TREE_IN_C__
#define __TREE_IN_C__

#include "baseMacro.h"

#define UNIQ tree

#define TreeNode(valType) \
struct GENERATE_STRUCT_ID(UNIQ,valType) {\
    valType data;\
    int value;\
    struct valType * left;\
    struct valType * right;\
}
#define Tree(ValType) \
struct GENERATE_STRUCT_ID(UNIQ,valType) {\
    valType data;\
    int value;\
    struct valType * left;\
    struct valType * right;\
}

#endif