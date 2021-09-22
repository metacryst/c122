#include "../Playlist.h"

void shuffle() {    
    if(!(pPlaylist->head)) {
        printf("->No songs found! Try running load command first.\n");
        return;
    }
    
    // bounds for number generation
    int listBegin = 1;
    int listLength = countNodes(pPlaylist->head);
    printf("%d", listLength);
    
    char alreadyPlayed[11];
    int playCount = 0;
    
    while(playCount<listLength) {
        int songNumber;
        char songNumberString[4]; 
        
        // keep re-generating number until it's a new song
        while(strstr(alreadyPlayed, songNumberString)) {
            songNumber = (rand() % (listLength - listBegin + 1)) + listBegin;
            printf("songNumber: %d\n", songNumber);
            printf("strstr: %s\n", strstr(alreadyPlayed, songNumberString));
            snprintf(songNumberString, 3, "%d", songNumber);
        }
        
        Node* songToPlay = songSearch(songNumber);
        printf("\nNOW PLAYING: %d", songNumber);
        printRecord(songToPlay);
        
        playCount++;
        sleep(5);
    }
}