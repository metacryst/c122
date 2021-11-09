#include "ClassList.h"

bool editAbsences(List<Data>* classList) {
    if(!classList->head) {
        printf("-> No data! Try running load command first.\n\n");
        return false;
    }
    
    int studentID;
    cout <<  "~~ Enter ID of student to edit: "; cin >> studentID;
    string studentIDString = to_string(studentID);
    
    Node<Data>* student = classList->head;
    
    while(student) {
        if(student->data->IDnumber==studentIDString) {
            break;
        } else {
            student=student->next;
        }
    }
    if(!student) {
        cout << "-> No student found!" << endl;
        return false;
    }
    if(student->data->numAbsences==0) {
        cout << student->data->name << " has no absences!" << endl;
        return false;
    }
    
    cout << "-> Here are " << student->data->name << "'s absences: " << endl;
    cout << "   " << student->data->allAbsences->getAbsencesString() << endl;
    
    string date;
    cout << "~~ Enter Date of Absence to Delete (Ex: \"2021-11-9\"): "; cin >> date;
    bool lastAbsenceRemoved=(student->data->allAbsences->peek()==date);
    bool removed = student->data->allAbsences->removeAbsence(date);
    if(removed) {
        student->data->numAbsences--;
        printf("   ▣▣▣▣▣▣▣▣▣▣-▣-▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n");
        printf("   ▣ Record: %s\n", student->data->recordNumber.c_str());
        printf("   ▣ ID: %s\n", student->data->IDnumber.c_str());
        printf("   ▣ Name: %s\n", student->data->name.c_str());
        printf("   ▣ Email: %s\n", student->data->email.c_str());
        printf("   ▣ Units: %s\n", student->data->units.c_str());
        printf("   ▣ Program: %s\n", student->data->program.c_str());
        printf("   ▣ Level: %s\n", student->data->level.c_str());
        printf("   \033[1;91m▣ Absences: %d\n\033[m", student->data->numAbsences);
        if(lastAbsenceRemoved) {
        printf("   \033[1;91m▣ Last Absence: %s\n\033[m", student->data->allAbsences->peek().c_str());
        } else {
        printf("   ▣ Last Absence: %s\n", student->data->allAbsences->peek().c_str());
        }
        printf("   ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n\n");
    } else {
        printf("\n-> Absence not found!\n");
    }
    
    return removed ? true : false;
}