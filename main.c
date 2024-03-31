#include <stdio.h>
#include "lineartypes.h"


typedef struct myNodeA {
    int a;
    double b;
    float c;
    char d[20];
} MyNodeTypeA;

typedef struct myNodeB {
    double b;
} MyNodeTypeB;

LinearNodeType(MyNodeTypeA);
LinearNodeContainerType(MyNodeTypeA);

int main(){
    LinearNodeContainer(MyNodeTypeA) mylist;
    LinearNode(MyNodeTypeA) mynodea;
    LinearNode(MyNodeTypeA) mynodec;
    MyNodeTypeA cd = {1,2.5,3.3,"cba"};
    MyNodeTypeA mn = {1,2.2,3.3,"abc"};
    mynodea.data = &cd;
    mynodec.data = &mn;
    printf("Hello, world A! %s\n", mynodea.data->d);
    // printf("Hello, world C! %f\n", mynodec.data->b);
    return 0;
}