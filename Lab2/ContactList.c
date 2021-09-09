#include "contacts.h"

void initList(List* newList)
{
	newList->headPointer = NULL;
}

Node* makeNode(const Contact* newContact)
{
	Node* newNodePointer = (Node *) malloc(sizeof(Node));

	if (newNodePointer != NULL)
	{
		newNodePointer->contact = *newContact;
		newNodePointer->nextPointer = NULL;
	}

	return newNodePointer;
}

int insertFront(List* listPointer, const Contact* contact)
{
	Node* newNode = makeNode(contact);
	int success = 0;

	if (newNode != NULL)
	{
		success = 1;
		newNode->nextPointer = listPointer->headPointer;
		listPointer->headPointer = newNode;
	}

	return success;
}

int insertContactInOrder(List* listPointer, const Contact* contact)
{
	Node* newNode = makeNode(contact);
	int success = 0;
	
	if(newNode != NULL)
	{
		success = 1;
		
		int stringsToCompare = 0;
		
		Node* firstCompareNode = listPointer->headPointer;
		Node* secondCompareNode = NULL;
		
		while(stringsToCompare) {
			if(firstCompareNode->nextPointer) {
				secondCompareNode = firstCompareNode->nextPointer;
			}
			
		}
		
	}
	
	return success;
}


int deleteAtPositionN(struct node** headPointerPointer, int n, Contact* contactPointer)
{
	int success = 1;
	int failure = 0;
	
	if(n<=0) {
		return failure;
	}
	
	Node* nodeToDelete = *headPointerPointer;
	Node* prevNode = *headPointerPointer;
	
	for(int i = 1; i<n; i++) {
		nodeToDelete = nodeToDelete->nextPointer;
		if(i>1) {
			prevNode = prevNode->nextPointer;
		}
	}
	
	if(nodeToDelete->nextPointer) {
		prevNode->nextPointer = nodeToDelete->nextPointer;
	} else {
		prevNode->nextPointer = NULL;
	}
	
	*contactPointer = (nodeToDelete->contact);
	free(nodeToDelete);
	
	return success;
}

void printList(List* list) {
	if(!(list->headPointer)) {
		return;
	}

	printf("%s\n", list->headPointer->contact.name);
	printf("%s\n", list->headPointer->contact.phone);
	printf("%s\n", list->headPointer->contact.email);
	printf("%s\n", list->headPointer->contact.title);
	
	Node* nodeToPrint = list->headPointer->nextPointer;
	while(nodeToPrint) {
		printf("%s\n", nodeToPrint->contact.name);
		printf("%s\n", nodeToPrint->contact.phone);
		printf("%s\n", nodeToPrint->contact.email);
		printf("%s\n", nodeToPrint->contact.title);
		
		nodeToPrint = nodeToPrint->nextPointer;
	}
}
