#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitbitData.h"


int main() {    
    FILE* infile = fopen("FitbitData.csv", "r");
    
    if(infile == NULL) {
        printf("File not found!\n");
        return 0;
    } else {
        printf("Opened File Successfully!\n");
    }
    
    
    FitbitData data[1440] = { {"", "", 0, 0, 0, 0, 0, 0} };
        
    int lineNumber = 1;
    char line[250] = "";
    char* patient;
    
    while (lineNumber == 1) {
        fgets(line, 250, infile);
        strtok(line, ",");
        patient = strtok(NULL, ",");
        printf("patient: %s\n", patient);
        lineNumber++;
    }
    
    while (lineNumber == 2) {
        fgets(line, 250, infile);
        strtok(line, ",");
        patient = strtok(NULL, ",");
        printf("patient: %s\n", patient);
        lineNumber++;
    }
    
    while(fgets(line, 250, infile)) {
        printf("lineNumber: %d\n", lineNumber);
        strcpy (data[lineNumber].patient, strtok(line, ","));
        printf("main loop: %s\n", data[lineNumber].patient);
        lineNumber++;
        break;
    }
    
    
        
        

    
    
    return 1;
}





// TA APPROACH
    // for each data type:
    //  if(temp) {
    //     write to file
    // } else {
    //    write 0
    //}