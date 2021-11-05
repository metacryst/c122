#include "ClassList.h"

bool LoadMaster(List<Data>* classList, fstream& masterList) {
    string line;
    getline(masterList, line);
    
    while(getline(masterList, line)) {
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
        
        
        
        
        getline(masterList, line);
        istringstream line2Stream(line);
        
        string numAbsencesString;
        getline(line2Stream, numAbsencesString, ',');
        newStudent->numAbsences = stoi(numAbsencesString);
        
        string absence;
        while(getline(line2Stream, absence, ',')) {
            newStudent->allAbsences->push(absence); // gonna be in the wrong order
        }
    }
}
