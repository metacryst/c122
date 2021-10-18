#include "iostream"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
using std::cout;

class Data {
private:
     int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
     int serviceTime;   // Random time; varies between express 1-5 and normal 3-8 lanes; units in minutes
     int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
public:
    Data(char express = 'n') {
        customerNumber = customers++;
        srand (time(NULL));
        serviceTime = express == 'e' ? rand() % 5 + 1 : rand() % 8 + 3;;
    }
};

class Customer {
private:
     Data *data;    // The memory for Data will need to be allocated on the heap as well!
     Customer *next;
     friend class Queue;
public:
    Customer() {
        // need to figure out about randomly deciding express or regular
        // should probably hava a file or something that is the brain of the random generation
        this->data = new Data();
    }
};

class Queue {
private:
     Customer *head;
     Customer *tail;
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }
    
    int enqueue(Customer* newItem) {
        this->tail->next = newItem;
        this->tail = newItem;
        
        return this->tail == newItem ? 1 : 0;
    }
    
    bool isEmpty() {
        return this->head == nullptr ? true : false;
    }
};


int customers;
Queue* expressLane;
Queue* regularLane;