#include "LinkedList.h"

void initList(List* pList)
{
	// empty list
	pList->pHead = NULL; // (*pList).pHead = NULL;
}

Node* makeNode(const int data)
{
	Node* pMem = (Node *) malloc(sizeof(Node)); // we tried to allocate space

	if (pMem != NULL)
	{
		// malloc succeeded in allocating a Node
		pMem->data = data;
		pMem->pNext = NULL;
	}

	return pMem;
}

int insertFront(List* pList, const int data)
{
	Node* pMem = makeNode(data);
	int success = 0;

	if (pMem != NULL)
	{
		// makeNode - malloc () allocates space successfully
		success = 1;
		pMem->pNext = pList->pHead;
		pList->pHead = pMem;
	}

	return success;
}

// order - ascending - 'A' - 'Z' based on movie title
int insertOrder(List* pList, const int data)
{
	Node* pMem = makeNode(data), *pCur = pList->pHead,
		*pPrev = NULL;
	int success = 0;

	if (pMem != NULL)
	{
		// allocated space for a Node just fine

	}
	
	return 0;
}

int deleteAtPositionN(struct node** pHead, int n, int *dataPointer)
{
	int success = 1;
	int failure = 0;
	
	if(n<=0) {
		return failure;
	}
	
	// these are equivalent: arrow traverses the pointer
	// printf("%d\n", (*pHead)->data);
	// printf("%d\n", (**pHead).data);
	
	Node* nodeToDelete = *pHead;
	Node* prevNode = *pHead;
	
	for(int i = 1; i<n; i++) {
		nodeToDelete = nodeToDelete->pNext;
		if(i>1) {
			prevNode = prevNode->pNext;
		}
	}
	
	if(nodeToDelete->pNext) {
		prevNode->pNext = nodeToDelete->pNext;
	}
	
	*dataPointer = (nodeToDelete->data);
	free(nodeToDelete);
	
	return success;
}