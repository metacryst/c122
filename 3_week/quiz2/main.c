/*
	This example illustrates how to implement a singly linked
	list in C.

	History: 9/3 - Implemented makeNode (), insertFront (),
	               and started discussing insertOrder ().
			 9/1 - Defined the required structs for the example
			       including struct Data, Node, and List. We
				   also implemented initList ()
*/

#include "LinkedList.h"

int main(int argc, char *argv[])
{
	List intCollection = {NULL};
	

	initList(&intCollection);

	insertFront(&intCollection, 1999);	
	insertFront(&intCollection, 2001);
	insertFront(&intCollection, 2004);
	
	printf("Data of head: %d\n", intCollection.pHead->data);
	printf("Data of 2: %d\n", intCollection.pHead->pNext->data);
	printf("Data of 3: %d\n", intCollection.pHead->pNext->pNext->data);
	
	int deleteSuccess = 0;
	Node** doubleHeadPointer = &intCollection.pHead;
	int data = 0;
	deleteSuccess = deleteAtPositionN(doubleHeadPointer, 2, &data);
	
	printf("~~~\n");
	printf("Data of 2: %d\n", intCollection.pHead->pNext->data);
	
	return 0;
}