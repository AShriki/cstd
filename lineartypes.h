#ifndef __CLINTYPES__
#define __CLINTYPES__

#include "basemacro.h"

/* STRUCTS VVV */
typedef struct linearnode{
    void * data;
    struct linearnode * next;
    struct linearnode * previous;
    int value;
}LinNode;

typedef struct linearnodecontainer{
    LinNode * head;
    LinNode * tail;
    size_t data_size;
    int count;
}LinContainer;
/* STRUCTS ^^^ */

#define UNIQ_NODE linearnode
#define UNIQ_CONTAINER linearcontainer

/*
@brief Linear Node is used as a type for nodes used in single/double linked lists,
stacks,deque,etc..
@param val_type: The data type contained by the node
*/
#define LinearNode(val_type) \
struct GENERATE_STRUCT_ID(UNIQ_NODE,val_type)

/*
@brief Linear Node Type Container declares a structure type to reduce 
boilerplate needed for declaring the node used in single/double linked lists,
stacks,deque,etc..
@param val_type: The data type contained by the node
*/
#define LinearNodeType(val_type)\
LinearNode(val_type){\
    val_type * data;\
    LinearNode(val_type) * next;\
    LinearNode(val_type) * previous;\
    int value;\
}

/*
@brief Linear Node Container Type declares a structure type to reduce 
boilerplate needed for declaring single/double linked lists,stacks,deque,etc..
@param val_type: The data type contained by the node
*/
#define LinearNodeContainerType(val_type)\
LinearNodeType(val_type); \
struct GENERATE_STRUCT_ID(UNIQ_CONTAINER,val_type){\
    LinearNode(val_type) * head; \
    LinearNode(val_type) * tail; \
    size_t data_size;\
    int count; \
}

/*
@brief Linear Node Container is used a type to declaring an instance 
of single/double linked lists,stacks,deque,etc..
@param val_type: The data type contained by the node
*/
#define LinearNodeContainer(val_type, list_name) \
struct GENERATE_STRUCT_ID(UNIQ_CONTAINER,val_type) list_name={VOID_PTR, VOID_PTR, sizeof(val_type), 0}

// LIST ACTIONS VVV
int pushRight(void *container, void * data);
int pushLeft(void *container, void * data);
int popRight(void * container, void * data);
int popleft(void * container, void * data);
int delete(void * container);
// LIST ACTIONS ^^^
#endif