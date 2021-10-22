#include "Shopping.h"

void generateExpressCustomer(Queue* expressLane, int runs) {
    int newServiceTime = (rand() % 5 + 1);
    int newTotalTime = expressLane->getTotalServiceTime() + newServiceTime;
    
    expressLane->enqueue(new Customer(newServiceTime, runs, newTotalTime));
}
void simulateExpressLane(Queue* expressLane, int nextCustomerArrival, int runs) {
        cout << endl;
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "\033[1;31m---------------------------------------------------------\033[m" << endl;
    
        int customerCheckedOut = 0;
        if(!expressLane->isEmpty()) {
            customerCheckedOut = expressLane->serviceCustomer();
        }
        if(!customerCheckedOut) {
            cout << endl;
        }
        
        int customerArrived = 0;
        if(nextCustomerArrival == 0) {
            generateExpressCustomer(expressLane, runs);
            customerArrived = 1;
        }
        cout << "EXPRESS: ";
        expressLane->print();
        if(customerArrived) {
           cout << "                   ->" << runs << " has entered the Express Lane!" << endl;
        } else {
            cout << endl;
        }
        
        cout << "\033[1;31m---------------------------------------------------------\033[m" << endl;
}

void generateRegularCustomer(Queue* regularLane, int runs) {
    int newServiceTime = (rand() % (8 - 3 + 1) + 3);
    int newTotalTime = regularLane->getTotalServiceTime() + newServiceTime;
    
    regularLane->enqueue(new Customer(newServiceTime, runs, newTotalTime));
}
void simulateRegularLane(Queue* regularLane, int nextCustomerArrival, int runs) {
        cout << endl;
        cout << endl;
        cout << "\033[1;31m---------------------------------------------------------\033[m" << endl;
    
        int customerCheckedOut = 0;
        if(!regularLane->isEmpty()) {
            customerCheckedOut = regularLane->serviceCustomer();
        }
        if(!customerCheckedOut) {
            cout << endl;
        }
        
        int customerArrived = 0;
        if(nextCustomerArrival == 0) {
            generateRegularCustomer(regularLane, runs);
            customerArrived = 1;
        }
        cout << "REGULAR: ";
        regularLane->print();
        if(customerArrived) {
           cout << "                   ->" << runs << " has entered the Regular Lane." << endl;
        } else {
            cout << endl;
        }
        
        cout << "\033[1;31m---------------------------------------------------------\033[m" << endl;
}


int main() {
    srand (time(NULL));
    int runs = 0;
    int desiredRuns = 0;
    
    system("clear");
    cout << "   How many minutes would you like? | 999=Run Tests " << endl;
    cout << "   Minutes: ";
    cin >> desiredRuns;
    
    if(desiredRuns == 999) {
        runTests();
        desiredRuns = 86400;
    }
    
    Queue* expressLane = new Queue();
    int nextExpressArrival=(rand() % 5 + 1);
    Queue* regularLane = new Queue();
    int nextRegularArrival=(rand() % (8 - 3 + 1) + 3);
    while(runs < desiredRuns) {
        runs++;
        
        system("clear");
        cout << runs << endl;
        
        simulateExpressLane(expressLane, nextExpressArrival, runs);
        
        cout << endl;
        cout << endl;
        
        simulateRegularLane(regularLane, nextRegularArrival, runs);
        
        nextExpressArrival>0 ? nextExpressArrival-- : nextExpressArrival=(rand() % 5 + 1);
        nextRegularArrival>0 ? nextRegularArrival-- : nextRegularArrival=(rand() % (8 - 3 + 1) + 3);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    
}