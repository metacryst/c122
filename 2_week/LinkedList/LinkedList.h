#ifndef LINKED_LIST_H
#define LINKED_LIST_H // guard code

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// the p in front of variables stands for pointer

typedef struct data {
    char movieTitle[50]; // 50 bytes
    int year; // 4 bytes
} Data; // 54 bytes

typedef struct node {
    Data movie; // 54 bytes
    struct node* pNext; // 4 bytes
} Node; // 58 bytes

typedef struct list {
    Node* pHead;
} List;

void initList(List *pList);
Node* makeNode(const Data *pNewData);
// passing pointer so we can access original
int insertFront(List *pList, const Data* pNewData);
// order: movie title, ascending (A-Z)
int insertOrder(List *pList, const Data* pNewData);

#endif