#include "ClassList.h"

bool load(List<Data>* list, fstream& classFile) {
    list->destroy();
    
    string line;
    getline(classFile, line);
    
    while(getline(classFile, line)) {
        istringstream lineStream(line);
        Data* newStudent = new Data();
        
        string recordNumber;
        getline(lineStream, recordNumber, ',');
        newStudent->recordNumber = recordNumber;
        //cout << recordNumber << " ";
        //cout << endl;
        
        string IDnumber;
        getline(lineStream, IDnumber, ',');
        newStudent->IDnumber = IDnumber;
        //cout << IDnumber << " ";
        //cout << endl;
        
        string firstName;
        getline(lineStream, firstName, ',');
        string lastName;
        getline(lineStream, lastName, ',');
        string firstLast = firstName + "," + lastName;
        newStudent->name = firstLast;
        //cout << firstLast << " ";
        //cout << endl;
        
        string email;
        getline(lineStream, email, ',');
        newStudent->email = email;
        //cout << newStudent->email << " ";
        //cout << endl;
        
        string units;
        getline(lineStream, units, ',');
        newStudent->units = units;
        //cout << units << " ";
        //cout << endl;
        
        string program;
        getline(lineStream, program, ',');
        newStudent->program = program;
        //cout << program << " ";
        //cout << endl;
        
        string level;
        getline(lineStream, level, ',');
        newStudent->level = level;
        //cout << newStudent->level << " ";
        //cout << endl;
        
        list->add(newStudent);
    }
    
    
    return true;
}