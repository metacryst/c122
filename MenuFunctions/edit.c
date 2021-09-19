#include "../Playlist.h"

void edit() {
    printf("☾ Enter Artist: ");
    char artist[150];
    scanf("%s", artist);
    printf("->Searching for %s...\n", artist);
    int artistSearchSuccess = printArtistSearch(artist);
    
    if(artistSearchSuccess) {
        int songNumber;
        printf("☾ Enter Number of Song to Edit: ");
        scanf("%d", &songNumber);
        int songSearchSuccess = printSongSearch(songNumber);
        
        if(songSearchSuccess) {
            int editSelection;
            printf("☾ 1=Artist, 2=Album, 3=Song, 4=Genre, 5=Length, 6=Times Played, 7=Rating \n");
            printf("☾ Field to Edit: ");
            scanf("%d", &editSelection);
            
            switch(editSelection) {
                case 1:
                    printf("☾ Edit to Make: ");
                    char artistEdit[150];
                    scanf("%s", artistEdit);
                    break;
            }
        }
    }
}