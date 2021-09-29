#include <iostream>
using namespace std;

class FitnessAppWrapper {
  private:
    string test;

  public:
    FitnessAppWrapper() {
        test = "abc";
        cout << "-->Wrapper Running Constructor" << endl;
    }

    string getTest() {
        return test;
    }
};

class Plan {
  private:
    string name;
    string date;
};