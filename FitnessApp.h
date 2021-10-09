#include <iostream>
#include <fstream>
using namespace std;

class Plan {
protected: // protected so child classes can access
    string name;
    string date;
    
public:
    Plan(string newName = "", string newDate = "") {
      name = newName;
      date = newDate;
    }
};

class DietPlan:Plan {
    friend istream& operator>>(istream&, DietPlan&);
    friend ostream& operator<<(ostream&, DietPlan&);
private:
    unsigned int calories;
    
public:
    DietPlan(unsigned int newCalories = 2000) {
      calories = newCalories;
    }
};

class FitnessAppWrapper {
private:
    DietPlan* dailyDietPlan;
  
public:
    FitnessAppWrapper() {
        displayMenu();
    }
    void displayMenu();
    
    void loadDailyDietPlan(fstream& fileStream, DietPlan& dietPlan);
};
