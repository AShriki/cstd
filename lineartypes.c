#include "lineartypes.h"
#include <string.h>
#include <stdlib.h>
typedef struct linearnode{
    void * data;
    struct linearnode * next;
    struct linearnode * previous;
    int value;
}LinNode;

typedef struct linearnodecontainer{
    LinNode * head;
    LinNode * tail;
    int count;
}LinContainer;

void * popRight(void *container){
    LinContainer * tmp_container = (LinContainer *)container;
}
void * popLeft(void *container){
    LinContainer * tmp_container = (LinContainer *)container;
}
void pushRight(void *container, void * data, size_t data_struct_size){
    LinContainer * tmp_container = (LinContainer *)container;
    if (!tmp_container->tail && tmp_container->count == 0){
        tmp_container->tail = malloc(sizeof(LinNode));
        tmp_container->tail->data = malloc(data_struct_size);
        memcpy(tmp_container->tail->data, data, data_struct_size);
        tmp_container->head = tmp_container->tail;
    }else {
        tmp_container->tail->next = malloc(sizeof(LinNode));
        tmp_container->tail->next->data = malloc(data_struct_size);
        memcpy(tmp_container->tail->next->data, data, data_struct_size);
        tmp_container->tail->next->previous = tmp_container->tail;
        tmp_container->tail = tmp_container->tail->next;
    }
    tmp_container->count += 1;
}
void pushLeft(void *container, void * data, size_t data_struct_size){
    LinContainer * tmp_container = (LinContainer *)container;
    if (!tmp_container->head && tmp_container->count == 0){
        tmp_container->head = malloc(sizeof(LinNode));
        tmp_container->head->data = malloc(data_struct_size);
        memcpy(tmp_container->head->data, data, data_struct_size);
        tmp_container->head = tmp_container->tail;
    }else {
        tmp_container->head->previous = malloc(sizeof(LinNode));
        tmp_container->head->previous->next = tmp_container->head;
        memcpy(tmp_container->head->previous->data, data, data_struct_size);
        tmp_container->head = tmp_container->head->previous;
    }
    tmp_container->count += 1;
}
int find(void *container, int value){

}
void delete(void *container, int value){

}