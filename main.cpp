#include <iostream>
using namespace std;

void displayMenu() {
    cout << "Hello! Here are your options: " << endl;
    cout << "1. Import List: " << endl;
}


int main() {
    displayMenu();
    
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout<< (now->tm_year + 1900) << '-'
        << (now->tm_mon + 1) << '-'
        << now->tm_mday
        << endl;
}