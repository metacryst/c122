#ifndef LINKED_LIST_H
#define LINKED_LIST_H // guard code

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node
{
	int data; // 54 bytes
	struct node* pNext; // 4 bytes
} Node; // 58 bytes

typedef struct list
{
	Node* pHead;
} List;

void initList(List *pList);
Node* makeNode(const int data);
int insertFront(List *pList, const int data);
// order - ascending - 'A' - 'Z' based on movie title
int insertOrder(List* pList, const int data);
int deleteAtPositionN (struct node **pHead, int n, int *pData);


#endif