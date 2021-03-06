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
    
    bool isEmpty() {
        return absences.back()=="None";
    }
    
    string getAbsencesString() {
        string absenceString = "";
        
        for (vector<string>::iterator t=absences.begin(); t!=absences.end(); ++t) {
            if(*t != "None") {
                absenceString += *t + ",";
            }
        }
        return absenceString;
    }
    
    bool removeAbsence(string absence) {
        int i = 0;
        for (vector<string>::iterator t=absences.begin(); t!=absences.end(); ++t) {
            if(*t == absence) {
                absences.erase(absences.begin() + i);
                return true;
            }
            i++;
        }
        return false;
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
    ~Data() {
        delete(allAbsences);
    }
};