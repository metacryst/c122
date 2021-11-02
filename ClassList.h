#include "Data.h"

template <class T>
class Node {
    T data;
    Node<T>* next;
        
};

template <class T>
class List {
    
    Node<T>* head;
};

bool load();

List<T>* classList;


// time_t t = time(0);   // get time now
//     struct tm* now = localtime( & t );
//     cout<< (now->tm_year + 1900) << '-'
//         << (now->tm_mon + 1) << '-'
//         << now->tm_mday
//         << endl;