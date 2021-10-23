#include <iostream>
using std::string; using std::cout; using std::endl;

class MorseNode{
    char character;
    MorseNode* left;
    MorseNode* right;
    
    MorseNode(char character, string morse) {
        left = nullptr;
        right = nullptr;
    }
};

class MorseTree{
    MorseNode _root;
public:
    MorseTree() {
        cout << "mousetree" << endl;
        // read from file, make tree
    }
};