#include "../Playlist.h"

void shuffle() {    
    if(!(pPlaylist->head)) {
        printf("->No songs found! Try running load command first.\n");
        return;
    }
    
    // bounds for number generation
    int listBegin = 1;
    int listLength = countNodes(pPlaylist->head);
    
    int songsToPlay[100] = {0};
    int playedCount = 0;
    
    // seed the random number generator
    srand(time(NULL));

    // create list of songs to play
    int alreadyGenerated[100] = {0};
    for(int i=0; i<listLength; i++) {
        int songNumber = (rand() % (listLength - listBegin + 1)) + listBegin;
        
        while(alreadyGenerated[songNumber]) {
            songNumber = (rand() % (listLength - listBegin + 1)) + listBegin;
        }
        
        songsToPlay[i] = songNumber;
        alreadyGenerated[songNumber] = 1;
    }
    
    for(int i=0; i<listLength; i++) {
        printPlayingRecord(songSearch(songsToPlay[i]));
        sleep(3);
    }
    
    fflush(stdin);
}