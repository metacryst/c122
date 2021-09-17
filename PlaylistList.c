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

void printList() {
	Node* next = pPlaylist->head;
    if(!next) {
        printf("No songs found! Try running load command first.\n");
        return;
    }
    
    printf("\n\n");
    while(next) {
        printf("\n");
        printf("Artist: %s\n", next->data.artist);
        printf("Album: %s\n", next->data.albumTitle);
        printf("Song: %s\n", next->data.songTitle);
        printf("Genre: %s\n", next->data.genre);
        printf("Length: %d:%d\n", next->data.songLength.minutes, next->data.songLength.seconds);
        printf("Times Played: %d\n", next->data.timesPlayed);
        printf("Rating: %d\n", next->data.rating);
        
        next = next->next;
    }
    printf("\n");
}

void clearList() {
	Node* nodeToDelete = pPlaylist->head;

    while(nodeToDelete) {
        Node* nextNodeToDelete = NULL;
        if(nodeToDelete->next) {
            nextNodeToDelete = nodeToDelete->next;
            nextNodeToDelete->prev = NULL;
            pPlaylist->head = nextNodeToDelete;
            
            free(nodeToDelete);
            nodeToDelete = nextNodeToDelete;
        } else {
            pPlaylist->head = NULL;
            
            free(nodeToDelete);
            nodeToDelete = NULL;
        }
    }
}