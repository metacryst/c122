#include "ClassList.h"

bool markAbsences(List<Data>* classList) {
    if(!classList->head) {
        printf("-> No data! Try running load command first.\n\n");
        return false;
    }
    
    
    Node<Data>* student=classList->head;
    int i=0;
    while(student) {        
        i++;
        
        printf( "  Is %s absent? (\033[1;91m1=Yes\033[m,0=No): ", student->data->name.c_str());
        int response;
        cin >> response;
        
        if(response==1) {
            time_t t = time(0);   // get time now
            struct tm* now = localtime( & t );
            
            string absence;
            absence += to_string(now->tm_year+1900);
            absence += "-";
            absence += to_string(now->tm_mon + 1);
            absence += "-";
            absence += to_string(now->tm_mday);
            
            student->data->allAbsences->push(absence);
            student->data->numAbsences++;
            
            printf("  ▣▣▣▣▣▣▣▣▣▣-%d-▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n", i);
            printf("  ▣ Record: %s\n", student->data->recordNumber.c_str());
            printf("  ▣ ID: %s\n", student->data->IDnumber.c_str());
            printf("  ▣ Name: %s\n", student->data->name.c_str());
            printf("  ▣ Email: %s\n", student->data->email.c_str());
            printf("  ▣ Units: %s\n", student->data->units.c_str());
            printf("  ▣ Program: %s\n", student->data->program.c_str());
            printf("  ▣ Level: %s\n", student->data->level.c_str());
            printf("  \033[1;91m▣ Absences: %d\n\033[m", student->data->numAbsences);
            printf("  \033[1;91m▣ Last Absence: %s\n\033[m", student->data->allAbsences->peek().c_str());
            printf("  ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n\n");
            
            student=student->next;
            continue;
        }
        
        printf("  ▣▣▣▣▣▣▣▣▣▣-%d-▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n", i);
        printf("  ▣ Record: %s\n", student->data->recordNumber.c_str());
        printf("  ▣ ID: %s\n", student->data->IDnumber.c_str());
        printf("  ▣ Name: %s\n", student->data->name.c_str());
        printf("  ▣ Email: %s\n", student->data->email.c_str());
        printf("  ▣ Units: %s\n", student->data->units.c_str());
        printf("  ▣ Program: %s\n", student->data->program.c_str());
        printf("  ▣ Level: %s\n", student->data->level.c_str());
        printf("  ▣ Absences: %d\n", student->data->numAbsences);
        printf("  ▣ Last Absence: %s\n", student->data->allAbsences->peek().c_str());
        printf("  ▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n\n");
        
        student=student->next;
    }
    
    
    cout << endl;
    cout << endl;
    cout << "  ~~~~~~END OF CLASS~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        
    return true;
}