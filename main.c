#include "FitbitData.h"

int main() {    
    FILE* infile = fopen("FitbitData.csv", "r");
    FILE* outfile = fopen("DataResults.csv", "w");    
    
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
    
    double totalCalories = 0;
    double totalDistance = 0;
    unsigned int totalFloors = 0;
    unsigned int totalSteps = 0;
    unsigned int averageHeartRate = 0;
    unsigned int maxSteps = 0;

    
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
        
        printf("\n");
        
        char* scannedPatient = strtok(line, ",");
            int patientTargetMismatch = strcmp(targetPatient, scannedPatient);
            if(patientTargetMismatch) {
                continue;
            } else {
                fputs(scannedPatient, outfile);
                fputs(",", outfile);
            
                strcpy (data[iterations].patient, scannedPatient);
                // printf("patient: %s\n", data[iterations].patient);
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
                totalCalories += data[iterations].calories;
                // printf("calories: %.9f\n", data[iterations].calories);
            }
            
        char* scannedDistance = strtok(NULL, ",");
            if(scannedDistance) {
                fputs(scannedDistance, outfile);
                fputs(",", outfile);
                
                data[iterations].distance = atof(scannedDistance);
                totalDistance += data[iterations].distance;
                // printf("distance: %.9f\n", data[iterations].distance);
            }
            
        char* scannedFloors = strtok(NULL, ",");
            if(scannedFloors) {
                fputs(scannedFloors, outfile);
                fputs(",", outfile);
                
                data[iterations].floors = (unsigned int) atoi(scannedFloors);
                totalFloors += data[iterations].floors;
                // printf("floors: %u\n", data[iterations].floors);
            }
                        
        char* scannedHeartRate;        
            if(doubleCommasPointer) {
                fputs("0,", outfile);
                data[iterations].heartRate = 0;
             } else {
                scannedHeartRate = strtok(NULL, ",");
                
                fputs(scannedHeartRate, outfile);
                fputs(",", outfile);
                
                data[iterations].heartRate = (unsigned int) atoi(scannedHeartRate);     
                averageHeartRate = calculateAverageHeartRate(data[iterations].heartRate);
                // printf("heartRate: %u\n", data[iterations].heartRate);
            }
            
        char* scannedSteps = strtok(NULL, ",");
            if(scannedSteps) {
                fputs(scannedSteps, outfile);
                fputs(",", outfile);
                
                data[iterations].steps = (unsigned int) atoi(scannedSteps);
                totalSteps += data[iterations].steps;
                if(data[iterations].steps > maxSteps) {
                    maxSteps = data[iterations].steps;
                }
                // printf("steps: %u\n", data[iterations].steps);
            }
            
        const char delimiters[] = " ,-!?\r\n";
        char* scannedSleep = strtok(NULL, delimiters);
            if(scannedSleep) {                
                fputs(scannedSleep, outfile);

                if(!strcmp(scannedSleep, "1")) {
                    data[iterations].sleepLevel = ASLEEP;
                }
                else if(!strcmp(scannedSleep, "2")) {
                    data[iterations].sleepLevel = AWAKE;
                }
                else if(!strcmp(scannedSleep, "3")) {
                    data[iterations].sleepLevel = REALLYAWAKE;
                }
            } else {
                data[iterations].sleepLevel = NONE;
                fputs("0", outfile);
            }
            calculatePoorSleep(scannedMinute, data[iterations].sleepLevel);
            printf("sleep: %d\n", data[iterations].sleepLevel);
            printf("main ---LARGEST POOR SLEEP INTERVAL: %s\n", largestPoorSleepInterval);
        
        fputs("\n", outfile);
        
        iterations++;
    }
    fclose(outfile);
    fclose(infile);
    
    
    printf("\nTotal Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
    printf("TOTAL CALORIES: %f\n", totalCalories);
    printf("TOTAL DISTANCE: %f\n", totalDistance);
    printf("TOTAL FLOORS: %u\n", totalFloors);
    printf("TOTAL STEPS: %u\n", totalSteps);
    printf("AVERAGE HEART RATE: %u\n", averageHeartRate);
    printf("MAX STEPS: %u\n", maxSteps);
    printf("SLEEP: %s\n", largestPoorSleepInterval);
    printf("\n");
    
    
    FILE* finalOutFile = fopen("Results.csv", "w");
    
    fputs("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n", finalOutFile);
    fputs("\n", finalOutFile);
    
    outfile = fopen("DataResults.csv", "r");
    
    while(iterations > 0) {
        fgets(line, 250, outfile);
        
        char* scannedPatient = strtok(line, ",");
                fputs(scannedPatient, finalOutFile);
                fputs(",", finalOutFile);

        
        char* scannedMinute = strtok(NULL, ",");
                fputs(scannedMinute, finalOutFile);
                fputs(",", finalOutFile);
            
            
        char* scannedCalories = strtok(NULL, ",");
                fputs(scannedCalories, finalOutFile);
                fputs(",", finalOutFile);
                
            
        char* scannedDistance = strtok(NULL, ",");
                fputs(scannedDistance, finalOutFile);
                fputs(",", finalOutFile);

            
        char* scannedFloors = strtok(NULL, ",");
                fputs(scannedFloors, finalOutFile);
                fputs(",", finalOutFile);

                        
        char* scannedHeartRate = strtok(NULL, ",");
                fputs(scannedHeartRate, finalOutFile);
                fputs(",", finalOutFile);
            
        char* scannedSteps = strtok(NULL, ",");
                fputs(scannedSteps, finalOutFile);
                fputs(",", finalOutFile);

            
        const char delimiters[] = " ,-!?\r\n";
        char* scannedSleep = strtok(NULL, delimiters);
                fputs(scannedSleep, finalOutFile);
        
        
        fputs("\n", finalOutFile);
        
        iterations--;
    }
    
    
    fclose(infile);
    fclose(finalOutFile);
    
    
    return 1;
}