#include "Shopping.h"
#include <chrono>
#include <thread>


void simulateExpressLane() {
    expressLane = new Queue();
    int runs = 0;
    
    int nextCustomerArrival = (rand() % 5 + 1);
    cout << "next Customer in " << nextCustomerArrival << "minutes" << endl;
    
    while(runs < 20) {
        cout << runs << endl;
        if(nextCustomerArrival == 0) {
            int serviceTime = (rand() % 5 + 1);
            expressLane->enqueue(new Customer(serviceTime, runs));
            nextCustomerArrival = (rand() % 5 + 1);
            cout << "next Customer in " << nextCustomerArrival << "minutes" << endl;
            expressLane->print();
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