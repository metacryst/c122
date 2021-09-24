#include "Playlist.h"

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
void printPlayingRecord(Node* node) 
{
    printf("\nNOW PLAYING: ");
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

// indented functions are within local scope only
        void countNodes() {   
            int count = 0;
            
            Node* nodeToCount = pPlaylist->head;
             
            if(nodeToCount) {
                while(nodeToCount) {
                    count+=1;
                    nodeToCount = nodeToCount->next;
                }
            }
            
            listLength = count;
        }

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
    if(data->rating > 5 || data->rating<1) {
        return 0;
    }
    if(data->timesPlayed < 0) {
        return 0;
    }
    
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
    countNodes();
    
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
    // node is only node
    else {
        free(node);
        pPlaylist->head = NULL;
        success=1;
    }
        
    countNodes();
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
    
    countNodes();
}