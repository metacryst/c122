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

class Grocery {
    string item;
    Grocery* next;
    friend class groceryList;

    Grocery(string grocery) {
        item = grocery;
        next = nullptr;
    }
};
class groceryList {
private:
    Grocery* first;
    Grocery* last;
    int count;
    friend class Customer;
public:
    groceryList(int express);
    ~groceryList();
    void addToList(int numberItems);
};

class Customer {
private:
    Data* data;    // The memory for Data will need to be allocated on the heap as well!
    groceryList* groceries;
    Customer* next;
    friend class Queue;
public:
    Customer(int express, int number, int totalTime) {
        this->groceries = new groceryList(express);
        this->data = new Data(this->groceries->count, number, totalTime+(this->groceries->count));
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
    
    int enqueue(Customer* customer);
    void dequeue();
    bool isEmpty();
    int serviceCustomer();
    int getTotalServiceTime();
    void print();
    void deleteQueue();
};