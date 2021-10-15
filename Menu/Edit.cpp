#include "../FitnessApp.h"

void FitnessAppWrapper::editDailyDietPlan(int day) {
    cout << endl << weeklyDietPlan[day-1] << endl << endl;
    
    int command = 0;
    cout << "☾☾ 1=Name, 2=Calories, 3=Date: " << endl;
    cout << "☾☾ Command: ";
    cin >> command;
    
    switch(command) {
        case 1: {
            string newName;
            cout << "☾☾ Enter New Name: ";
            cin.ignore(); // get rid of any extraneous "\n"
            getline(cin, newName);
            weeklyDietPlan[day-1].setName(newName);
            break;
        }
        case 2: {
            int newCalories;
            cout << "☾☾ Enter New Calories: ";
            cin >> newCalories;
            weeklyDietPlan[day-1].editGoal(newCalories);
            break;
        }
        case 3: {
            string newDate;
            cout << "☾☾ Enter New Date: ";
            cin.ignore(); // get rid of any extraneous "\n"
            getline(cin, newDate);
            weeklyDietPlan[day-1].setDate(newDate);
            break;
        }
    }
    
    cout << endl << "-> Here is your new Plan!" << endl;
    cout << weeklyDietPlan[day-1] << endl;
    
    return;
};