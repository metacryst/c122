#include "ClassList.h"

bool generateReports(List<Data>* classList) {
    if(!classList->head) {
        printf("-> No data! Try running load command first.\n\n");
        return false;
    }
    
    int report = 0;
    cout << "-> Which Report? (1=Most Recent Absences, 2=Students With X Absences): ";
    cin >> report;
    
    if(report==1) {
        Node<Data>* student=classList->head;
        int i=0;
        printf("\n");
        while(student) {      
            i++;
                
            printf("  ▣▣▣▣▣▣▣▣▣▣-%d-▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n", i);
            printf("  ▣ Name: %s\n", student->data->name.c_str());
            printf("  ▣ Last Absence: %s\n", student->data->allAbsences->peek().c_str());
            printf("  ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n\n");
                
            student=student->next;
            
        }
        return true;
    } else if(report==2) {
        int absences = 0;
        cout << "-> Enter Number of Absences to Search For: ";
        cin >> absences;
        
        Node<Data>* student=classList->head;
        int i=0;
        bool studentFound = false;
        printf("\n");
        while(student) {    
            if(student->data->numAbsences!=absences) {student=student->next; continue;}  
            studentFound=true;
            i++;
                
            printf("  ▣▣▣▣▣▣▣▣▣▣-%d-▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n", i);
            printf("  ▣ Name: %s\n", student->data->name.c_str());
            printf("  \033[1;91m▣ # Absences: %d\n\033[m", student->data->numAbsences);
            printf("  ▣ Last Absence: %s\n", student->data->allAbsences->peek().c_str());
            printf("  ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n\n");
                
            student=student->next;
        }
        
        if(!studentFound) {
            printf("-> No students found!\n");
        }
        return true;
    }
    cout << "-> Command not Recognized! " << endl;
    return false;
}