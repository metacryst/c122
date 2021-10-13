#include "../FitnessApp.h"

void FitnessAppWrapper::storeDailyDietPlan(fstream& fileStream, DietPlan& dietPlan) {
    if(!fileStream) {
        cerr << "No file!" << endl;
    }
    fileStream << dietPlan;
};
void FitnessAppWrapper::storeWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]) {
    for(int i = 0; i < 7; i++) {
        storeDailyDietPlan(fileStream, weeklyDietPlan[i]);
    }
};
