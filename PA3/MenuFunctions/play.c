#include "../Playlist.h"

void play() {
    int printSuccess = printList();
    if(!printSuccess) {
        return;
    }
    
    printf("->Enter Starting Song Number \n");
    printf("☾ Command: ");
    
    char songString[3];
    fgets(songString, 3, stdin); 
    int songNumber;
    sscanf(songString, "%d", &songNumber);
    
    Node* songToPlay = songSearch(songNumber);
    
    while(songToPlay != pPlaylist->tail) {
        printPlayingRecord(songToPlay);
        songToPlay = songToPlay->next;
        sleep(3);
    }
    printPlayingRecord(songToPlay);
    sleep(3);
}