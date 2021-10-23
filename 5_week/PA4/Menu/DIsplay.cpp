#include "../FitnessApp.h"

void FitnessAppWrapper::displayDailyDietPlan(DietPlan& dietPlan) {
    cout << endl << dietPlan << endl;
};
int FitnessAppWrapper::displayWeeklyDietPlan(DietPlan weeklyDietPlan[]) {
    if(!dietPlansLoaded) {
        cout << "-> Failed. Try Running Load Command First!" << endl;
        return 0;
    }
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i = 0; i < 7; i++) {
        cout << endl << i+1 << " " + days[i];
        displayDailyDietPlan(weeklyDietPlan[i]);
    }
    return 1;
};

void FitnessAppWrapper::displayDailyExercisePlan(ExercisePlan& exercisePlan) {
    cout << endl << exercisePlan << endl;
};
int FitnessAppWrapper::displayWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[]) {
    if(!exercisePlansLoaded) {
        cout << "-> Failed. Try Running Load Command First!" << endl;
        return 0;
    }
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i = 0; i < 7; i++) {
        cout << endl << i+1 << " " + days[i];
        displayDailyExercisePlan(weeklyExercisePlan[i]);
    }
    return 1;
};