#include "Playlist.h"

int countNodes(Node* node) {
    int length = 0;
    
    if(node) {
        Node* nextNode = node;
        while(nextNode) {
            length+=1;
            nextNode = nextNode->next;
        }
    }
    
    return length;
}

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
        void decrementPositions(Node* node) {
            if(node) {
                node->position -= 1;
                decrementPositions(node->next);
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
    printf("▣ Length: %d:%02u\n", node->data.songLength.minutes, node->data.songLength.seconds);
    printf("▣ Times Played: %d\n", node->data.timesPlayed);
    printf("▣ Rating: %d\n", node->data.rating);
    printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
}

int printList() {
	Node* next = pPlaylist->head;
    if(!next) {
        printf("No songs found! Try running load command first.\n");
        return 0;
    }
    
    printf("\n\n");
    while(next) {
        printRecord(next);
        next = next->next;
    }
    printf("\n");
    
    return 1;
}

int deleteNode(Node* node) {
    int success=0;
    
    // beginning of list
    if(!(node->prev) && node->next) {        
        pPlaylist->head = node->next;
        pPlaylist->head->prev = NULL;
        
        decrementPositions(pPlaylist->head);
        free(node);
        success=1;
    }
    // middle of list
    else if(node->prev && node->next) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        decrementPositions(node->next);
        free(node);
        success=1;
    }
    // end of list
    else if(node->prev && !(node->next)) {
        node->prev->next = NULL;
        
        free(node);
        success=1;
    }
    
    return success;
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
        printf("->No songs found! Try running load command first.\n");
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

Node* songSearch(int songNumber) {
    Node* next = pPlaylist->head;
    if(!next) {
        printf("->No songs found! Try running load command first.\n");
        return NULL;
    }
    
    Node* foundSong = NULL;
        
    printf("\n\n");
    while(next) {
        if(next->position == songNumber) {
            foundSong = next;            
            next = next->next;
        } else {
            next = next->next;
        }
    }
    printf("\n");
    
    if(!foundSong) {
        printf("No matches found!\n");
    }
    
    return foundSong;
}

Node* songTitleSearch(char* songTitle) {
    Node* next = pPlaylist->head;
    if(!next) {
        printf("No songs found! Try running load command first.\n");
        return NULL;
    }
    
    Node* foundSong = NULL;
        
    printf("\n");
    while(next) {
        if(!strcmp(next->data.songTitle, songTitle)) {
            foundSong = next;
            next = next->next;
        } else {
            next = next->next;
        }
    }
    printf("\n");
    
    if(!foundSong) {
        printf("No matches found!\n");
    }
    
    return foundSong;
}