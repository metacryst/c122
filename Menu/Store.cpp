#include "../FitnessApp.h"

void FitnessAppWrapper::storeDailyDietPlan(fstream& fileStream, DietPlan& dietPlan) {
    if(!fileStream) {
        cerr << "No file!" << endl;
    }
    
    fileStream << dietPlan;
};
int FitnessAppWrapper::storeWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]) {
    if(!dietPlansLoaded) {
        cout << "-> Failed. Try Running Load Command First!" << endl;
        return 0;
    }
    for(int i = 0; i < 7; i++) {
        storeDailyDietPlan(fileStream, weeklyDietPlan[i]);
    }
    return 1;
};

void FitnessAppWrapper::storeDailyExercisePlan(fstream& fileStream, ExercisePlan& exercisePlan) {
    if(!fileStream) {
        cerr << "No file!" << endl;
    }
    fileStream << exercisePlan;
};
int FitnessAppWrapper::storeWeeklyExercisePlan(fstream& fileStream, ExercisePlan weeklyExercisePlan[]) {
    if(!exercisePlansLoaded) {
        cout << "-> Failed. Try Running Load Command First!" << endl;
        return 0;
    }
    for(int i = 0; i < 7; i++) {
        storeDailyExercisePlan(fileStream, weeklyExercisePlan[i]);
    }
    return 1;
};