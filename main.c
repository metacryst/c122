#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitbitData.h"

int strlen_recursive (const char* stringAddress) {
    if(!stringAddress[0]) {
        return 0;
    }
    
    int lengthIncrement = 1;
    lengthIncrement += strlen_recursive((stringAddress+lengthIncrement));
    
    return lengthIncrement;
}

int main() {    
    FILE* infile = fopen("FitbitData.csv", "r");
    FILE* outfile = fopen("Results.csv", "w");
    
    
    if(infile == NULL) {
        printf("inFile not found!\n");
        return 0;
    } else {
        printf("Opened inFile Successfully!\n");
    }
    if (outfile == NULL)
    {
        printf("outFile not found!\n");
        return 0;
    } else {
        printf("Opened outFile Successfully!\n");
    }
    
    
    FitbitData data[1440] = { {"", "", 0, 0, 0, 0, 0, 0} };
        
    char previousLine[250];
    char line[250] = "";
    char targetPatient[6] = "";
    
    // retrieve patient
    fgets(line, 250, infile);
    strtok(line, ",");
    strcpy(targetPatient, strtok(NULL, ","));
    
    // go to line 3
    fgets(line, 250, infile);
        
    // read file
    int iterations = 0;
    while(iterations < 1440) {
        fgets(line, 250, infile);
        
        int lineDuplicate = !strcmp(line, previousLine);
            if(lineDuplicate) {
                continue;
            }
            strcpy (previousLine, line);
        
        char* doubleCommasPointer = strstr(line, ",,");
        
        
        
        char* scannedPatient = strtok(line, ",");
            int patientTargetMismatch = strcmp(targetPatient, scannedPatient);
            if(patientTargetMismatch) {
                continue;
            } else {
                fputs(scannedPatient, outfile);
                fputs(",", outfile);
            
                strcpy (data[iterations].patient, scannedPatient);
                printf("\npatient: %s\n", data[iterations].patient);
            }
        
        char* scannedMinute = strtok(NULL, ",");
            if(scannedMinute) {
                fputs(scannedMinute, outfile);
                fputs(",", outfile);
                
                strcpy (data[iterations].minute, scannedMinute);
                printf("minute: %s\n", data[iterations].minute);
            }
            
        char* scannedCalories = strtok(NULL, ",");
            if(scannedCalories) {
                fputs(scannedCalories, outfile);
                fputs(",", outfile);
                
                data[iterations].calories = atof(scannedCalories);
                printf("calories: %.9f\n", data[iterations].calories);
            }
            
        char* scannedDistance = strtok(NULL, ",");
            if(scannedDistance) {
                fputs(scannedDistance, outfile);
                fputs(",", outfile);
                
                data[iterations].distance = atof(scannedDistance);
                printf("distance: %.9f\n", data[iterations].distance);
            }
            
        char* scannedFloors = strtok(NULL, ",");
            if(scannedFloors) {
                fputs(scannedFloors, outfile);
                fputs(",", outfile);
                
                data[iterations].floors = atof(scannedFloors);
                printf("floors: %u\n", data[iterations].floors);
            }
                        
        char* scannedHeartRate;        
            if(doubleCommasPointer) {
                fputs("0,", outfile);
                data[iterations].heartRate = 0;
             } else {
                scannedHeartRate = strtok(NULL, ",");
                
                fputs(scannedHeartRate, outfile);
                fputs(",", outfile);
                
                data[iterations].heartRate = atof(scannedHeartRate);
                printf("heartRate: %u\n", data[iterations].heartRate);
                
            }
            
        char* scannedSteps = strtok(NULL, ",");
            if(scannedSteps) {
                fputs(scannedSteps, outfile);
                fputs(",", outfile);
                
                data[iterations].steps = atof(scannedSteps);
                printf("steps: %u\n", data[iterations].steps);
            }
            
        const char delimiters[] = " ,-!?\r\n";
        char* scannedSleep = strtok(NULL, delimiters);
            if(scannedSleep) {
                printf("scannedSleep: %s\n", scannedSleep);
                
                fputs(scannedSleep, outfile);
                
                if(!strcmp(scannedSleep, "0")) {
                    data[iterations].sleepLevel = NONE;
                }
                else if(!strcmp(scannedSleep, "1")) {
                    data[iterations].sleepLevel = ASLEEP;
                }
                else if(!strcmp(scannedSleep, "2")) {
                    data[iterations].sleepLevel = AWAKE;
                }
                else if(!strcmp(scannedSleep, "3")) {
                    data[iterations].sleepLevel = REALLYAWAKE;
                } 
                else {
                    data[iterations].sleepLevel = 5;
                }
                
                
                printf("sleep: %d\n", data[iterations].sleepLevel);
            }
        
        
        
        fputs("\n", outfile);
        
        iterations++;
    }
    
    
    
    return 1;
}







// data[lineNumber].calories = atof(strtok(NULL, ","));
// printf("calories: %.9f\n", data[lineNumber].calories);



// TA APPROACH
    // for each data type:
    //  if(temp) {
    //     write to file
    // } else {
    //    write 0
    //}