#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
#include "people.h"

using namespace std;

class Person 
{
  protected:
    string name;
    int age;
    char gender;
    int height;
  public:
    explicit Person(string _name, int _age, char _gender, int _height)
    {
        this->name = _name;
        this->age = _age;
        this->gender = _gender;
        this->height = _height;
    }
    
    // Person(string _name, int _age, char _gender, int _height) {
    //     this->name = _name;
    //     this->age = _age;
    //     this->gender = _gender;
    //     this->height = _height;
    // };
    // Person(string _name="", int _age=0, char _gender='M', int _height=0);
    
    
};


struct Course 
{
    string name;
    int credits;
    float grade;
};

class Student: public Person 
{
    Course courses[8];
    int coursesTaken;
    int totalCredits;
    
    

    Student(string _name, int _coursesTaken=8) {
        this->name = _name;
        coursesTaken=_coursesTaken;
    }
    
};

#endif