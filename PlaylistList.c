#include "Playlist.h"

Node* makeNode(const Record data)
{
	Node* newNode = (Node *) malloc(sizeof(Node));

	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
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
		newNode->next = pPlaylist->head;
		if(pPlaylist->head) {
			pPlaylist->head->prev = newNode;
		}
		pPlaylist->head = newNode;
	}

	return success;
}