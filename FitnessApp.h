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
    DietPlan* weeklyDietPlan;
    fstream dietFile;
  
public:
    FitnessAppWrapper() 
    {
        dietFile.open("dietPlans.txt");
        weeklyDietPlan = new DietPlan[7];
        displayMenu();
    }
    ~FitnessAppWrapper()
    {
        dietFile.close();
    }
    void displayMenu();
    
    void loadDailyDietPlan(fstream& fileStream, DietPlan& dietPlan);
    void loadWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]);
    
    void storeDailyDietPlan(fstream& fileSteam, DietPlan& dietPlan);
    void storeWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]);
    
    void displayDailyDietPlan(DietPlan& dietPlan);
    void displayWeeklyDietPlan(DietPlan weeklyDietPlan[]);
    
};
