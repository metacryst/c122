#include "../Playlist.h"

void display() {
    printf("->Search for an artist? 2=Search, 3=Show All\n");
    printf("☾ Command: ");

    char responseString[3];
    int response = 0;
    fgets(responseString, 3, stdin);
    sscanf(responseString, "%d", &response);
    
    switch(response) {
        case 2:
            printf("☾ Enter Artist: ");
            char artist[40];
            fgets(artist, 40, stdin);
            // replace newline character
            artist[strlen(artist)-1]='\0'; 
            
            printf("->Searching for %s...\n", artist);
            printArtistSearch(artist);
            break;
        case 3:
            printf("->Displaying...\n");
            printList();
            break;
        default:
            printf("->Command not recognized: %d\n", response);
            break;
    }
    
    return;
}