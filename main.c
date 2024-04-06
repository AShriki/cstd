#include <stdio.h>
#include <string.h>
#include "include/lineartypes.h"
#include "include/tree.h"
typedef struct myNodeA {
    int a;
    double b;
    float c;
    char * d;
} MyNodeTypeA;

typedef struct myNodeB {
    double b;
} MyNodeTypeB;

DeclareLinearContainer(MyNodeTypeA);
DeclareTree(MyNodeTypeA);

int main(){
    LinearContainer(MyNodeTypeA, mylist);
    Tree(MyNodeTypeA, mytree);
    mytree.head;
    return 0;
}