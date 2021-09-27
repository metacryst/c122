#include "../Playlist.h"

int storeSong(Node* node, FILE* outfile) {
    fputs(node->data.artist, outfile);
        fputs(",", outfile);
    fputs(node->data.albumTitle, outfile);
        fputs(",", outfile);
    fputs(node->data.songTitle, outfile);
        fputs(",", outfile);
    fputs(node->data.genre, outfile);
        fputs(",", outfile);
        
    char songMinutesString[10];
        snprintf(songMinutesString, 10, "%d", node->data.songLength.minutes);
        fputs(songMinutesString, outfile);
        fputs(":", outfile);
    char songSecondsString[10];
        snprintf(songSecondsString, 10, "%d", node->data.songLength.seconds);
        fputs(songSecondsString, outfile);
            fputs(",", outfile);
    
    char timesPlayedString[10];
        snprintf(timesPlayedString, 10, "%d", node->data.timesPlayed);
        fputs(timesPlayedString, outfile);
            fputs(",", outfile);
        
    char ratingString[10];
        snprintf(ratingString, 10, "%d", node->data.rating);
        fputs(ratingString, outfile);
    
    if(node->next != pPlaylist->head) {
        fputs("\n", outfile);
    }

    return 1;
}

int store() {
    if(!(pPlaylist->head)) {
        printf("No songs to store! Try running load command first.\n");
        return 0;
    }
    
    FILE* outfile = fopen("musicPlayList.csv", "w");
    if(outfile == NULL) {
        printf("outfile not found!\n");
        return 0;
    }    
    fputs("", outfile);
    fclose(outfile);
    
    outfile = fopen("musicPlayList.csv", "w");
    if(outfile == NULL) {
        printf("outfile not found!\n");
        return 0;
    }    
    
    Node* current = pPlaylist->head;
    while(current->next != pPlaylist->head) {
        storeSong(current, outfile);
        current = current->next;
    }
    // store final song
    storeSong(current, outfile);
       
    fclose(outfile);
    
    return 1;
}