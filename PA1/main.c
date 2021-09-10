#include "FitbitData.h"

int main() {    
    FILE* infile = fopen("FitbitData.csv", "r");
    FILE* dataFile = fopen("DataResults.csv", "w");    
    
    if(infile == NULL) {
        printf("inFile not found!\n");
        return 0;
    } else {
        printf("Opened inFile Successfully!\n");
    }
    if (dataFile == NULL)
    {
        printf("dataFile not found!\n");
        return 0;
    } else {
        printf("Opened dataFile Successfully!\n");
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
        
        // printf("\n");
        
        char* scannedPatient = strtok(line, ",");
            int patientTargetMismatch = strcmp(targetPatient, scannedPatient);
            if(patientTargetMismatch) {
                continue;
            } else {
                fputs(scannedPatient, dataFile);
                fputs(",", dataFile);
            
                strcpy (data[iterations].patient, scannedPatient);
                // printf("patient: %s\n", data[iterations].patient);
            }
        
        char* scannedMinute = strtok(NULL, ",");
            if(scannedMinute) {
                fputs(scannedMinute, dataFile);
                fputs(",", dataFile);
                
                strcpy (data[iterations].minute, scannedMinute);
                // printf("minute: %s\n", data[iterations].minute);
            }
            
        char* scannedCalories = strtok(NULL, ",");
            if(scannedCalories) {
                fputs(scannedCalories, dataFile);
                fputs(",", dataFile);
                
                data[iterations].calories = atof(scannedCalories);
                totalCalories += data[iterations].calories;
                // printf("calories: %.9f\n", data[iterations].calories);
            }
            
        char* scannedDistance = strtok(NULL, ",");
            if(scannedDistance) {
                fputs(scannedDistance, dataFile);
                fputs(",", dataFile);
                
                data[iterations].distance = atof(scannedDistance);
                totalDistance += data[iterations].distance;
                // printf("distance: %.9f\n", data[iterations].distance);
            }
            
        char* scannedFloors = strtok(NULL, ",");
            if(scannedFloors) {
                fputs(scannedFloors, dataFile);
                fputs(",", dataFile);
                
                data[iterations].floors = (unsigned int) atoi(scannedFloors);
                totalFloors += data[iterations].floors;
                // printf("floors: %u\n", data[iterations].floors);
            }
                        
        char* scannedHeartRate;        
            if(doubleCommasPointer) {
                fputs("0,", dataFile);
                data[iterations].heartRate = 0;
             } else {
                scannedHeartRate = strtok(NULL, ",");
                
                fputs(scannedHeartRate, dataFile);
                fputs(",", dataFile);
                
                data[iterations].heartRate = (unsigned int) atoi(scannedHeartRate);     
                averageHeartRate = calculateAverageHeartRate(data[iterations].heartRate);
                // printf("heartRate: %u\n", data[iterations].heartRate);
            }
            
        char* scannedSteps = strtok(NULL, ",");
            if(scannedSteps) {
                fputs(scannedSteps, dataFile);
                fputs(",", dataFile);
                
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
                fputs(scannedSleep, dataFile);

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
                fputs("0", dataFile);
            }
            calculatePoorSleep(scannedMinute, data[iterations].sleepLevel);
            // printf("sleep: %d\n", data[iterations].sleepLevel);
            // printf("main ---LARGEST POOR SLEEP INTERVAL: %s\n", largestPoorSleepInterval);
        
        fputs("\n", dataFile);
        
        iterations++;
    }
    fclose(dataFile);
    fclose(infile);
    
    
    FILE* resultsFile = fopen("Results.csv", "w");
    if(resultsFile == NULL) {
        return 0;
    }
    dataFile = fopen("DataResults.csv", "r");
    if(dataFile)
    
    printf("\nTotal Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n");
    printf("%f,", totalCalories);
    printf("%f,", totalDistance);
    printf("%u,", totalFloors);
    printf("%u,", totalSteps);
    printf("%u,", averageHeartRate);
    printf("%u,", maxSteps);
    printf("%s\n", largestPoorSleepInterval);
    printf("\n");
    
    char totalCaloriesString[15];
    char totalDistanceString[15];
    char totalFloorsString[15];
    char totalStepsString[15];
    char averageHeartRateString[15];
    char maxStepsString[15];
    
    ftoa(totalCalories, totalCaloriesString, 10);
    ftoa(totalDistance, totalDistanceString, 10);
    itoa(totalFloors, totalFloorsString, 10);
    itoa(totalSteps, totalStepsString, 10);
    itoa(averageHeartRate, averageHeartRateString, 10);
    itoa(maxStepsString, maxStepsString, 10);
    
    fputs("Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps,Sleep\n", resultsFile);
    fputs(totalCaloriesString, resultsFile);
    fputs(",", resultsFile);
    fputs(totalDistanceString, resultsFile);
    fputs(",", resultsFile);
    fputs(totalFloorsString, resultsFile);
    fputs(",", resultsFile);
    fputs(totalStepsString, resultsFile);
    fputs(",", resultsFile);
    fputs(averageHeartRateString, resultsFile);
    fputs(",", resultsFile);
    fputs(maxStepsString, resultsFile);
    fputs(",", resultsFile);
    fputs(largestPoorSleepInterval, resultsFile);
    
    while(iterations > 0) {
        fgets(line, 250, dataFile);
        
        char* scannedPatient = strtok(line, ",");
                fputs(scannedPatient, resultsFile);
                fputs(",", resultsFile);

        
        char* scannedMinute = strtok(NULL, ",");
                fputs(scannedMinute, resultsFile);
                fputs(",", resultsFile);
            
            
        char* scannedCalories = strtok(NULL, ",");
                fputs(scannedCalories, resultsFile);
                fputs(",", resultsFile);
                
            
        char* scannedDistance = strtok(NULL, ",");
                fputs(scannedDistance, resultsFile);
                fputs(",", resultsFile);

            
        char* scannedFloors = strtok(NULL, ",");
                fputs(scannedFloors, resultsFile);
                fputs(",", resultsFile);

                        
        char* scannedHeartRate = strtok(NULL, ",");
                fputs(scannedHeartRate, resultsFile);
                fputs(",", resultsFile);
            
        char* scannedSteps = strtok(NULL, ",");
                fputs(scannedSteps, resultsFile);
                fputs(",", resultsFile);

            
        const char delimiters[] = " ,-!?\r\n";
        char* scannedSleep = strtok(NULL, delimiters);
                fputs(scannedSleep, resultsFile);
        
        
        fputs("\n", resultsFile);
        
        iterations--;
    }
    
    
    fclose(infile);
    fclose(resultsFile);
    
    
    return 1;
}