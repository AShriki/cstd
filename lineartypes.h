#ifndef __CLINTYPES__
#define __CLINTYPES__

#include "basemacro.h"

#define UNIQ_NODE linearnode
#define UNIQ_CONTAINER linearcontainer

/*
@brief Linear Node is used as a type for nodes used in single/double linked lists,
stacks,deque,etc..
@param valType: The data type contained by the node
*/
#define LinearNode(valType) \
struct GENERATE_STRUCT_ID(UNIQ_NODE,valType)

/*
@brief Linear Node Type Container declares a structure type to reduce 
boilerplate needed for declaring the node used in single/double linked lists,
stacks,deque,etc..
@param valType: The data type contained by the node
*/
#define LinearNodeType(valType)\
LinearNode(valType){\
    valType * data;\
    LinearNode(valType) * next;\
    LinearNode(valType) * previous;\
    int value;\
}

/*
@brief Linear Node Container Type declares a structure type to reduce 
boilerplate needed for declaring single/double linked lists,stacks,deque,etc..
@param valType: The data type contained by the node
*/
#define LinearNodeContainerType(valType)\
LinearNodeType(valType); \
struct GENERATE_STRUCT_ID(UNIQ_CONTAINER,valType){\
    LinearNode(valType) * head; \
    LinearNode(valType) * tail; \
    int count; \
}

/*
@brief Linear Node Container is used a type to declaring an instance 
of single/double linked lists,stacks,deque,etc..
@param valType: The data type contained by the node
*/
#define LinearNodeContainer(valType)\
struct GENERATE_STRUCT_ID(UNIQ_CONTAINER,valType)

void pushRight(void *container, void * data, size_t data_struct_size);
void pushLeft(void *container, void * data, size_t data_struct_size);

#endif