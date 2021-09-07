#include "LinkedList.h"

void initList(List* pList)
{
	// empty list
	pList->pHead = NULL; // (*pList).pHead = NULL;
}

// heap memory sticks around in scope until we decide to delete it
Node* makeNode(const Data* pNewData) {
    // malloc is the function that goes to the heap and requests bytes
    // parameter determines how many bytes
    // optional : casting void * return type of malloc to Node *
    Node *pMem = (Node *) malloc(sizeof(Node));
    
    if(pMem != NULL) {
        // malloc succeeded at allocating space for a Node
        pMem->movie.year = pNewData->year;
        strcpy(pMem->movie.movieTitle, pNewData->movieTitle);
        pMem->pNext = NULL;
    }
    
    return pMem;
};

int insertFront(List* pList, const Data* pNewData) {
    Node* pMem = makeNode(pNewData);
    int success = 0;
    
    if(pMem != NULL)
    {
        // makeNode - malloc() allocates space successfully
        success = 1;
        pMem->pNext = pList->pHead;
        pList->pHead = pMem;
    }
    
    return success;
}

int insertOrder(List* pList, const Data* pNewData) {
    Node* pMem = makeNode(pNewData), *pCur = pList->pHead, *pPrev=NULL;
    int success = 0;
    
    if(pMem != NULL) {
        
    }
}