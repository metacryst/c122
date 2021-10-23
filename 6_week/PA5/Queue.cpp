#include "Shopping.h"

int Queue::enqueue(Customer* customer) {
        if(!isEmpty()) {
            this->back->next = customer;
            this->back = customer;
        } else {
            this->front = customer;
            this->back = customer;
        }
                
        return this->back == customer ? 1 : 0;
    }
void Queue::dequeue() {
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

bool Queue::isEmpty() {
    return front == nullptr ? true : false;
}

int Queue::serviceCustomer() {
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

int Queue::getTotalServiceTime() {
    Customer* customer = front;
    int time = 0;
    while(customer) {
        time += customer->data->serviceTime;
        customer = customer->next;
    }
    return time;
}

void Queue::print() {
    Customer* customer = front;
    string queueString = "    ";
    int customers = 0;
    while(customer) {
        queueString = queueString + "<-C-" + to_string(customer->data->customerNumber) + "-S-" 
        + to_string(customer->data->serviceTime) + "- ";
        customers++;
        if(customers%4 == 0) {
            queueString = queueString;
            cout << "  " << queueString << endl;
            queueString = "    ";
        }
        customer = customer->next;
    }
    queueString = queueString;
    cout << "  " << queueString << endl;
}

void Queue::deleteQueue() {
    Customer* customer = front;
    Customer* nextCustomer;
    while(customer) {
        nextCustomer = customer->next;
        delete(customer);
        customer = nextCustomer;
    }
}