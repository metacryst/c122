#include <stdio.h>
#include <stdlib.h>

// This function appends no more than n characters from the string pointed to by source to the end of the string pointed to by destination. The null character is appended to the end of the result. If the length of the C string in source is less than n, then only the content up to the terminating null character is copied. The destination pointer is returned. 

//NOTE: you must use pointer arithmetic and notation in your definition.

char *my_strncat (char *destination, const char *source, int n) {
     
    // renaming parameters
    const char* sourceFirstCharacterAddress = source;
    int appendLength = n;
        
    int destinationNullCharacter = 0;
    int nullReached = 0;
    
    while(!nullReached) {
        if(*(destination+destinationNullCharacter)) {
            destinationNullCharacter++;
        } else {
            nullReached = 1;
        }
    }
    
    printf("%d\n", destinationNullCharacter);
    printf("\n");
    
    for(int iterations=1; iterations<=appendLength; iterations++) {
        int i = iterations-1;
        
        // check for nullcharacter
        if(*(source+i)) {
            printf("%c\n", *(source+i));
            printf("%d\n", destinationNullCharacter);
            *(destination+destinationNullCharacter) = *(source+i);
            printf("%c\n", *(destination+destinationNullCharacter));
            
            destinationNullCharacter++;
        } else {
            break;
        }
    }
    
    *(destination+destinationNullCharacter) = '\0';
            
    return destination;
}

int main() {
    char sourceString[100];
    char destinationString[100];
    
    printf("\n");
    
    
    
    printf("Give a destString: ");
        // scanf: Max length of 99 characters; puts a null terminated string in string, thus 99 chars + null is the max
        scanf("%99s", destinationString);
        printf("This is your destination string: %s\n", destinationString);
        printf("\n");
        
    printf("Give a sourceString: ");
        // scanf: Max length of 99 characters; puts a null terminated string in string, thus 99 chars + null is the max
        scanf("%99s", sourceString);
        printf("This is your string: %s\n", sourceString);
        printf("\n");
        
     
        
    // "destinationArray" and "sourceString" will become a pointer automatically when passed as a parameter
    char* product = my_strncat(destinationString, sourceString, 6);
    
    printf("~~~\n");
    int productHighestIndex = 0;
    int nullReached = 0;
    
    while(!nullReached) {
        if(product[productHighestIndex]) {
            printf("%c", product[productHighestIndex]);
            productHighestIndex++;
        } else {
            nullReached = 1;
        }
    }
    printf("\n~~~");
    printf("\n");
    
    return 0;
}