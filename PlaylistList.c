#include "Playlist.h"

Node* makeNode(const Record data)
{
	Node* newNode = (Node *) malloc(sizeof(Node));

	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}

	return newNode;
}

int insertFront(const Record* data)
{
	Node* newNode = makeNode(*data);
	int success = 0;

	if (newNode != NULL)
	{
		success = 1;
		newNode->next = PlaylistPointer->head;
		PlaylistPointer->head = newNode;
	}

	return success;
}