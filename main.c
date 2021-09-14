#include "Playlist.h"

void mainMenu() {
        
    int command = 0;
        printf("Hello! Welcome to your music library.\n");
        printf("Here are some number commands to get you started: \n");
        printf("\n");
        printf("1 - Load\n");
        printf("11 - Exit\n");
    
    List Playlist = {NULL};
    pPlaylist = &Playlist;
    
    while(command != 11) {
        printf("\n");
        
        printf("Command: ");
        scanf("%d", &command);
        
        switch(command) {
            case 1:
                printf("1: Load\n");
                load();
                printf("head: %s\n", pPlaylist->head->data.albumTitle);
                printf("second: %s\n", pPlaylist->head->next->data.albumTitle);
                printf("third: %s\n", pPlaylist->head->next->next->data.albumTitle);
                printf("fourth: %s\n", pPlaylist->head->next->next->next->data.albumTitle);
                break;
            case 11: 
                printf("11: Exit\n");
                break;
            default: 
                printf("Command not recognized: %d\n", command);
                break;
        }
    }
}

int main() {
    mainMenu();
    
    return 0;
}