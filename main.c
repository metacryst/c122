#include <stdio.h>

void mainMenu() {
    int command = 0;
    printf("Hello! Welcome to your music library.\n");
    printf("Here are some number commands to get you started: \n");
    printf("\n");
    printf("11 - Exit\n");
    
    while(command != 11) {
        printf("\n");
        
        printf("Command: ");
        scanf("%d", &command);
        printf("%d\n", command);
    }
}

int main() {
    mainMenu();
    
    return 0;
}