#include "../Playlist.h"

void display() {
    
    Node* next = pPlaylist->head;
    if(!next) {
        printf("No songs found! Try running load command first.\n");
        return;
    }
    
    printf("\n\n");
    while(next) {
        printf("\n");
        printf("Artist: %s\n", next->data.artist);
        printf("Album: %s\n", next->data.albumTitle);
        printf("Song: %s\n", next->data.songTitle);
        printf("Genre: %s\n", next->data.genre);
        printf("Length: %d:%d\n", next->data.songLength.minutes, next->data.songLength.seconds);
        printf("Times Played: %d\n", next->data.timesPlayed);
        printf("Rating: %d\n", next->data.rating);
        
        next = next->next;
    }
    printf("\n");
}