#include "Stack.h"

StackNode* makeNode(double data)
{
	StackNode* newNode = (StackNode *) malloc(sizeof(StackNode));

	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->below = NULL;
	}

	return newNode;
}

int push(double data)
{
	StackNode* newNode = makeNode(data);
	int success = 0;

	if (newNode != NULL)
	{
		success = 1;
        if(pStack->top) {
            newNode->below = pStack->top;
        }
        pStack->top = newNode;
	}

	return success;
}

int isEmpty() {
    if(!(pStack->top)) {
        return 1;
    } else {
        return 0;
    }
}

int pop() {
    if(pStack->top->below) {
        StackNode* temp = pStack->top;
        pStack->top = pStack->top->below;
        free(temp);
        return 1;
    } else if(pStack->top) {
        StackNode* temp = pStack->top;
        free(temp);
        pStack->top = NULL;
        return 1;
    } else {
        return 0;
    }
}

double top() {
    return pStack->top->data;
}