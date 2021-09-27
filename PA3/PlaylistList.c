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
             
            while(nodeToCount != pPlaylist->tail) {
                count+=1;
                nodeToCount = nodeToCount->next;
            }
            
            count+=1;
            
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
        void resetPositions() {
            Node* node = pPlaylist->head;
            int nodeNumber = 1;
            
            while(node->next != pPlaylist->head) {
                node->position=nodeNumber;
                
                nodeNumber++;
                node = node->next;
            }
            
            node->position=nodeNumber;
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
        
	if(pPlaylist->head) {
        pPlaylist->head->prev = newNode;
        pPlaylist->tail->next = newNode;
        newNode->next = pPlaylist->head;
        newNode->prev = pPlaylist->tail;
        pPlaylist->head = newNode;
	} else {
        newNode->next = newNode;
        newNode->prev = newNode;
        pPlaylist->head = newNode;
        pPlaylist->tail = newNode;
    }
    
    countNodes();
    resetPositions();
    
	return 1;
}

int deleteNode(Node* node) {
    int success=0;
    
    // node is only node
    if ((node->prev == node) && (node->next == node)) {
        free(node);
        pPlaylist->head = NULL;
        success=1;
    }
    // beginning of list
    else if(node == pPlaylist->head) {    
        node->next->prev = pPlaylist->tail;
        pPlaylist->tail->next = node->next;
        
        pPlaylist->head = node->next;
        
        free(node);
        resetPositions();
        success=1;
    }
    // end of list
    else if(node == pPlaylist->tail) {
        node->prev->next = pPlaylist->head;
        pPlaylist->head->prev = node->prev;
        
        pPlaylist->tail = node->prev;
        
        free(node);
        success=1;
    } 
    // middle of list
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        resetPositions();
        free(node);
        success=1;
    }
    
        
    countNodes();
    return success;
}

void clearList() {
	Node* toDelete = pPlaylist->head;

    // delete from front
    while(toDelete) {
        if(toDelete->next != toDelete) {
            // next pointing back at tail
            toDelete->next->prev = pPlaylist->tail;
            // tail pointing forward at next
            pPlaylist->tail->next = toDelete->next;
            // head is now next
            pPlaylist->head = toDelete->next;
            
            Node* nextToDelete = toDelete->next;
            free(toDelete);
            toDelete = nextToDelete;
        } else {
            pPlaylist->head = NULL;
            pPlaylist->tail = NULL;
            
            free(toDelete);
            toDelete = NULL;
        }
    }
    
    countNodes();
}