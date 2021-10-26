#include <iostream>
#include <fstream>
#include <sstream>
using std::string; using std::cout; using std::endl; using std::fstream; using std::istringstream;

class MorseNode{
    string character;
    string morse;
    MorseNode* left;
    MorseNode* right;
  public:
    MorseNode(string character, string morse) {
        left = nullptr;
        right = nullptr;
        this->character = character;
        this->morse = morse;
    }
};

class MorseTree{
    fstream MorseTable;
  public:
    MorseTree() 
    {
        cout << "morsetree" << endl;
        MorseTable.open("MorseTable.txt");
        string line = "";
        while(getline(MorseTable,line)) {
            istringstream iss(line);
            string englishCharacter; iss >> englishCharacter;
            string morse = "";
            string morseCharacter = "";
            while (iss >> morseCharacter) {
                morse += morseCharacter;
            }
            addNewNode(englishCharacter, morse);
        }
        MorseTable.close();
    }
    
    void addNewNode(string englishCharacter, string morse) 
    {
        MorseNode* newNode = new MorseNode(englishCharacter, morse);
    }
};