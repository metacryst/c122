#include "../Playlist.h"

void shuffle() {    
    if(!(pPlaylist->head)) {
        printf("->No songs found! Try running load command first.\n");
        return;
    }
    
    // bounds for number generation
    int listBegin = 1;
    int listLength = countNodes(pPlaylist->head);
    
    int alreadyPlayed[100] = {0};
    int playedCount = 0;
    
    // seed the random number generator
    srand(time(NULL));
    
    while(playedCount<listLength) {        
        int songNumber = 1;
        // keep re-generating number until it's a new song
        
        songNumber = (rand() % (listLength - listBegin + 1)) + listBegin;
        printf("songNumber: %d\n", songNumber);
        if(alreadyPlayed[songNumber]) {
            while(alreadyPlayed[songNumber]) {
                songNumber = (rand() % (listLength - listBegin + 1)) + listBegin;
                printf("songNumber: %d\n", songNumber);
            }
        }
        
        Node* songToPlay = songSearch(songNumber);
        printf("\nNOW PLAYING:");
        printRecord(songToPlay);
        
        alreadyPlayed[songNumber] = 1;
        playedCount++;
        printf("playedCount = %d\n", playedCount);
        printf("playedCount<listLength = %d\n", playedCount<listLength);
        
        sleep(1);
        
    }    
}