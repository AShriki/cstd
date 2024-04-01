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

int main(){
    char * s = "aaa";
    LinearNodeContainer(MyNodeTypeA) mylist;
    MyNodeTypeA a = {1,2.3,4.5,"cba"};
    MyNodeTypeA b = {6,7.8,9.10,"abc"};
    MyNodeTypeA *c = malloc(sizeof(MyNodeTypeA));
    memcpy(c,&b,sizeof(MyNodeTypeA));
    b.d = s;
    printf("here\n");
    pushRight(&mylist,&a,sizeof(MyNodeTypeA));
    // pushRight(&mylist,&b,sizeof(MyNodeTypeA));
    // pushRight(&mylist,c,sizeof(MyNodeTypeA));
    // printf("%d\n",mylist.count);
    // printf("%s\n",mylist.head->data->d);
    // printf("%s\n",mylist.head->next->data->d);
    // printf("%s\n",mylist.head->next->next->data->d);
    return 0;
}