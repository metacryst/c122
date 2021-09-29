#include <iostream>
using namespace std;

class FitnessAppWrapper {
public:
    string test;

    FitnessAppWrapper() {
        test = "abc";
        cout << "Constructor" << endl;
    }

    string getTest() {
        return test;
    }


};