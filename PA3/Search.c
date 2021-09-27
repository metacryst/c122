#include "Playlist.h"

int printArtistSearch(char* artist) {
    Node* toPrint = pPlaylist->head;
    if(!toPrint) {
        printf("->No songs found! Try running load command first.\n");
        return 0;
    }
    
    int matches = 0;
    
    printf("\n");
    while(toPrint->next != pPlaylist->head) {
        if(!strcmp(toPrint->data.artist, artist)) {
            printRecord(toPrint);
            
            toPrint = toPrint->next;
            matches++;
        } else {
            toPrint = toPrint->next;
        }
    }
    if(!strcmp(toPrint->data.artist, artist)) {
        printRecord(toPrint);
        matches++;
    }
    printf("\n");
    
    if(matches==0) {
        printf("No matches found!\n");
        return 0;
    }
    
    return 1;
}

Node* songSearch(int songNumber) {
    Node* toSearch = pPlaylist->head;
    if(!toSearch) {
        printf("->No songs found! Try running load command first.\n");
        return NULL;
    }
    
    Node* foundSong = NULL;
        
    printf("\n\n");
    while(toSearch != pPlaylist->tail) {
        if(toSearch->position == songNumber) {
            foundSong = toSearch;            
            toSearch = toSearch->next;
        } else {
            toSearch = toSearch->next;
        }
    }
    if(toSearch->position == songNumber) {
        foundSong = toSearch;            
    }
    printf("\n");
    
    if(!foundSong) {
        printf("No matches found!\n");
    }
    
    return foundSong;
}

Node* songTitleSearch(char* songTitle) {
    Node* toSearch = pPlaylist->head;
    if(!toSearch) {
        printf("No songs found! Try running load command first.\n");
        return NULL;
    }
    
    Node* foundSong = NULL;
        
    printf("\n");
    while(toSearch != pPlaylist->tail) {
        if(!strcmp(toSearch->data.songTitle, songTitle)) {
            foundSong = toSearch;
            toSearch = toSearch->next;
        } else {
            toSearch = toSearch->next;
        }
    }
    if(!strcmp(toSearch->data.songTitle, songTitle)) {
        foundSong = toSearch;
    }
    printf("\n");
    
    if(!foundSong) {
        printf("No matches found!\n");
    }
    
    return foundSong;
}