#include "Shopping.h"
#include <chrono>
#include <thread>

int runs = 0;

int generateExpressCustomer() {
    int newServiceTime = (rand() % 5 + 1);
    int newTotalTime = expressLane->getTotalTime() + newServiceTime;
    
    expressLane->enqueue(new Customer(newServiceTime, runs, newTotalTime));
    int nextCustomerArrival = (rand() % 5 + 1);
    return nextCustomerArrival;
}

void simulateExpressLane() {
    expressLane = new Queue();
    
    int nextCustomerArrival = (rand() % 5 + 1);
    
    while(runs < 20) {
        system("clear");
        cout << runs << endl;
        cout << endl;
        cout << endl;
        
        int customerCheckedOut = 0;
        if(!expressLane->isEmpty()) {
            customerCheckedOut = expressLane->serviceCustomer();
        }
        if(!customerCheckedOut) {
            cout << endl;
        }
        
        int customerArrived = 0;
        if(nextCustomerArrival == 0) {
            nextCustomerArrival = generateExpressCustomer();
            customerArrived = 1;
        }
        cout << "EXPRESS: ";
        expressLane->print();
        if(customerArrived) {
           cout << "                   " << runs << " has entered the Express Lane!" << endl;
        }
        
        nextCustomerArrival--;
        runs++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


int main() {
    srand (time(NULL));
    simulateExpressLane(); // may need to move timing here: --> simulate express lane, then regular lane, then sleep
}