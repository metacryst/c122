#include "../Playlist.h"

void shufflePlay(int* songsToPlay) {
    for(int i=0; i<listLength; i++) {
        printPlayingRecord(songSearch(songsToPlay[i]));
        *(songsToPlay+i) = 0;
        sleep(1);
    }
}

void shuffle() {    
    if(!(pPlaylist->head)) {
        printf("->No songs found! Try running load command first.\n");
        return;
    }
    
    int songsToPlay[100] = {0};
    
    int playedCount = 0;
    
    // seed the random number generator
    srand(time(NULL));
    
    int listBegin = 1;

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
    
    shufflePlay(songsToPlay);
}