#include "ClassList.h"

bool store(List<Data>* classList, fstream& masterFile) {
    if(!classList->head) {
        printf("-> No data! Try running load command first.\n\n");
        return false;
    }
    
    Node<Data>* student = classList->head;
    while(student) {
            // cout << "Printing: " << student->data->name << endl;
        
        masterFile << student->data->recordNumber << ",";
            // cout << "Record: " << student->data->recordNumber << endl;
        masterFile << student->data->IDnumber << ",";
            // cout << "ID: " << student->data->IDnumber << endl;
        masterFile << student->data->name << ",";
            // cout << "Name: " << student->data->name << endl;
        masterFile << student->data->email << ",";
            // cout << "Email: " << student->data->email << endl;
        masterFile << student->data->units << ",";
            // cout << "Units: " << student->data->units << endl;
        masterFile << student->data->program << ",";
            // cout << "Program: " << student->data->program << endl;
        masterFile << student->data->level << ",";
            // cout << "Level: " << student->data->level << endl;
        
        masterFile << "\n";
        masterFile << to_string(student->data->numAbsences);
        masterFile << ",";
        masterFile << student->data->allAbsences->getAbsencesString();
            // cout << "Absences: " << student->data->allAbsences->getAbsencesString();
        
        masterFile << "\n";
            // cout << endl;
            // cout << endl;
        student=student->next;
    }
    
    
    
     
     
     
    return true;
}