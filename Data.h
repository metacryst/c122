#include <iostream>
using namespace std;


class Stack {
    int* top;
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