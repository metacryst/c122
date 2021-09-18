#include "Playlist.h"

// indented functions are within local scope only

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
        void incrementPositions(Node* node) {
            if(node) {
                node->position += 1;
                incrementPositions(node->next);
            }
        }
int insertFront(const Record* data)
{
	Node* newNode = makeNode(*data);
    newNode->position = 1;

	if (newNode == NULL){
		return 0;
    }
    
	newNode->next = pPlaylist->head;
	if(newNode->next) {
		newNode->next->prev = newNode;
	}
	pPlaylist->head = newNode;
    
    Node* nextNode = newNode->next;
    incrementPositions(nextNode);
    
	return 1;
}

        void printRecord(Node* node) 
        {
            printf("\n");
            printf("▣▣▣▣▣▣▣▣▣▣-%d-▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n", node->position);
            printf("▣ Artist: %s\n", node->data.artist);
            printf("▣ Album: %s\n", node->data.albumTitle);
            printf("▣ Song: %s\n", node->data.songTitle);
            printf("▣ Genre: %s\n", node->data.genre);
            printf("▣ Length: %d:%d\n", node->data.songLength.minutes, node->data.songLength.seconds);
            printf("▣ Times Played: %d\n", node->data.timesPlayed);
            printf("▣ Rating: %d\n", node->data.rating);
            printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
        }
void printList() {
	Node* next = pPlaylist->head;
    if(!next) {
        printf("No songs found! Try running load command first.\n");
        return;
    }
    
    printf("\n\n");
    while(next) {
        printRecord(next);
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

int printArtistSearch(char* artist) {
    Node* next = pPlaylist->head;
    if(!next) {
        printf("No songs found! Try running load command first.\n");
        return 0;
    }
    
    int matches = 0;
    
    printf("\n");
    while(next) {
        if(!strcmp(next->data.artist, artist)) {
            printRecord(next);
            
            next = next->next;
            matches++;
        } else {
            next = next->next;
        }
    }
    printf("\n");
    
    if(matches==0) {
        printf("No matches found!\n");
        return 0;
    }
    
    return 1;
}

void printSongSearch(int songNumber) {
    Node* head = pPlaylist->head;
    if(!head) {
        printf("No songs found! Try running load command first.\n");
        return;
    }
    
    int matches = 0;
    
    printf("\n\n");
    Node* next = head;
    while(next) {
        if(next->position == songNumber) {
            printRecord(next);
            
            next = next->next;
            matches++;
        } else {
            next = next->next;
        }
    }
    printf("\n");
    
    if(matches==0) {
        printf("No matches found!\n");
    }
    
    return;
}