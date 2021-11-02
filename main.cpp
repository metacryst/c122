#include "ClassList.h"

class Menu {
public:
Menu() {
    cout << endl;
    cout << "Hello! Here are your options: " << endl;
    cout << "1. Import List " << endl;
    cout << "7. Exit " << endl;
    cout << endl;
    
    List<Data>* classList = new List<Data>;
    fstream classFile;
    
    int command;
    while(command!=7) {
        cout << "--Enter Command: "; cin>>command;
        switch(command) {
            case 1:
                classFile.open("classList.csv");
                load(classList, classFile);
                classFile.close();
                break;
            case 7:
                return;
        }
    }
}
};



int main() {
    Menu* menu = new Menu();    
}