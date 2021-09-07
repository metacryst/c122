#include <stdio.h>
#include <stdlib.h>
#include "Club.h"

int main(void)
{
    // if we set one of the elements in the array, the rest of the elements will be set to one default value
    // here we are setting the first element of the array as this object
    Student students[100] = { {"", "", "", 0} };
    
    // "r" as second parameter means read
    // we are creating a stream here
    FILE* infile = fopen("data.csv", "r");
    int lineNumber = 0;
    char line[250] = "";
    
    if(infile != NULL) {
        printf("Opened File Successfully!\n");
        
        // if fgets reaches the end of the file it returns a null pointer
        // fgets reads one line
        while (fgets(line, 250, infile) != NULL) {
            
            // need to separate based on comma and put into correct struct field
            // string token takes delimiter (comma) and replaces with null character (\0)
            // so, we are forming a substring
            // the name of an array returns address of first character
            // strtok splits the string using comma and returns address of first character of new substring
            // then, strcopy puts the new substring into correct field
            strcpy (students[lineNumber].last, strtok(line, ","));
            
            // next, start at the newly inserted null pointer and go to the next comma
            // successive calls to strtok begin from where last left off
            // inside of strtok, there is a static variable that retains value of address across calls
            strcpy (students[lineNumber].first, strtok(NULL, ","));
            
            // now, strtok has address of null character before email characters
            strcpy (students[lineNumber].email, strtok(NULL, ","));
            
            // atio converts ascii to integer
            // if there was a string "27" in the line, atoi would return 27 as integer (it converts consecutive number characters)
            // fgets puts \n at the end of line so we can use that as delimiter
            students[lineNumber].classStanding = atio(strtok(NULL, "\n"));
            
            printf("%s, %s, %s, %d\n", 
                students[lineNumber].last,
                students[lineNumber].first,
                students[lineNumber].email,
                students[lineNumber].classStanding);
        }
    }
    
    return 0;
}