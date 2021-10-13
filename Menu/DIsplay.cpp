#include "../FitnessApp.h"

void FitnessAppWrapper::displayDailyDietPlan(DietPlan& dietPlan) {
    cout << endl << dietPlan << endl;
};
void FitnessAppWrapper::displayWeeklyDietPlan(DietPlan weeklyDietPlan[]) {
    string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i = 0; i < 7; i++) {
        cout << endl << i+1 << " " + days[i];
        displayDailyDietPlan(weeklyDietPlan[i]);
    }
};