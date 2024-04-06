#include "lineartypes.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int popRight(void * container, void * data){
    LinContainer * tmp_container = (LinContainer *)container;
    if (tmp_container->tail){
        memcpy(data, tmp_container->tail->data, tmp_container->data_size);
        free(tmp_container->tail->data);
        tmp_container->count--;
        if (tmp_container->tail == tmp_container->head){
            free(tmp_container->tail);
            tmp_container->head = VOID_PTR;
            tmp_container->tail = VOID_PTR;
            return 0;
        }
        tmp_container->tail = tmp_container->tail->previous;
        LinNode * target_node = tmp_container->tail->next;
        tmp_container->tail->next = tmp_container->tail->next->next;
        free(target_node);
    }
    return 0;
}
int popLeft(void * container, void * data){
    LinContainer * tmp_container = (LinContainer *)container;
    if (tmp_container->head){
        memcpy(data, tmp_container->head->data, tmp_container->data_size);
        free(tmp_container->head->data);
        tmp_container->count--;
        if (tmp_container->tail == tmp_container->head){
            free(tmp_container->tail);
            tmp_container->head = VOID_PTR;
            tmp_container->tail = VOID_PTR;
            return 0;
        }
        tmp_container->head = tmp_container->head->next;
        LinNode * target_node = tmp_container->head->previous;
        tmp_container->head->previous = tmp_container->head->previous->previous;
        free(target_node);
    }
    return 0;
}
int pushRight(void *container, void * data){
    LinContainer * tmp_container = (LinContainer *)container;
    if (!tmp_container->tail && tmp_container->count == 0){
        tmp_container->tail = malloc(sizeof(LinNode));
        tmp_container->tail->data = malloc(tmp_container->data_size);
        memcpy(tmp_container->tail->data, data, tmp_container->data_size);
        tmp_container->head = tmp_container->tail;
    }else {
        tmp_container->tail->next = malloc(sizeof(LinNode));
        tmp_container->tail->next->data = malloc(tmp_container->data_size);
        memcpy(tmp_container->tail->next->data, data, tmp_container->data_size);
        tmp_container->tail->next->previous = tmp_container->tail;
        tmp_container->tail = tmp_container->tail->next;
    }
    tmp_container->count += 1;
    return 0;
}
int pushLeft(void *container, void * data){
    LinContainer * tmp_container = (LinContainer *)container;
    if (!tmp_container->head && tmp_container->count == 0){
        tmp_container->head = malloc(sizeof(LinNode));
        tmp_container->head->data = malloc(tmp_container->data_size);
        memcpy(tmp_container->head->data, data, tmp_container->data_size);
        tmp_container->head = tmp_container->tail;
    }else {
        tmp_container->head->previous = malloc(sizeof(LinNode));
        tmp_container->head->previous->data = malloc(tmp_container->data_size);
        tmp_container->head->previous->next = tmp_container->head;
        memcpy(tmp_container->head->previous->data, data, tmp_container->data_size);
        tmp_container->head = tmp_container->head->previous;
    }
    tmp_container->count += 1;
    return 0;
}
int delete(void * container){
    LinContainer * tmp_container = (LinContainer *)container;
    int c = tmp_container->count;
    for (int i = 0; i < c; i++){
        LinNode tmp;
        popLeft(tmp_container,&tmp);
    }
    return 0;
}