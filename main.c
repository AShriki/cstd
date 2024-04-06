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
    LinearNodeContainer(MyNodeTypeA, mylist);
    for (int i = 0; i < 500; i++){
        MyNodeTypeA a = {i,2.+i/10,i+i/10,"aaa"};
        pushRight(&mylist,&a);
    }
    int c = mylist.count;
    for (int i = 0; i < c; i++){
        MyNodeTypeA tmp;
        popLeft(&mylist,&tmp);
        printf("%d\n",tmp.a);
    }
    return 0;
}