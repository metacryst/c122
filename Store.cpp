#include "ClassList.h"

bool store(List<Data>* classList, fstream& masterFile) {
    if(!classList->head) {
        printf("-> No data! Try running load command first.\n\n");
        return false;
    }
    
    Node<Data>* student = classList->head;
    while(student) {
        masterFile << student->data->recordNumber << ",";
        masterFile << student->data->IDnumber << ",";
        masterFile << student->data->name << ",";
        masterFile << student->data->email << ",";
        masterFile << student->data->units << ",";
        masterFile << student->data->program << ",";
        masterFile << student->data->level;
        masterFile << to_string(student->data->numAbsences);
        
        masterFile << student->data->allAbsences->getAbsencesString();
        
        masterFile << "\n";
        
        student=student->next;
    }
    
    
    
     
     
     
    return true;
}