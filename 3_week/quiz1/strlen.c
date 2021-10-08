#include <stdio.h>
#include <stdlib.h>

// This function accepts a pointer to a string and recursively counts the number of characters in the provided string, excluding the null character. This function should return the number of characters in the string.

int strlen_recursive (const char* stringAddress) {
    if(!stringAddress[0]) {
        return 0;
    }
        
    return 1 + strlen_recursive(stringAddress+1);
}

int main() {
    char string[100];
    
    printf("Give a string: ");
        // scanf: Max length of 99 characters; puts a null terminated string in string, thus 99 chars + null is the max
        scanf("%99s", string);
        printf("This is your string: %s", string);
        printf("\n");
        
    int length = strlen_recursive(string);
    printf("This is your length: %d\n", length);
    
    return 0;
}