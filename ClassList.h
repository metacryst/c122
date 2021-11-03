#include "Data.h"
#include <fstream>
#include <sstream>


template <class T>
class Node {
    public:
    T* data;
    Node<T>* next;
    
    Node() {
        this->data = nullptr;
        this->next = nullptr;
    }
};

template <class T>
class List {
    Node<T>* head;
public:
    List() {
        head=nullptr;
    }
    
    void add(Data* newStudent) {
        cout << "adding " << newStudent->name << endl;
        
        Node<T>* next = this->head;
        
        this->head = new Node<Data>;
        this->head->data = newStudent;
        this->head->next = next;
        
        cout << endl;
    }
    
};

bool load(List<Data>* list, fstream& classFile);


// time_t t = time(0);   // get time now
//     struct tm* now = localtime( & t );
//     cout<< (now->tm_year + 1900) << '-'
//         << (now->tm_mon + 1) << '-'
//         << now->tm_mday
//         << endl;