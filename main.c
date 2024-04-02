#include <stdio.h>
#include <string.h>

#include "lineartypes.h"
typedef struct myNodeA {
    int a;
    double b;
    float c;
    char * d;
} MyNodeTypeA;

typedef struct myNodeB {
    double b;
} MyNodeTypeB;

LinearNodeContainerType(MyNodeTypeA);

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

int main(){
    LinearNodeContainer(MyNodeTypeA) mylist;
    MyNodeTypeA a = {1,2.3,4.5,"cba"};
    MyNodeTypeA b = {6,7.8,9.10,"aaa"};
    MyNodeTypeA c = {11,12.13,14.15,"abca"};
    pushRight(&mylist,&a,sizeof(MyNodeTypeA));
    pushRight(&mylist,&b,sizeof(MyNodeTypeA));
    pushRight(&mylist,&c,sizeof(MyNodeTypeA));
    printf("%d\n",mylist.count);
    printf("%s\n",mylist.head->data->d);
    printf("%s\n",mylist.head->next->data->d);
    printf("%s\n",mylist.head->next->next->data->d);
    return 0;
}