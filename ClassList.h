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
public:
    Node<T>* head;
    
    List() {
        head=nullptr;
    }
    
    void add(Data* newStudent) {        
        Node<T>* next = this->head;
        
        this->head = new Node<Data>;
        this->head->data = newStudent;
        this->head->next = next;        
    }
    
};

bool load(List<Data>* list, fstream& classFile);
bool markAbsences(List<Data>* classList);