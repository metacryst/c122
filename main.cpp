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
      cout << "1. Load Daily Diet Plan " << endl;
      cout << endl;
      cout << "☾☾ Enter command: ";
      
      int command = 0;
      cin >> command;
      cout << endl << "Command: " << command << endl;
      
      switch(command) {
        case 1: { // brackets to keep file in scope
          cout << "-> Loading Daily Diet Plan..." << endl;
          fstream infile("dietPlans.txt");
          dailyDietPlan = new DietPlan();
          loadDailyDietPlan(infile, *dailyDietPlan);
          break;
        }
        default: 
          cout << "Command not recognized!" << endl;
          break;
      }
    }


int main() {
    FitnessAppWrapper app;
    
    return 0;
}