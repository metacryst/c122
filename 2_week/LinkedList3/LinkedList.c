#include "LinkedList.h"

void initList(List* pList)
{
	// empty list
	pList->pHead = NULL; // (*pList).pHead = NULL;
}

Node* makeNode(const Data* pNewData)
{
	Node* pMem = (Node *) malloc(sizeof(Node)); // we tried to allocate space

	if (pMem != NULL)
	{
		// malloc succeeded in allocating a Node
		pMem->movie.year = pNewData->year;
		strcpy(pMem->movie.movieTitle, pNewData->movieTitle);
		pMem->pNext = NULL;
	}

	return pMem;
}

int insertFront(List* pList, const Data* pNewData)
{
	Node* pMem = makeNode(pNewData);
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
int insertOrder(List* pList, const Data* pNewData)
{
	Node* pMem = makeNode(pNewData), *pCur = pList->pHead,
		*pPrev = NULL;
	int success = 0;

	if (pMem != NULL)
	{
		// allocated space for a Node just fine

	}
	
	return 0;
}