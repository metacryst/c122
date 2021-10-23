#include "../FitnessApp.h"

void FitnessAppWrapper::loadDailyDietPlan(fstream& fileStream, DietPlan& dietPlan) {
    if (!fileStream.is_open()) {return;}
    
    fileStream >> dietPlan;
}
void FitnessAppWrapper::loadWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]) {
    for(int i = 0; i < 7; i++) {
        loadDailyDietPlan(fileStream, weeklyDietPlan[i]);
    }
};

void FitnessAppWrapper::loadDailyExercisePlan(fstream& fileStream, ExercisePlan& exercisePlan) {
    if (!fileStream.is_open()) {return;}
    
    fileStream >> exercisePlan;
}
void FitnessAppWrapper::loadWeeklyExercisePlan(fstream& fileStream, ExercisePlan weeklyExercisePlan[]) {
    for(int i = 0; i < 7; i++) {
        loadDailyExercisePlan(fileStream, weeklyExercisePlan[i]);
    }
};