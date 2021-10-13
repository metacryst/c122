#include "../FitnessApp.h"

void FitnessAppWrapper::editDailyDietPlan(int day) {
    cout << weeklyDietPlan[day-1] << endl;
    
    int field = 0;
    cout << "☾☾ 1=Name, 2=Calories, 3=Date: " << endl;
    cout << "☾☾ Command: " << endl;
    cin >> field;
    
    
    return;
};