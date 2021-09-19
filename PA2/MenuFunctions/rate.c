#include "../Playlist.h"

void rate() {
    printf("☾ Enter Number of Song to Rate: ");
    char selectionString[3];
    fgets(selectionString, 3, stdin);
    int rateSelection;
    sscanf(selectionString, "%d", &rateSelection);
    
    Node* searchedSong = songSearch(rateSelection);
    if(searchedSong) {
        printf("☾ Enter Rating: ");
        char rateString[3];
        fgets(rateString, 3, stdin); 
        int rating;
        sscanf(rateString, "%d", &rating);
        
        searchedSong->data.rating = rating;
        printf("-> Here is your new song!\n");
        printRecord(searchedSong);
    }
}