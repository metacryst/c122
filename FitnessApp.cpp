#include "FitnessApp.h"

void FitnessAppWrapper::loadDailyDietPlan(fstream& fileStream, DietPlan& dietPlan) {
    string line;
    if (!fileStream.is_open()) {return;}
    
    fileStream >> dietPlan;
    
    fileStream.close();
    
    cout << *dailyDietPlan << endl;
}