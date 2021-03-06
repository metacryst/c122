#include "../Playlist.h"

void edit() {
    printf("☾ Enter Artist: ");
        char artist[150];
        fgets(artist, 150, stdin); 
        artist[strlen(artist)-1]='\0'; // replace newline
    printf("->Searching for %s...\n", artist);
    
    int artistSearchSuccess = printArtistSearch(artist);
    if(artistSearchSuccess) {
        printf("☾ Enter Name of Song to Edit: ");
            char songString[150];
            fgets(songString, 150, stdin); 
            songString[strlen(songString)-1]='\0'; // replace newline
        
        Node* searchedSong = songTitleSearch(songString);
        if(searchedSong) {
            printRecord(searchedSong);
            printf("\n->Edit Methods: 1=Artist, 2=Album, 3=Song, 4=Genre, 5=Length, 6=Times Played, 7=Rating \n");
            printf("☾ Command: ");
                char selectionString[3];
                fgets(selectionString, 3, stdin); 
                int editSelection;
                sscanf(selectionString, "%d", &editSelection);
            
            switch(editSelection) {
                case 1: // Artist
                    printf("☾ Edit to Make: ");
                    char artistEdit[150];
                    fgets(artistEdit, 150, stdin); 
                    artistEdit[strlen(artistEdit)-1]='\0';
                    
                    strcpy(searchedSong->data.artist, artistEdit);
                    break;
                case 2: // Album
                    printf("☾ Edit to Make: ");
                    char albumEdit[150];
                    fgets(albumEdit, 150, stdin); 
                    albumEdit[strlen(albumEdit)-1]='\0';
                    
                    strcpy(searchedSong->data.albumTitle, albumEdit);
                    break;
                case 3: // Song
                    printf("☾ Edit to Make: ");
                    char songTitleEdit[150];
                    fgets(songTitleEdit, 150, stdin); 
                    songTitleEdit[strlen(songTitleEdit)-1]='\0';
                    
                    strcpy(searchedSong->data.songTitle, songTitleEdit);
                    break;
                case 4: // Genre
                    printf("☾ Edit to Make: ");
                    char genreEdit[150];
                    fgets(genreEdit, 150, stdin); 
                    genreEdit[strlen(genreEdit)-1]='\0';
                    
                    strcpy(searchedSong->data.genre, genreEdit);
                    break;
                case 5: // Length
                    printf("☾ Edit to Make (Format: m:ss): ");
                    char lengthEdit[8];
                    fgets(lengthEdit, 8, stdin);
                    lengthEdit[strlen(lengthEdit)-1]='\0';
                    
                    char* scannedMinutes;
                        scannedMinutes = strtok(lengthEdit, ":");
                        if(scannedMinutes) {
                            printf("scannedMinutes: %s\n", scannedMinutes);
                            
                            int integerMinutes;
                            integerMinutes = atoi(scannedMinutes);
                            printf("integerMinutes: %d\n", integerMinutes);
                            
                            searchedSong->data.songLength.minutes = integerMinutes;
                            printf("setMinutes: %d\n", searchedSong->data.songLength.minutes);
                        }
                    char* scannedSeconds;
                        scannedSeconds = strtok(NULL, "\0");
                        if(scannedSeconds) {
                            printf("scannedSeconds: %s\n", scannedSeconds);
                            
                            int integerSeconds;
                            integerSeconds = atoi(scannedSeconds);
                            printf("integerSeconds: %d\n", integerSeconds);
                            
                            searchedSong->data.songLength.seconds = integerSeconds;
                            printf("setSeconds: %d\n", searchedSong->data.songLength.seconds);
                        }
                    break;
                default:
                    printf("->Command Not Recognized: %d\n", editSelection);
                    return;
            }
            
            printf("->Here is your new song!\n");
            printRecord(searchedSong);
            
            sleep(1);
                    
        }
    }
}