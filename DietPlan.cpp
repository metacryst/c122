#include "FitnessApp.h"

// EXTRACTION
istream& operator>>(istream& lhs, DietPlan& plan)
{      
    string name;
        getline(lhs, name);
        if(name.length()==0) 
        {
            getline(lhs, name);
        }
        plan.name = name;
    // cout << name << endl;
        
    string caloriesString;
        getline(lhs, caloriesString);
        int calories = stoi(caloriesString);
        plan.calories = calories;
    // cout << calories << endl;
        
    string date;
        getline(lhs, date);
        plan.date = date;
    // cout << date << endl;

    return lhs;
}

// INSERTION
ostream& operator<<(ostream& lhs, DietPlan& plan)
{  
    // cout << "inside operator" << endl;
    lhs << " |" << plan.name << endl;
    lhs << " |" << plan.calories << endl;
    lhs << " |" << plan.date;

    return lhs;
}

fstream& operator<<(fstream& fileStream, DietPlan& plan)
{  
    fileStream << plan.name << endl;
    fileStream << plan.calories << endl;
    fileStream << plan.date << endl;
    fileStream << endl;

    return fileStream;
}

