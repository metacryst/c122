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
    ~Plan() {
        
    };
    string getName() {
        return this->name;
    }
    string setName(string newName) {
        this->name = newName;
        return this->name;
    }
    string getDate() {
        return this->date;
    }
    string setDate(string newDate) {
        this->date = newDate;
        return this->date;
    }
};

class DietPlan:public Plan {
    friend istream& operator>>(istream&, DietPlan&);
    friend ostream& operator<<(ostream&, DietPlan&);
    friend fstream& operator<<(fstream&, DietPlan&);
private:
    unsigned int calories;
    
public:
    DietPlan(unsigned int newCalories = 2000) {
      calories = newCalories;
    }
    DietPlan(const DietPlan &copy) {
	    calories = copy.calories;
	    name = copy.name;
        date = copy.date;
    }
    
    int editGoal(unsigned int newCalories) {
        this->calories = newCalories;
        return newCalories;
    }
};

class ExercisePlan:public Plan {
    friend istream& operator>>(istream&, ExercisePlan&);
    friend ostream& operator<<(ostream&, ExercisePlan&);
    friend fstream& operator<<(fstream&, ExercisePlan&);
private:
    unsigned int steps;
    
public:
    ExercisePlan(unsigned int newSteps = 100) {
      steps = newSteps;
    }
    ExercisePlan(const ExercisePlan &copy) {
	    steps = copy.steps;
	    name = copy.name;
        date = copy.date;
    }
    
    int editGoal(unsigned int newSteps) {
        this->steps = newSteps;
        return newSteps;
    }
};

class FitnessAppWrapper {
private:
    DietPlan* weeklyDietPlan;
    ExercisePlan* weeklyExercisePlan;
    fstream dietFile;
    fstream exerciseFile;
  
public:
    FitnessAppWrapper() 
    {
        weeklyDietPlan = new DietPlan[7];
        weeklyExercisePlan = new ExercisePlan[7];
        displayMenu();
    }
    ~FitnessAppWrapper()
    {
        dietFile.close();
        exerciseFile.close();
    }
    void displayMenu();
    
    // 1.
    void loadDailyDietPlan(fstream& fileStream, DietPlan& dietPlan);
    void loadWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]);
    // 2.
    void loadDailyExercisePlan(fstream& fileStream, ExercisePlan& exercisePlan);
    void loadWeeklyExercisePlan(fstream& fileStream, ExercisePlan weeklyExercisePlan[]);
    
    // 3.
    void storeDailyDietPlan(fstream& fileStream, DietPlan& dietPlan);
    void storeWeeklyDietPlan(fstream& fileStream, DietPlan weeklyDietPlan[]);
    
    
    // 5.
    void displayDailyDietPlan(DietPlan& dietPlan);
    void displayWeeklyDietPlan(DietPlan weeklyDietPlan[]);
    // 6.
    void displayDailyExercisePlan(ExercisePlan& exercisePlan);
    void displayWeeklyExercisePlan(ExercisePlan weeklyExercisePlan[]);
    
    void editDailyDietPlan(int day);
};
