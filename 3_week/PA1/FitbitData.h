#ifndef FIT_BIT_DATA_H
#define FIT_BIT_DATA_H // guard code



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
     NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
    char patient[10];
    char minute[9];
    double calories;
    double distance;
    unsigned int floors;
    unsigned int heartRate;
    unsigned int steps;
    Sleep sleepLevel;
    
} FitbitData;


static unsigned int heartRateSum = 0;
static unsigned int numberOfHeartRates = 0;
unsigned int calculateAverageHeartRate(unsigned int heartRate);

char largestPoorSleepInterval[20];
static int largestPoorSleepSum = 0;
void calculatePoorSleep(char* minute, Sleep sleepLevel);

#endif