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
    ~Node() {
        delete(data);
    }
    
    
};

template <class T>
class List {
public:
    Node<T>* head;
    
    List() {
        head=nullptr;
    }
    ~List() {
        destroy();
    }
    
    void add(Data* newStudent) {        
        Node<T>* next = this->head;
        
        this->head = new Node<Data>;
        this->head->data = newStudent;
        this->head->next = next;        
    }
    
    void destroy() {
        while(head) {
            Node<Data>* temp=head->next;
            delete(head);
            head=temp;
        }
    }
    
};

bool load(List<Data>* list, fstream& classFile);
bool markAbsences(List<Data>* classList);
bool store(List<Data>* classList, fstream& masterFile);
bool loadMaster(List<Data>* classList, fstream& masterFile);