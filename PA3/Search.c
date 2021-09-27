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

    int calculateSearchDirection(song, lastFound) {
        int direction;
        // if song is in front of us
        if(song > lastFound) {
            if(abs(song - lastFound) > listLength/2) { 
                direction = -1; // loop around thru head
            } else {
                direction = 1; // traverse normally
            }
        }
        // if song is behind us
        if(song < lastFound) {
            if(abs(song - lastFound) > listLength/2) { 
                direction = 1; // loop around thru tail
            } else {
                direction = -1; // traverse normally
            }
        }
        return direction;
    }
Node* songSearch(int songNumber) {
    static Node* lastFoundSong;
    Node* startingNode;

    if(!pPlaylist->head) {
        printf("->No songs found! Try running load command first.\n");
        return NULL;
    }

    int direction = 1;
    if(lastFoundSong) {
        direction = calculateSearchDirection(songNumber, lastFoundSong->position);
        startingNode = lastFoundSong;
    } else {
        direction = calculateSearchDirection(songNumber, 1);
        startingNode = pPlaylist->head;
    }
            
    printf("\n\n");

    Node* toSearch = startingNode;
    Node* foundSong;
    int iterations = 0;
    while(toSearch != startingNode || iterations==0) {
        if(direction > 0) { // Forwards
            if(toSearch->position == songNumber) {
                foundSong = toSearch;
                break;
            } else {
                toSearch = toSearch->next;
            }
        }
        if(direction < 0) { // Backwards
            if(toSearch->position == songNumber) {
                foundSong = toSearch;
                break;
            } else {
                toSearch = toSearch->prev;
            }
        }
        iterations++;
    }
    printf("\n");
    
    if(!foundSong) {
        printf("No matches found!\n");
    } else {
        lastFoundSong = foundSong;
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