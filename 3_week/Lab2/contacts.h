#ifndef LINKED_LIST_H
#define LINKED_LIST_H // guard code

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum boolean
{
    FALSE, 
    TRUE
} Boolean;

typedef struct contact
{
    char name[50];
    char phone[12]; // 18005557577
    char email[50];
    char title[20];
} Contact;

typedef struct node
{
	Contact contact;
	struct node* nextPointer;
} Node;

typedef struct list
{
	Node* headPointer;
} List;

void initList(List* listPointer);
Node* makeNode(const Contact* contactPointer);
int insertFront(List* listPointer, const Contact* contactPointer);
int insertContactInOrder(List* listPointer, const Contact* contactPointer);
int deleteAtPositionN (struct node **pHead, int n, Contact* contactPointer);
void printList(List* listPointer);

char* stringCompare(char* string1, char* string2);


#endif