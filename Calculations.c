#include "FitbitData.h"

unsigned int calculateAverageHeartRate(unsigned int heartRate) {
    heartRateSum += heartRate;
    numberOfHeartRates++;
    
    unsigned int averageHeartRate = heartRateSum/numberOfHeartRates;
    
    return averageHeartRate;
}


void calculatePoorSleep(char* minute, Sleep sleepLevel) {
    static int poorSleepSum = 0;
    static int lastMinuteHadPoorSleep = 0;
    static char beginMinute[10];
    static char endMinute[10];
    
    int goodSleepOrNoData = (sleepLevel==1 || sleepLevel==0);
    int poorSleep = (sleepLevel==2 || sleepLevel==3);
    
    int poorSleepStarting = (poorSleep && !lastMinuteHadPoorSleep);
    int poorSleepOngoing = (poorSleep && lastMinuteHadPoorSleep);
    int poorSleepEnding = (goodSleepOrNoData && lastMinuteHadPoorSleep);
    
    
    if(poorSleepStarting) {
        printf("~~~~~POOR SLEEP STARTING \n");
        memset(beginMinute, 0, sizeof beginMinute);
        strcpy(beginMinute, minute);
        
        printf("BEGIN MINUTE: %s\n", beginMinute);
        printf("END MINUTE: %s\n", endMinute);
        
        lastMinuteHadPoorSleep = 1;
        poorSleepSum += sleepLevel;
        printf("~~POOR SLEEP sum %d\n", poorSleepSum);
    }
    else if(poorSleepOngoing) {
        printf("~~POOR SLEEP ongoing \n");
        memset(endMinute, 0, sizeof endMinute);
        strcpy(endMinute, minute);
        
        printf("BEGIN MINUTE: %s\n", beginMinute);
        printf("END MINUTE: %s\n", endMinute);
        
        poorSleepSum += sleepLevel;
        printf("~~POOR SLEEP sum %d\n", poorSleepSum);
    }
    else if(poorSleepEnding) {
        printf("~~~~~POOR SLEEP ENDING \n");
        memset(endMinute, 0, sizeof endMinute);
        strcpy(endMinute, minute);
        
        printf("BEGIN MINUTE: %s\n", beginMinute);
        printf("END MINUTE: %s\n", endMinute);
        
        lastMinuteHadPoorSleep = 0;
        printf("~~POOR SLEEP sum %d\n", poorSleepSum);
        
        if(poorSleepSum > largestPoorSleepSum) {
            largestPoorSleepSum = poorSleepSum;
            
            printf("BEGIN MINUTE: %s\n", beginMinute);
            printf("END MINUTE: %s\n", endMinute);
            
            // clear out final interval arrays
            memset(largestPoorSleepInterval, 0, sizeof largestPoorSleepInterval);
            
            // write begin and end minutes to them
            strcpy(largestPoorSleepInterval, beginMinute);
            strcat(largestPoorSleepInterval, ":");
            strcat(largestPoorSleepInterval, endMinute);
            
            printf("LARGEST POOR SLEEP INTERVAL MINUTES: %s\n", largestPoorSleepInterval);
            printf("LARGEST POOR SLEEP INTERVAL MINUTES ADDRESS: %p\n", largestPoorSleepInterval);
        }
        
        poorSleepSum = 0;
        printf("~~LARGEST POOR SLEEP sum %d\n", largestPoorSleepSum);
    }
    else if(goodSleepOrNoData && !poorSleepOngoing) {
        return;
    }
}