#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//This function copies no more than n characters from the string pointed to by source to the buffer pointed to by destination. If the length of the C string in source is less than n, then the destination is padded with null characters until n characters have been copied to it. The function returns destination. NOTE: you must use array notation in your definition. 

char* my_strncpy (char* destination, const char* source, int n) {
    
    // renaming parameters
    const char* sourceFirstCharacterAddress = source;
    int copyLength = n;
        
    for(int iterations=1; iterations<=copyLength; iterations++) {
        int i = iterations-1;
        printf("%c\n", sourceFirstCharacterAddress[i]);
                
        destination[i] = sourceFirstCharacterAddress[i];
        printf("%c\n", destination[i]);
        
        if(!sourceFirstCharacterAddress[i]) {
            // need single quotes for character literal; double quotes denotes a string literal (which would add a null terminator)
            // the type of this '\0' character literal is integer in C and char in C++
            destination[i] = '\0';
            printf("%s\n", "Null!");
        }
    }
    
    return destination;
}

int main() {
    char sourceString[100];
    
    printf("Give a sourceString: ");
        // scanf: Max length of 99 characters; puts a null terminated string in string, thus 99 chars + null is the max
        scanf("%99s", sourceString);
        printf("This is your string: %s\n", sourceString);
        
    // two equivalent ways to allocate memory - declare an array, or use malloc
    // apparently, simply declaring {char* destinationAddress;} will cause problems later on when assigning values. (Bus error: 10)
    
    // char* destinationAddress = malloc(strlen(sourceString) + 1);
    char destinationArray[6];
        
    // "destinationArray" and "sourceString" will become a pointer automatically when passed as a parameter
    char* final = my_strncpy(destinationArray, sourceString, 6);
    
    printf("%c\n", final[0]);
    printf("%c\n", final[1]);
    printf("%c\n", final[2]);
    printf("%c\n", final[3]);
    printf("%c\n", final[4]);
    printf("%c\n", final[5]);
    
    return 0;
}