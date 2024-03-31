#include "lineartypes.h"
typedef struct linearnode{
    void * data;
    void * next;
    void * previous;
    int value;
}LinNode;

typedef struct linearnodecontainer{
    LinNode * head;
    LinNode * tail;
    int count;
}LinContainer;

void * popRight(void *container){
    LinContainer * cont = (LinContainer *)container;
    if (!cont->tail)
        return 0;
    LinNode * tmp_tail = (LinNode *)cont->tail;
    return (void *)tmp_tail;
}
void * popLeft(void *container){
    LinContainer * cont = (LinContainer *)container;
}
void pushRight(void *container, void * node){
    LinContainer * tmp_container = (LinContainer *)container;
    LinNode * tmp_node = (LinNode *)node;
    if (!cont->head)
}
void pushLeft(void *container){
    LinContainer * cont = (LinContainer *)container;
}
int find(void *container, int value){

}
void delete(void *container, int value){

}