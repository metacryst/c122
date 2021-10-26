#include <iostream>
#include <fstream>
#include <sstream>
using std::string; using std::cout; using std::endl; using std::fstream; using std::istringstream; using std::max;
using std::abs;

class MorseNode{
    string character;
    string morse;
    MorseNode* left;
    MorseNode* right;
    int height;
    int depth;
    
    friend class MorseTree;
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
    MorseNode* _root;
    
    public:
    MorseTree() {
        _root = nullptr;
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
            insert(englishCharacter, morse);
        }
        
        printPreorder();
        printDiagram();
        MorseTable.close();
    }
    
    
    
    void setHeight(MorseNode* node) {
        MorseNode* right = node->right;
        int rightHeight = (right ? right->height : -1);
        MorseNode* left = node->left;
        int leftHeight = (left ? left->height : -1);
        
        int nodeHeight=max(rightHeight, leftHeight) + 1;
        node->height = nodeHeight;
        
        int balanceFactor = rightHeight-leftHeight;
        if(balanceFactor>1) {
        }
        
        return;
    }
    
    
    void insert(string englishCharacter, string morse){
        if(_root == nullptr) {
            MorseNode* newNode = new MorseNode(englishCharacter, morse);
             _root = newNode;
            _root->depth = 0;
            _root->height = 0;
            return;
        }
        insertHelper(englishCharacter, morse, _root);}
    MorseNode* insertHelper(string englishCharacter, string morse, MorseNode* currentNode) {
        if(currentNode == nullptr) {
            MorseNode* newNode = new MorseNode(englishCharacter, morse);
            newNode->height = 0;
            return newNode;
        }
        
        if(englishCharacter < currentNode->character) {
            currentNode->left = insertHelper(englishCharacter, morse, currentNode->left);
            currentNode->left->depth = currentNode->depth + 1;
        } else if(englishCharacter > currentNode->character) {
            currentNode->right = insertHelper(englishCharacter, morse, currentNode->right);
            currentNode->right->depth = currentNode->depth + 1;
        }
        
        setHeight(currentNode);
        return currentNode;
    }
    
    void printPreorder() {
        if(_root==nullptr) {return;};
        printPreorderHelper(_root);
        cout << endl;}
    void printPreorderHelper(MorseNode* node) {
        if(node==nullptr) {return;};
        cout << node->character << " ";
        printPreorderHelper(node->left);
        printPreorderHelper(node->right);
    }
    
    void printInorder() {
        if(_root==nullptr) {return;};
        printInorderHelper(_root);
        cout << endl;}
    void printInorderHelper(MorseNode* node) {
        if(node==nullptr) {return;};
        printInorderHelper(node->left);
        cout << node->character << " ";
        printInorderHelper(node->right);
    }
    
    void printDiagram() {
        if(_root==nullptr) return;
        printDiagramHelper(_root);}
    void printDiagramHelper(MorseNode* node) {
        if(node==nullptr) return;
        
        // get first node (root)
        // set left print space to half of terminal
        // add node to list
        // print nodes in list
        //    for each child child of nodes in list, print right or left
        // edge left print space left by one node (so 2 spaces?)
        // if we could dynamically get width of terminal it would work
        
        cout << node->character << " " << node->depth << " " << node->height << endl;
        if(node->left) {
            cout << "/" << endl;
            printDiagramHelper(node->left);
        }
        if(node->right) {
           cout << "\\" << endl;;
           printDiagramHelper(node->right);
        }
    }
};




    
    // MorseNode* addNewNode(string englishCharacter, string morse) {
    //     MorseNode* thisNode = _root;
    //     if(!thisNode) {
    //         _root = new MorseNode(englishCharacter, morse);
    //         goto NodeFound;
    //     }
        
    //     LOOP:
    //     if(englishCharacter < thisNode->character) {
    //         cout << "left" << endl;
    //         if(thisNode->left) {thisNode = thisNode->left;}
    //         else {
    //             thisNode->left = new MorseNode(englishCharacter, morse);
    //             goto NodeFound;
    //         }
    //     } 
    //     else if(englishCharacter > thisNode->character) {
    //         cout << "right" << endl;
    //         if(thisNode->right) {thisNode = thisNode->right;}
    //         else {
    //             thisNode->right = new MorseNode(englishCharacter, morse);
    //             goto NodeFound;
    //         }
    //     }
    //     goto LOOP;
        
        
    //     NodeFound:
    //     return thisNode;
    // }