#include "../Playlist.h"

void insert() {
    Duration newSongLength = {0, 0};
    Record newRecord = {"", "", "", "", newSongLength, 0, 0};
    
    printf("☾ Enter Artist: ");
        char artist[150];
        fgets(artist, 150, stdin);
        // replace newline character
        artist[strlen(artist)-1]='\0'; 
        strcpy(newRecord.artist, artist);
        
    printf("☾ Enter Album: ");
        char albumTitle[150];
        fgets(albumTitle, 150, stdin);
        albumTitle[strlen(albumTitle)-1]='\0'; 
        strcpy(newRecord.albumTitle, albumTitle);
        
    printf("☾ Enter Song: ");
        char songTitle[150];
        fgets(songTitle, 150, stdin);
        songTitle[strlen(songTitle)-1]='\0'; 
        strcpy(newRecord.songTitle, songTitle);
        
    printf("☾ Enter Genre: ");
        char genre[20];
        fgets(genre, 20, stdin);
        genre[strlen(genre)-1]='\0'; 
        strcpy(newRecord.genre, genre);
        
    printf("☾ Enter Length (Format: m:ss): ");
        char length[8];
        fgets(length, 8, stdin);
        length[strlen(length)-1]='\0';
        
        char* scannedMinutes;
            scannedMinutes = strtok(length, ":");
            if(scannedMinutes) {
                int integerMinutes;
                integerMinutes = atoi(scannedMinutes);
                newSongLength.minutes = integerMinutes;
            }
        char* scannedSeconds;
            scannedSeconds = strtok(NULL, "\0");
            if(scannedSeconds) {                
                int integerSeconds;
                integerSeconds = atoi(scannedSeconds);
                newSongLength.seconds = integerSeconds;
            }
                        
    printf("☾ Enter Rating: ");
        char rateString[3];
        fgets(rateString, 3, stdin); 
        int rating;
        sscanf(rateString, "%d", &rating);
        newRecord.rating = rating;
        
    newRecord.timesPlayed = 0;
    newRecord.songLength = newSongLength;
    
    insertFront(&newRecord);
    
    printf("-> Here is your new song!\n");
    printRecord(pPlaylist->head);
    
    sleep(1);
    
}