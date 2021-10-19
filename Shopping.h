#include "iostream"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Simulation.h"
using std::cout;
using std::endl;
using std::string;

class Data {
private:
     int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
     int serviceTime;   // Random time; varies between express 1-5 and normal 3-8 lanes; units in minutes
     int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
     friend class Queue;
public:
    Data(int serviceTime, int number) {
        this->serviceTime = serviceTime;
        this->customerNumber = number;
    }
};

class Customer {
private:
     Data *data;    // The memory for Data will need to be allocated on the heap as well!
     Customer *next;
     friend class Queue;
public:
    Customer(int serviceTime, int number) {
        // need to figure out about randomly deciding express or regular
        // should probably hava a file or something that is the brain of the random generation
        this->data = new Data(serviceTime, number);
    }
};

class Queue {
private:
     Customer *front;
     Customer *back;
public:
    Queue() {
        front = nullptr;
        back = nullptr;
    }
    
    int enqueue(Customer* customer) {
        if(!isEmpty()) {
            this->back->next = customer;
        } else {
            this->front = customer;
            this->back = customer;
        }
                
        return this->back == customer ? 1 : 0;
    }
    void dequeue(Customer* customer) {
        Customer* nextCustomer = nullptr;
        if(!isEmpty()) {
            nextCustomer = front->next;
        }
        if(nextCustomer) {
            delete(front);
            front = nextCustomer;
        } else {
            delete(front);
            front = nullptr;
            back = nullptr;
        }
    }
    
    bool isEmpty() {
        return front == nullptr ? true : false;
    }
    
    void serviceCustomers() {
        if(front->data->serviceTime == 0) {
            dequeue(front);
        }
        Customer* customer = front;
        while(customer) {
            customer->data->serviceTime--;
            customer = customer->next;
        }
    }
    
    void print() {
        Customer* customer = front;
        string customerString = "";
        while(customer) {
            customerString = customerString + "<---Customer--";
        }
        cout << "## " << customerString << endl;
    }
};

Queue* expressLane;
Queue* regularLane;