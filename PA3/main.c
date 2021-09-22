#include "Playlist.h"

void mainMenu() {
        
    int command = 0;
    char commandString[3];
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
        printf("4 - Insert\n");
        printf("5 - Delete\n");
        printf("6 - Edit\n");
        printf("7 - Sort\n");
        printf("8 - Rate\n");
        printf("9 - Play\n");
        printf("10 - Shuffle Play\n");
        printf("11 - Exit\n");
    
    List Playlist = {NULL};
    pPlaylist = &Playlist;
    
    while(command != 11) {
        printf("\n\n");
        printf("☾☾ 1=Load, 2=Store, 3=Display, 4=Insert, 5=Delete, 6=Edit,\n");
        printf("☾☾ 7=Sort, 8=Rate, 9=Play, 10=Shuffle Play, 11=Exit \n");
        printf("☾☾ Command: ");
        fgets(commandString, 3, stdin);
        sscanf(commandString, "%d", &command); // convert command to integer
        
        int operationSuccess;
        
        switch(command) {
            case 1:
                printf("->Loading...\n");
                operationSuccess = load();
                if(operationSuccess) {
                    printf("->Loaded.\n");
                }
                break;
            case 2:
                printf("->Storing Playlist...\n");
                operationSuccess = store();
                if(operationSuccess) {
                   printf("->Stored.\n"); 
                }
                break;
            case 3:
                printf("->Display List\n");
                display();
                break;
            case 4:
                printf("->Insert New Song\n");
                insert();
                break;
            case 5:
                printf("->Delete Song\n");
                delete();
                break;
            case 6:
                printf("->Edit List\n");
                edit();
                break;
            case 7:
                printf("->Sort List\n");
                sort();
                break;
            case 8:
                printf("->Rate Song\n");
                printList();
                rate();
                break;
            case 9:
                printf("->Play Song\n");
                play();
                break;
            case 10:
                printf("->Shuffle Play\n");
                shuffle();
                break;
            case 11: 
                printf("->Exit.\n");
                printf("->Storing Playlist...\n");
                operationSuccess = store();
                if(operationSuccess) {
                   printf("->Stored.\n"); 
                }
                printf("\n");
                break;
            default:
                printf("\n->Command not recognized: %d\n", command);
                break;
        }
    }
}

int main() {
    mainMenu();
    
    return 0;
}