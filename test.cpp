#include "Test.h"


int enqueueOnEmptyQueue(Queue* testQueue) {
    testQueue->enqueue(new Customer(3, 1, 3)); // serviceTime, Number, total time
    if(!(testQueue->isEmpty()) && testQueue->getTotalServiceTime()==3) {
        return 1;
    } else {
        return 0;
    }
}
int enqueueOnOneNodeQueue(Queue* testQueue) {
    testQueue->enqueue(new Customer(4, 2, 7)); 
    if(!(testQueue->isEmpty()) && testQueue->getTotalServiceTime()==7) {
        return 1;
    } else {
        return 0;
    }
}
int dequeueOnTwoNodeQueue(Queue* testQueue) {
    testQueue->dequeue(); 
    if(!(testQueue->isEmpty()) && testQueue->getTotalServiceTime()==4) {
        return 1;
    } else {
        return 0;
    }
}
int dequeueOnOneNodeQueue(Queue* testQueue) {
    testQueue->dequeue(); 
    if(testQueue->isEmpty()) {
        return 1;
    } else {
        return 0;
    }
}


void runTests() {
    system("clear");
    
    Queue* testQueue = new Queue();
    
    cout << "Test One:  enqueueOnEmptyQueue" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    int one = enqueueOnEmptyQueue(testQueue);
    one ? cout<<"  \033[1;42m Success! \033[m"<<endl : cout<<"  \033[1;5;30;41m FAILED \033[m"<<endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  
  cout << "Test Two:  enqueueOnOneNodeQueue" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    int two = enqueueOnOneNodeQueue(testQueue);
    two ? cout<<"  \033[1;42m Success! \033[m"<<endl : cout<<"  \033[1;5;30;41m FAILED \033[m"<<endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  
  cout << "Test Three:  dequeueOnTwoNodeQueue" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    int three = dequeueOnTwoNodeQueue(testQueue);
    three ? cout<<"  \033[1;42m Success! \033[m"<<endl : cout<<"  \033[1;5;30;41m FAILED \033[m"<<endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  
  cout << "Test Four:  dequeueOnOneNodeQueue" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    int four = dequeueOnOneNodeQueue(testQueue);
    four ? cout<<"  \033[1;42m Success! \033[m"<<endl : cout<<"  \033[1;5;30;41m FAILED \033[m"<<endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  
  delete(testQueue);
  
    cout << "Test 5:  24 Hour Simulation" << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    cout << "Get Ready..." << endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(1500));
  
}