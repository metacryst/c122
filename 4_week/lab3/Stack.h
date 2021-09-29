#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackNode {
    double data;
    struct stackNode* below;
} StackNode;

typedef struct stack {
    StackNode* top;
} Stack;

Stack* pStack;

int isEmpty();
int push(double data);
int pop();
double top();