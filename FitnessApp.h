#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class FitnessAppWrapper {

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
      cout << "1. Load Stream " << endl;
      cout << endl;
      cout << "☾☾ Enter command: ";   
      
      int command = 0;
      cin >> command;
      cout << endl << "Command: " << command << endl;
      
      switch(command) {
        case 1:
          cout << "Command is 1." << endl;
          break;
        default: 
          cout << "Command not recognized!" << endl;
          break;
      }
    }
    
};

class Plan {
  private:
    string name;
    string date;
};