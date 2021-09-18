#include "../Playlist.h"

void edit() {
    printf("☾ Enter Artist: ");
    char artist[150];
    scanf("%s", artist);
    printf("->Searching for %s...\n", artist);
    int artistSearchSuccess = 0;
    artistSearchSuccess = printArtistSearch(artist);
    
    if(artistSearchSuccess) {
        int songNumber;
        printf("☾ Enter Number of Song to Edit: ");
        scanf("%d", &songNumber);
        printSongSearch(songNumber);
    }
}