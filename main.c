#include "Playlist.h"

void mainMenu() {
        
    int command = 0;
        printf("           ______________ \n");
        printf("          /             /| \n");
        printf("         /             / | \n");
        printf("        /____________ /  | \n");
        printf("       | ___________ |   | \n");
        printf("       ||           ||   | \n");
        printf("       || PLAYLIST  ||   | \n");
        printf("       ||           ||   | \n");
        printf("       ||___________||   | \n");
        printf("       |   _______   |  /  \n");
        printf("      /|  (_______)  | /   \n");
        printf("     ( |_____________|/    \n");
        printf("     \\                    \n");
        printf(" .=======================. \n");
        printf(" | ::::::::::::::::  ::: | \n");
        printf(" | ::::::::::::::[]  ::: | \n");
        printf(" |   -----------     ::: | \n");
        printf(" `-----------------------' \n");
        
        printf("\n\nHello! Welcome to your music library.\n");
        printf("Here are some number commands to get you started: \n");
        printf("\n");
        printf("1 - Load\n");
        printf("2 - Store\n");
        printf("3 - Display\n");
        printf("11 - Exit\n");
    
    List Playlist = {NULL};
    pPlaylist = &Playlist;
    
    while(command != 11) {
        printf("\n\n");
        printf("☾☾ 1=Load, 2=Store, 3=Display, 11=Exit \n");
        printf("☾☾ Command: ");
        scanf("%d", &command);
        
        int success;
        
        switch(command) {
            case 1:
                printf("-->Loading...\n");
                success = load();
                if(success) {
                    printf("-->Loaded.\n");
                }
                break;
            case 2:
                printf("-->Storing Playlist...\n");
                success = store();
                if(success) {
                   printf("-->Stored.\n"); 
                }
                break;
            case 3:
                printf("-->Search for an artist? 1=Search, 2=Show All\n");
                printf("☾ Command: ");
                
                int response = 0;
                scanf("%d", &response);
                switch(response) {
                    case 1:
                        printf("☾ Enter Artist: ");
                        char artist[40];
                        scanf("%s", artist);
                        printf("-->Searching for %s...\n", artist);
                        printArtistSearch(artist);
                        break;
                    case 2:
                        printf("-->Displaying...\n");
                        display();
                        break;
                    default:
                        printf("-->Command not recognized: %d\n", response);
                }
                break;
            case 11: 
                printf("-->Exit.\n");
                printf("-->Storing Playlist...\n");
                success = store();
                if(success) {
                   printf("-->Stored.\n"); 
                }
                printf("\n");
                break;
            default: 
                printf("-->Command not recognized: %d\n", command);
                break;
        }
    }
}

int main() {
    mainMenu();
    
    return 0;
}