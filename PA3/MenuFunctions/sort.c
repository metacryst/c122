#include "../Playlist.h"

void sort() {
    printf("->Sort Methods: 1=Artist, 2=Album, 3=Rating, 4=Times Played\n");
    printf("☾ Command: ");
    
    char commandString[3];
    fgets(commandString, 3, stdin);
    int command;
    sscanf(commandString, "%d", &command);
    

    printf("\n\n");
    
    Node* node1 = pPlaylist->head;
    if(!node1) {
            printf("No songs found! Try running load command first.\n");
            return;
    }
    
    int endOfList = 0;
    while(!endOfList) {
        Node* node2 = node1->next;
        if(!node2) {
            endOfList = 1;
            break;
        }
        
        int comparison;
        
        switch(command) {
            case 1:
                comparison = strcmp(node2->data.artist, node1->data.artist);
                break;
            case 2:
                comparison = strcmp(node2->data.albumTitle, node1->data.albumTitle);
                break;
            case 3:
                if(node2->data.rating > node1->data.rating) {
                    comparison = -1;
                } else {
                    comparison = 1;
                }
                break;
            case 4:
                if(node2->data.timesPlayed > node1->data.timesPlayed) {
                    comparison = -1;
                } else {
                    comparison = 1;
                }
                break;
        }
        
        int swapHappened = 0;
        
        if(comparison < 0) { // if node 2 is before node 1 (descending)
            Record tempData = node1->data;
            node1->data = node2->data;
            node2->data = tempData;
            swapHappened = 1;
        }
        
        if(swapHappened) {
            node1=pPlaylist->head;
        } else {
            node1=node1->next;
        }
            
    }
    
    printf("Here is your new list, in descending order:\n");
    sleep(1);
    printList();
}