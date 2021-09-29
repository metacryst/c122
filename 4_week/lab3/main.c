#include "Stack.h"

int mainMenu() {
    int command = 0;
        printf("Hello! Welcome to your stack.\n");
        printf("Here are some number commands to get you started: \n");
        printf("\n");
        printf("1: Push\n");
        printf("2: Top\n");
        printf("3: Pop\n");
        
    
    Stack newStack = {NULL};
    pStack = &newStack;
    
    while(command != 11) {
        printf("\n");
        
        printf("Command: ");
        scanf("%d", &command);
        
        switch(command) {
            case 1:
                printf("1: Push: Enter a value: ");
                double input;
                scanf("%lf", &input);
                push(input);
                break;
            case 2:
                printf("2. Top\n");
                printf("Top of stack value: %f\n", top());
                break;
            case 3:
                printf("3. Pop\n");
                pop();
                break;
            default: 
                printf("Command not recognized: %d\n", command);
                break;
        }
    }
    
    return 1;
}


int main() {
    mainMenu();
    
    return 0;
}
// int main() {

//     Stack newStack = {NULL};
//     pStack = &newStack;
        
//     if(isEmpty()) {
//         printf("Empty!\n");
//     } else {
//         printf("Not Empty!\n");
//     };
//     printf("\n");
    
    
//     printf("Adding double: \n");
//     double sampleDouble = 4;
//     push(sampleDouble);
    
//     printf("top of stack: %f\n", pStack->top->data);
//     if(isEmpty()) {
//         printf("Empty!\n");
//     } else {
//         printf("Not Empty!\n");
//     };
//     printf("\n");
    
    
//     printf("Adding second double: \n");
//     double secondDouble = 8;
//     push(secondDouble);
    
//     printf("top of stack: %f\n", pStack->top->data);
//     if(isEmpty()) {
//         printf("Empty!\n");
//     } else {
//         printf("Not Empty!\n");
//     };
//     printf("\n");
    
//     printf("Popping: \n");
//     pop();
    
//     printf("new top of stack: %f\n", pStack->top->data);
//     if(isEmpty()) {
//         printf("Empty!\n");
//     } else {
//         printf("Not Empty!\n");
//     };
//     printf("\n");
    
//     printf("top of stack using top function: %f\n", top());
//     if(isEmpty()) {
//         printf("Empty!\n");
//     } else {
//         printf("Not Empty!\n");
//     };
//     printf("\n");
//     return 0;
// }