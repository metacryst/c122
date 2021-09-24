#include "Playlist.h"

int printArtistSearch(char* artist) {
    Node* next = pPlaylist->head;
    if(!next) {
        printf("->No songs found! Try running load command first.\n");
        return 0;
    }
    
    int matches = 0;
    
    printf("\n");
    while(next) {
        if(!strcmp(next->data.artist, artist)) {
            printRecord(next);
            
            next = next->next;
            matches++;
        } else {
            next = next->next;
        }
    }
    printf("\n");
    
    if(matches==0) {
        printf("No matches found!\n");
        return 0;
    }
    
    return 1;
}

Node* songSearch(int songNumber) {
    Node* next = pPlaylist->head;
    if(!next) {
        printf("->No songs found! Try running load command first.\n");
        return NULL;
    }
    
    Node* foundSong = NULL;
        
    printf("\n\n");
    while(next) {
        if(next->position == songNumber) {
            foundSong = next;            
            next = next->next;
        } else {
            next = next->next;
        }
    }
    printf("\n");
    
    if(!foundSong) {
        printf("No matches found!\n");
    }
    
    return foundSong;
}

Node* songTitleSearch(char* songTitle) {
    Node* next = pPlaylist->head;
    if(!next) {
        printf("No songs found! Try running load command first.\n");
        return NULL;
    }
    
    Node* foundSong = NULL;
        
    printf("\n");
    while(next) {
        if(!strcmp(next->data.songTitle, songTitle)) {
            foundSong = next;
            next = next->next;
        } else {
            next = next->next;
        }
    }
    printf("\n");
    
    if(!foundSong) {
        printf("No matches found!\n");
    }
    
    return foundSong;
}