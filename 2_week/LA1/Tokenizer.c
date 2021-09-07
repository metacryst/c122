#include <stdio.h>


// str is a pointer because C always converts arrays passed in to pointers
// it is not allowed to pass array values as parameters. Even if str parameter was an array, it would be converted to a pointer by the compiler.
char* myStrTok(char* str, const char* delim) {
    static char *pToken;
    
    int delimiterFound = 0;
    int runCounter = 0;
    char* firstCharacterAddress = str;
        
    while(!delimiterFound) {
        if(!*firstCharacterAddress) {
            return str;
        }
        
        printf("%c\n", *firstCharacterAddress);
        
        if(*firstCharacterAddress == *delim) {
            printf("%d\n", runCounter);
            delimiterFound = 1;
        }
        
        runCounter++;
        firstCharacterAddress++;
    }
    
    printf("%d\n", runCounter);
    return str;
}


int main() {
    char string[100];
    
    printf("Give a string: ");

    // Max length of 99 characters; puts a null terminated string in string, thus 99 chars + null is the max
    scanf("%99s", string);

    printf("This is your string: %s\n", string);
    
    // "string" will become a pointer automatically when passed as a parameter
    myStrTok(string, " ");
    
    return 0;
}

