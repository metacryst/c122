#include <stdio.h>



void reverseString(char string[100]) {
    if(!string) {
        return;
    }
    
    reverseString(*(string+1));
    printf("%c", *string);
}


int main() {
    char string[100];

    printf("Give a string: ");

    // Max length of 99 characters; puts a null terminated string in string, thus 99 chars + null is the max
    scanf("%99s", string);

    printf("This is your string: %s\n", string);
    
    // *string == string[0], so incrementing string and going to value will move along array
    // the star brings us to the value the address indicates
    reverseString(string);
    
    return 0;
}