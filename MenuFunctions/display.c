#include "../Playlist.h"

void display(int response) {
    switch(response) {
        case 2:
            printf("☾ Enter Artist: ");
            char artist[40];
            scanf("%s", artist);
            
            printf("->Searching for %s...\n", artist);
            printArtistSearch(artist);
            break;
        case 3:
            printf("->Displaying...\n");
            printList();
            break;
        default:
            printf("->Command not recognized: %d\n", response);
    }
}