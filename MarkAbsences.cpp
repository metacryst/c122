#include "ClassList.h"

bool markAbsences(List<Data>* classList) {
    if(!classList->head) {
        printf("-> No data! Try running load command first.\n\n");
        return false;
    }
    
    
    Node<Data>* node=classList->head;
    int i=0;
    while(node) {
        i++;
        printf("▣▣▣▣▣▣▣▣▣▣-%d-▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n", i);
        printf("▣ Record: %s\n", node->data->recordNumber.c_str());
        printf("▣ ID: %s\n", node->data->IDnumber.c_str());
        printf("▣ Name: %s\n", node->data->name.c_str());
        printf("▣ Email: %s\n", node->data->email.c_str());
        printf("▣ Units: %s\n", node->data->units.c_str());
        printf("▣ Program: %s\n", node->data->program.c_str());
        printf("▣ Level: %s\n", node->data->level.c_str());
        printf("▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣▣\n\n");
        
        printf( "--Is %s absent? 1=Yes,0=No", node->data->name.c_str());
        int response;
        cin >> response;
        
        
        
        node=node->next;
    }
    
    
    time_t t = time(0);   // get time now
    struct tm* now = localtime( & t );
    cout<< (now->tm_year + 1900) << '-'
        << (now->tm_mon + 1) << '-'
        << now->tm_mday
        << endl;
        
    return true;
}