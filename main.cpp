#include "Shopping.h"
#include <chrono>
#include <thread>

int runs = 0;

int generateExpressCustomer() {
    int newServiceTime = (rand() % 5 + 1);
    int newTotalTime = expressLane->getTotalTime() + newServiceTime;
    
    expressLane->enqueue(new Customer(newServiceTime, runs, newTotalTime));
    cout << "  Customer " << runs << " has entered the Express Lane!" << endl;
    int nextCustomerArrival = (rand() % 5 + 1);
    return nextCustomerArrival;
}

void simulateExpressLane() {
    expressLane = new Queue();
    
    int nextCustomerArrival = (rand() % 5 + 1);
    cout << "  next Customer in " << nextCustomerArrival << "minutes" << endl;
    
    while(runs < 20) {
        cout << runs << endl;
        if(!expressLane->isEmpty()) {
            expressLane->serviceCustomers(); // may need to put check at beginning and decrement at end to make more sense
        }
        expressLane->print();
        if(nextCustomerArrival == 0) {
            nextCustomerArrival = generateExpressCustomer();
            cout << "  next Customer in " << nextCustomerArrival << "minutes" << endl;
        }
        nextCustomerArrival--;
        runs++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}


int main() {
    srand (time(NULL));
    simulateExpressLane(); // possible move "runs" logic out here and have a function to check express lane
}