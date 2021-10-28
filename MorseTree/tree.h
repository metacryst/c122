#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

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
    
    bool setHeight() {
        int rightHeight = right ? right->height : -1;
        int leftHeight = left ? left->height : -1;
        height = max(rightHeight, leftHeight) + 1;
        
        int balanceFactor = rightHeight-leftHeight;
        return balanceFactor<=1 ? true : false;
    }
};

class MorseTree{
    fstream MorseTable;
    fstream convertFile;
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
        
        MorseTable.close();
    }
    
    string search(string character) {
        if(_root->character == character) return _root->morse;
        else return searchHelper(character, _root);
    }
    string searchHelper(string character, MorseNode* node) {
        if(node==nullptr) return "";
        if(node->character == character) return node->morse;
        
        return (character < node->character) ? searchHelper(character, node->left) : searchHelper(character, node->right);
    }
    
    string convert(string file) {
        convertFile.open(file);
        
        string line = "";
        string englishWord = "";
        string englishCharacter = "";
        string morseMatch = "";
        
        while(getline(convertFile,line)) {
            transform(line.begin(), line.end(), line.begin(), ::toupper);
            istringstream iss(line);
            while (iss >> englishWord) {
                while(englishWord!="") {
                    englishCharacter = string(1, englishWord[0]);
                    morseMatch = search(englishCharacter);
                    if(morseMatch != "") {
                        cout << "Found morse: " << morseMatch << endl;
                    } else {
                        cout << "No morse found: " << englishCharacter << endl;
                    }
                    englishWord.erase(0,1);
                }
            }
        }
        convertFile.close();
        
        return line;
    }
        
    MorseNode* rotateRight(MorseNode* root) {
		// 1. insert node in right with old root values
		MorseNode* newRight = new MorseNode(root->character, root->morse);
		newRight->right = (root->right);
		root->right = (newRight);
		
		// 2. set root value to values of left
		MorseNode* toDelete = root->left; 
		root->character = (toDelete->character);
        root->morse = (toDelete->morse);
		
		// 3. delete (now duplicated) left, storing away LR child
		MorseNode* toDelete_left = toDelete->left;
		MorseNode* toDelete_right = toDelete->right;
		root->left = toDelete_left;
            // calculate new left's height
        root->left->setHeight();
		
		// 4. update new right node with LR child
		newRight->left = toDelete_right;		
			// calculate new right's height
		newRight->setHeight();
								
		// Return the new root
		return root;
    }
    
    MorseNode* rotateLeft(MorseNode* root) {
        // 1. insert node in left with old root values
		MorseNode* newLeft = new MorseNode(root->character, root->morse);
		newLeft->left = (root->left);
		root->left = (newLeft);
		
		// 2. set root value to values of right
		MorseNode* toDelete = root->right;
		root->character = (toDelete->character);
        root->morse = (toDelete->morse);
		
		// 3. delete (now duplicated) right, storing away RL child
        MorseNode* toDelete_right = toDelete->right;
		MorseNode* toDelete_left = toDelete->left;
		root->right = toDelete_right;
            // calculate new right's height
        root->right->setHeight();
		
		// 4. update new left node with RL child
		newLeft->right = toDelete_left;	
			// calculate new left's height
		newLeft->setHeight();
								
		// Return the new root
		return root;
    }
    
    void balance(MorseNode* root) {
        MorseNode* left = root->left;
		MorseNode* right = root->right;
		
		int left_height = (left) ? left->height : -1;
        int LL_height = (left && left->left) ? left->left->height : -1;
	    int LR_height = (left && left->right) ? left->right->height : -1;
		
    	int right_height = (right) ? right->height : -1;
		int RL_height = (right && right->left) ? right->left->height : -1;
		int RR_height = (right && right->right) ? right->right->height : -1;
    			
		if(left_height > right_height) {
			if(LR_height > LL_height) { // LR ROTATION				
				rotateLeft(left);
				rotateRight(root);
			} else {
				rotateRight(root);
			}
		} else if(right_height > left_height) {
			if(RL_height > RR_height) { // RL ROTATION	
				rotateRight(right);
				rotateLeft(root);
			} else {
				rotateLeft(root);
			}
		}
    };
    
    void setHeight(MorseNode* node) {
        bool balanced = node->setHeight();
        if(!balanced) {
            balance(node);
        }
    }
    
    
    void insert(string englishCharacter, string morse){
        if(_root == nullptr) {
            MorseNode* newNode = new MorseNode(englishCharacter, morse);
             _root = newNode;
            _root->depth = 0;
            _root->height = 0;
            return;
        }
        insertHelper(englishCharacter, morse, _root);
    }
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