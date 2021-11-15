#include "ClassList.h"

class Menu {
public:
Menu() {
    system("clear");
    cout << endl;
    cout << "Hello! Here are your options: " << endl;
    cout << "1. Import Class List " << endl;
    cout << "2. Load Master List " << endl;
    cout << "3. Store Master List " << endl;
    cout << "4. Mark Absences" << endl;
    cout << "5. Edit Absences" << endl;
    cout << "6. Get Reports" << endl;
    cout << "7. Exit " << endl;
    cout << endl;
    
    List<Data>* classList = new List<Data>;
    fstream classFile;
    fstream masterFile;
    
    int command;
    while(command!=7) {
        cout << "~~ 1=Import List, 2=Load Master List, 3=Store Master List," << endl;
        cout << "~~ 4=Mark Absences, 5=Edit Absences, 6=Get Reports, 7=Exit " << endl;
        cout << "~~ Enter Command: "; cin>>command;
        switch(command) {
            case 1: {
                classFile.open("classList.csv");
                bool loaded=load(classList, classFile);
                if(loaded) printf("-> Loaded!\n\n");
                classFile.close();
                break;
            }
            case 2: {
                masterFile.open("master.txt");
                bool masterLoaded=loadMaster(classList, masterFile);
                if(masterLoaded) printf("-> Loaded!\n\n");
                masterFile.close();
                break;
            }
            case 3: {
                masterFile.open("master.txt", ofstream::out | ofstream::trunc);
                bool stored=store(classList, masterFile);
                if(stored) printf("-> Stored!\n\n");
                masterFile.close();
                break;
            }
            case 4:
                markAbsences(classList);
                cout << endl;
                break;
            case 5: {
                bool edited = editAbsences(classList);
                if(edited) {
                    cout << "-> Absence Removed." << endl;
                }
                cout << endl;
                cout << endl;
                break;
            }
            case 6: {
                bool reported = generateReports(classList);
                cout << endl;
                break;
            }
            case 7:
                return;
        }
    }
}
};



int main() {
    Menu* menu = new Menu();    
}