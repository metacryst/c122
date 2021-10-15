#include "FitnessApp.h"

void FitnessAppWrapper::displayMenu() {
      
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
      cout << "1. Load Weekly Diet Plan " << endl;
      cout << "3. Store Weekly Diet Plan " << endl;
      cout << "5. Display Weekly Diet Plan " << endl;
      cout << "7. Edit Daily Diet Plan " << endl;
      cout << endl;
      
      int command = 0;
      
  while(command != 11) {
      
      cout << "☾☾ Load, Store, Display, Edit\n";
      cout << "☾☾ 1,    3,     5,       7   | Diet\n";
      cout << "☾☾ 2,    4,     6,       8   | Exercise\n";
      cout << "☾☾ Enter Command: ";
      cin >> command;
      
      switch(command) {
        case 1: {
          cout << "-> Loading Weekly Diet Plan..." << endl;
          dietFile.open("dietPlans.txt");
            loadWeeklyDietPlan(dietFile, weeklyDietPlan);
          dietFile.close();
          cout << "-> Loaded." << endl;
          break;
        }
        case 2: {
          cout << "-> Loading Weekly Exercise Plan..." << endl;
          exerciseFile.open("exercisePlans.txt");
            loadWeeklyExercisePlan(exerciseFile, weeklyExercisePlan);
          exerciseFile.close();
          cout << "-> Loaded." << endl;
          break;
        }
        case 3: {
          cout << "-> Storing Weekly Diet Plan..." << endl;
          dietFile.open("dietPlans.txt");
            storeWeeklyDietPlan(dietFile, weeklyDietPlan);
          dietFile.close();
          cout << "-> Stored." << endl;
          break;
        }
        case 5: 
          cout << "-> Displaying Weekly Diet Plan..." << endl;
            displayWeeklyDietPlan(weeklyDietPlan);
          break;
        case 6: 
          cout << "-> Displaying Weekly Exercise Plan..." << endl;
            displayWeeklyExercisePlan(weeklyExercisePlan);
          break;
        case 7: 
            displayWeeklyDietPlan(weeklyDietPlan);
          int day;
          cout << endl << "☾☾ Enter Day Number: ";
          cin >> day;
            editDailyDietPlan(day);
          break;
        case 11:
          cout << "Exit." << endl;
          break;
        default: 
          cout << "Command not recognized!" << endl;
          break;
      }
      
      cout << endl;
  }
}


int main() {
    FitnessAppWrapper app;
    
    return 0;
}