#include <iostream>
#include <fstream>
using namespace std;

class Plan {
  private:
    string name;
    string date;
    
  public:
    Plan(string newName = "", string newDate = "") {
      name = newName;
      date = newDate;
    }
};
class DietPlan:Plan {
  private:
    unsigned int calories;
  public:
    DietPlan(unsigned int newCalories = 2000) {
      calories = newCalories;
    }
};

class FitnessAppWrapper {
  DietPlan dailyDietPlan;
  
  public:
    FitnessAppWrapper() {
        displayMenu();
    }
    
    void displayMenu() {
      
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "     _                             _      " << endl;  
      cout << "    | |                           | |      " << endl;  
      cout << "  =H| |========mn=======nm========| |H=" << endl;  
      cout << "    |_|        ( \\     / )        |_|  " << endl;  
      cout << "                \\ )(\")( /               " << endl;  
      cout << "                ( /\\_/\\ )              " << endl;    
      cout << "                 \\     /               " << endl;        
      cout << "                  )=O=(                " << endl;          
      cout << "                 /  _  \\               " << endl;                
      cout << "                /__/ \\__\\              " << endl;                
      cout << "                | |   | |              " << endl;                      
      cout << "                |_|   |_|              " << endl;          
      cout << "                (_)   (_)              " << endl;     
      
      cout << endl;
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "Welcome to Fitness! Here are your options: " << endl;
      cout << endl;
      cout << "1. Load Daily Diet Plan " << endl;
      cout << endl;
      cout << "☾☾ Enter command: ";
      
      int command = 0;
      cin >> command;
      cout << endl << "Command: " << command << endl;
      
      switch(command) {
        case 1:
          cout << "Loading Daily Diet Plan:" << endl;
          fstream infile("dietPlans.txt");
          dailyDietPlan = new DietPlan();
          loadDailyDietPlan(infile, dailyDietPlan);
          
          break;
        default: 
          cout << "Command not recognized!" << endl;
          break;
      }
    }
    
    void loadDailyDietPlan(fstream& fileStream, DietPlan& dietPlans);
};
