#include "../Playlist.h"

int store() {
    if(!(pPlaylist->head)) {
        printf("No songs in library! Try running load command first.\n");
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
    
    Node* next = pPlaylist->head;
    while(next) {
        fputs(next->data.artist, outfile);
            fputs(",", outfile);
        fputs(next->data.albumTitle, outfile);
            fputs(",", outfile);
        fputs(next->data.songTitle, outfile);
            fputs(",", outfile);
        fputs(next->data.genre, outfile);
            fputs(",", outfile);
            
        char songMinutesString[10];
            snprintf(songMinutesString, 10, "%d", next->data.songLength.minutes);
            fputs(songMinutesString, outfile);
            fputs(":", outfile);
        char songSecondsString[10];
            snprintf(songSecondsString, 10, "%d", next->data.songLength.seconds);
            fputs(songSecondsString, outfile);
                fputs(",", outfile);
        
        char timesPlayedString[10];
            snprintf(timesPlayedString, 10, "%d", next->data.timesPlayed);
            fputs(timesPlayedString, outfile);
                fputs(",", outfile);
            
        char ratingString[10];
            snprintf(ratingString, 10, "%d", next->data.rating);
            fputs(ratingString, outfile);
        
        fputs("\n", outfile);
        
        next = next->next;
    }
       
    fclose(outfile);
    
    return 1;
}