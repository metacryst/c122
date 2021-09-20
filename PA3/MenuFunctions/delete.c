#include "../Playlist.h"

void delete() {
    printf("☾ Enter Song Title: ");
        char songTitle[150];
        fgets(songTitle, 150, stdin); 
        songTitle[strlen(songTitle)-1]='\0';
        
    Node* searchedSong = songTitleSearch(songTitle);
    if(searchedSong) {
        printRecord(searchedSong);
        
        printf("\n☾ Delete? (y/n): ");
            char response[3];
            fgets(response, 3, stdin); 
            response[strlen(response)-1]='\0';
        
        if(!strcmp(response, "y")) {
            int deleteNodeSuccess = deleteNode(searchedSong);
            if(deleteNodeSuccess) {
                printf("->Deleted.\n");
            }
        }
    }
}