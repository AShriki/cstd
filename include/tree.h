#ifndef __TREE_IN_C__
#define __TREE_IN_C__

#include "basemacro.h"

struct ntree {
    void * data;
    int rank;
    struct ntree *kids;
    struct ntree *siblings;
};

#define UNIQ_TREE_NODE treenodetype
#define UNIQ_TREE_CONTAINER treenodecontainer

#define TreeNodeType(val_type) \
struct GENERATE_STRUCT_ID(UNIQ_TREE_NODE,val_type)

#define DeclareTreeNode(val_type) \
TreeNodeType(val_type) { \
    val_type * data; \
    int rank; \
    TreeNodeType(val_type) * kids; \
    TreeNodeType(val_type) * siblings; \
}

#define TreeStruct(val_type) \
struct GENERATE_STRUCT_ID(UNIQ_TREE_CONTAINER,val_type)

#define DeclareTree(val_type) \
DeclareTreeNode(val_type); \
TreeStruct(val_type) { \
    TreeNodeType(val_type) * head; \
    size_t data_size; \
    int count; \
}
#define Tree(val_type, name) \
TreeStruct(val_type) name = {VOID_PTR, sizeof(val_type), 0}

#endif