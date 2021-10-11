#include "FitnessApp.h"

void FitnessAppWrapper::loadDailyDietPlan(fstream& fileStream, DietPlan& dietPlan) {
    if (!fileStream.is_open()) {return;}
    
    fileStream >> dietPlan;
}
void FitnessAppWrapper::loadWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]) {
    for(int i = 0; i < 7; i++) {
        loadDailyDietPlan(fileStream, weeklyDietPlan[i]);
    }
};

void FitnessAppWrapper::storeDailyDietPlan(fstream& fileStreamDietPlan& dietPlan) {
    fileStream << dietPlan;
    
};
void FitnessAppWrapper::storeWeeklyDietPlan(DietPlan weeklyDietPlan[]) {
    for(int i = 0; i < 7; i++) {
        storeDailyDietPlan(weeklyDietPlan[i]);
    }
};

void FitnessAppWrapper::displayDailyDietPlan(DietPlan& dietPlan) {
    cout << endl << dietPlan << endl;
};
void FitnessAppWrapper::displayWeeklyDietPlan(DietPlan weeklyDietPlan[]) {
    for(int i = 0; i < 7; i++) {
        displayDailyDietPlan(weeklyDietPlan[i]);
    }
};