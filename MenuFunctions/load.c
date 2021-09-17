#include "../Playlist.h"

int load() {    
    FILE* infile = fopen("musicPlayList.csv", "r");
    if(infile == NULL) {
        printf("inFile not found!\n");
        return 0;
    }
    
    
    Node* nodeToDelete = pPlaylist->head;
    if(nodeToDelete) {
        printf("nodeToDelete Data: %s\n", nodeToDelete->data.albumTitle);
    }
    while(nodeToDelete) {
        Node* nextNodeToDelete = NULL;
        if(nodeToDelete->next) {
            nextNodeToDelete = nodeToDelete->next;
            printf("nextNode: %s\n", nextNodeToDelete->data.albumTitle);
            nextNodeToDelete->prev = NULL;
            pPlaylist->head = nextNodeToDelete;
            printf("newHead: %s\n", pPlaylist->head->data.albumTitle);
            free(nodeToDelete);
            nodeToDelete = nextNodeToDelete;
        } else {
            printf("end of list: playlist head artist: %s\n", pPlaylist->head->data.artist);
            free(nodeToDelete);
            pPlaylist->head = NULL;
            nodeToDelete = NULL;
        }
        
    }
    
    
    char line[250] = "";
    while(fgets(line, 250, infile)) {
        Duration newSongLength = {0, 0};
        Record newRecord = {"", "", "", "", newSongLength, 0, 0};
        
        char* scannedArtist;
            if(line[0] == '"') {
                scannedArtist = strtok(line, "\"");
                if(scannedArtist) {
                    strcat(newRecord.artist, "\"");
                    strcat (newRecord.artist , scannedArtist);
                    strcat(newRecord.artist, "\"");
                }
            } else {
                scannedArtist = strtok(line, ",");
                if(scannedArtist) {
                    strcpy (newRecord.artist , scannedArtist);
                }
            }
            
            // printf("artist: %s\n", newRecord.artist);
        
        char* scannedAlbum;
            scannedAlbum = strtok(NULL, ",");
            if(scannedAlbum) {
                strcpy (newRecord.albumTitle , scannedAlbum);
            }
        
            // printf("album: %s\n", newRecord.albumTitle);
        
        char* scannedSong;
            scannedSong = strtok(NULL, ",");
            if(scannedSong) {
                strcpy (newRecord.songTitle , scannedSong);
            }
        
            // printf("song: %s\n", newRecord.songTitle);
            
        char* scannedGenre;
            scannedGenre = strtok(NULL, ",");
            if(scannedGenre) {
                strcpy (newRecord.genre , scannedGenre);
            }
        
            // printf("genre: %s\n", newRecord.genre);
            
        char* scannedMinutes;
            scannedMinutes = strtok(NULL, ":");
            if(scannedMinutes) {
                newSongLength.minutes = atoi(scannedMinutes);
            }
        char* scannedSeconds;
            scannedSeconds = strtok(NULL, ",");
            if(scannedSeconds) {
                newSongLength.seconds = atoi(scannedSeconds);
            }
        
            // printf("newSongLength: %d:%d\n", newSongLength.minutes, newSongLength.seconds);
            
        char* scannedPlays;
            scannedPlays = strtok(NULL, ",");
            if(scannedPlays) {
                newRecord.timesPlayed = (unsigned int) atoi(scannedPlays);
            }
        
            // printf("timesPlayed: %d\n", newRecord.timesPlayed);
            
        char* scannedRating;
            scannedRating = strtok(NULL, ",");
            if(scannedRating) {
                newRecord.rating = (unsigned int) atoi(scannedRating);
            }
        
            // printf("rating: %d\n", newRecord.rating);
            
        newRecord.songLength = newSongLength;
        insertFront(&newRecord);
        
        // printf("\n");
    }
    
    fclose(infile);
        
    return 1;
}