#include "iostream"
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <chrono>
#include <thread>
using std::cout; using std::cin; using std::endl; using std::string; using std::to_string;

void runTests();

class Data {
private:
     int customerNumber; // Unique identifier; starts at 1; after 24 hours should be reset to 1
     int serviceTime;   // Random time; varies between express 1-5 and normal 3-8 lanes; units in minutes
     int totalTime;     // totalTime = serviceTime + sum of serviceTimes of customers in line before this customer; units in minutes
     friend class Queue;
public:
    Data(int serviceTime, int number, int totalTime) {
        this->serviceTime = serviceTime;
        this->customerNumber = number;
        this->totalTime = totalTime;
    }
};

class Customer {
private:
     Data* data;    // The memory for Data will need to be allocated on the heap as well!
     Customer* next;
     friend class Queue;
public:
    Customer(int serviceTime, int number, int totalTime) {
        this->data = new Data(serviceTime, number, totalTime);
        this->next = nullptr;
    }
    ~Customer() {
        delete(data);
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
    ~Queue() {
        deleteQueue();
    }
    
    int enqueue(Customer* customer) {
        if(!isEmpty()) {
            this->back->next = customer;
            this->back = customer;
        } else {
            this->front = customer;
            this->back = customer;
        }
                
        return this->back == customer ? 1 : 0;
    }
    void dequeue() {
        Customer* nextCustomer = nullptr;
        if(front) {
            nextCustomer = front->next;
        } else {return;}
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
    
    int serviceCustomer() {
        if(front) {
            front->data->serviceTime--;
        }
        if(front->data->serviceTime==0) {
            cout << "             <-" << front->data->customerNumber << " checked out, after " << front->data->totalTime << " minutes!" << endl;
            dequeue();
            return 1;
        }
        return 0;
    }
    
    int getTotalServiceTime() {
        Customer* customer = front;
        int time = 0;
        while(customer) {
            time += customer->data->serviceTime;
            customer = customer->next;
        }
        return time;
    }
    
    void print() {
        Customer* customer = front;
        string queueString = "    ";
        int customers = 0;
        while(customer) {
            queueString = queueString + "<-C-" + to_string(customer->data->customerNumber) + "-S-" 
            + to_string(customer->data->serviceTime) + "- ";
            customers++;
            if(customers%4 == 0) {
                cout << "INSIDE CONDITION" << endl;
                queueString = queueString;
                cout << "  " << queueString << endl;
                queueString = "    ";
            }
            customer = customer->next;
        }
        queueString = queueString;
        cout << "  " << queueString << endl;
    }
    
    void deleteQueue() {
        Customer* customer = front;
        Customer* nextCustomer;
        while(customer) {
            nextCustomer = customer->next;
            delete(customer);
            customer = nextCustomer;
        }
    }
};