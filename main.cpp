#include "ClassList.h"

class Menu {
public:
Menu() {
    system("clear");
    cout << endl;
    cout << "Hello! Here are your options: " << endl;
    cout << "1. Import Class List " << endl;
    cout << "3. Store Master List " << endl;
    cout << "4. Mark Absences" << endl;
    cout << "7. Exit " << endl;
    cout << endl;
    
    List<Data>* classList = new List<Data>;
    fstream classFile;
    fstream masterFile;
    
    int command;
    while(command!=7) {
        cout << "~~1=Import List, 3=Store Master List, 4=Mark Absences, 7=Exit " << endl;
        cout << "~~Enter Command: "; cin>>command;
        switch(command) {
            case 1: {
                classFile.open("classList.csv");
                bool loaded=load(classList, classFile);
                if(loaded) printf("-> Loaded!\n\n");
                classFile.close();
                break;
            }
            case 3: {
                masterFile.open("masterList.txt");
                masterFile.close();
                break;
            }
            case 4:
                markAbsences(classList);
                cout << endl;
                cout << endl;
                cout << "  ~~~~~~END OF CLASS~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << endl;
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