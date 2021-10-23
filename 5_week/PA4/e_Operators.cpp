#include "FitnessApp.h"

// EXERCISE
istream& operator>>(istream& lhs, ExercisePlan& plan)
{      
    string name;
        getline(lhs, name);
        if(name.length()==0) 
        {
            getline(lhs, name);
        }
        plan.name = name;
    // cout << name << endl;
        
    string stepsString;
        getline(lhs, stepsString);
        int steps = stoi(stepsString);
        plan.steps = steps;
    // cout << steps << endl;
        
    string date;
        getline(lhs, date);
        plan.date = date;
    // cout << date << endl;

    return lhs;
}

// INSERTION
ostream& operator<<(ostream& lhs, ExercisePlan& plan)
{  
    // cout << "inside operator" << endl;
    lhs << " |" << plan.name << endl;
    lhs << " |" << plan.steps << endl;
    lhs << " |" << plan.date;

    return lhs;
}

fstream& operator<<(fstream& fileStream, ExercisePlan& plan)
{  
    fileStream << plan.name << endl;
    fileStream << plan.steps << endl;
    fileStream << plan.date << endl;
    fileStream << endl;

    return fileStream;
}