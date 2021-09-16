#include "Playlist.h"

void mainMenu() {
        
    int command = 0;
        printf("Hello! Welcome to your music library.\n");
        printf("Here are some number commands to get you started: \n");
        printf("\n");
        printf("1 - Load\n");
        printf("2 - Store\n");
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
                printf("head: %d\n", pPlaylist->head->data.songLength.seconds);
                printf("second: %d\n", pPlaylist->head->next->data.songLength.seconds);
                printf("third: %d\n", pPlaylist->head->next->next->data.songLength.seconds);
                printf("fourth: %d\n", pPlaylist->head->next->next->next->data.songLength.seconds);
                break;
            case 2:
                printf("2: Store\n");
                store();
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