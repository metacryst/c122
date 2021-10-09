#include "FitnessApp.h"

istream& operator>>(istream& lhs, DietPlan& plan)
{  
    string name;
    getline(lhs, name);
    plan.name = name;    
    
    string caloriesString;
    getline(lhs, caloriesString);
    int calories = stoi(caloriesString);
    plan.calories = calories;
    
    string date;
    getline(lhs, date);
    plan.date = date;

    return lhs;
}

ostream& operator<<(ostream& lhs, DietPlan& plan)
{  
    lhs << plan.name << endl;
    lhs << plan.calories << endl;
    lhs << plan.date;

    return lhs;
} 