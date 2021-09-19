#include "../Playlist.h"

void play() {
    int printSuccess = printList();
    if(!printSuccess) {
        return;
    }
    
    printf("->Enter Song Number \n");
    printf("☾ Command: ");
    
    char songString[3];
    fgets(songString, 3, stdin); 
    int songNumber;
    sscanf(songString, "%d", &songNumber);
    
    Node* songToPlay = songSearch(songNumber);
    
    while(songToPlay) {
        printf("\nNOW PLAYING: ");
        printRecord(songToPlay);
        songToPlay = songToPlay->next;
        sleep(5);
    }
}