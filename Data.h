#include <iostream>
#include <vector>
using namespace std;


class Stack {
    vector<string> absences;
    
    public:
    Stack() {
        absences.push_back("None");
    }
    
    void push(string absence) {
        absences.push_back(absence);
    }
    
    void pop() {
        if(absences.back() != "None") {
            absences.pop_back();
        }
    }
    
    string peek() {
        return absences.back();
    }
};

class Data {
public:
    string recordNumber;
    string IDnumber;
    string name;
    string email;
    string units;
    string program;
    string level;
    
    int numAbsences;
    Stack* allAbsences;
    
    Data() {
        numAbsences=0;
        allAbsences=new Stack;
    }
};