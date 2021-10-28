#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iterator>
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
    
    void destroyMorseTree(MorseNode* node) {
        if(!node->left && !node->right) {
            delete(node);
        } else if(node->left) {
            destroyMorseTree(node->left);
            node->left = nullptr;
        } else if(node->right) {
            destroyMorseTree(node->right);
            node->right = nullptr;
        }
    }
    ~MorseTree() {
        destroyMorseTree(_root);
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
        
        string morseMessage = "";
        
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
                        // cout << "Found morse: " << morseMatch << endl;
                        morseMessage += morseMatch;
                        morseMessage += " ";
                    } else {
                        // cout << "No morse found: " << englishCharacter << endl;
                    }
                    englishWord.erase(0,1);
                }
                // cout << "Printing spaces" << endl;
                morseMessage += "   ";
            }
        }
        convertFile.close();
        
        cout << endl;
        cout << "Here is your message: " << endl;
        cout << morseMessage << endl;
        
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
    
    void printDiagram() { // for a balanced tree
        if(_root==nullptr) return;
        printDiagramHelper(_root);}
    void printDiagramHelper(MorseNode* node) {
        if(node==nullptr) return;
            
        // get width of terminal
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int winWidth = w.ws_col;
        int winHeight = w.ws_row;
        
        // create list, initialize with spaces
        MorseNode** treeRow = new MorseNode*[winWidth];
        for(int i=0; i<(winWidth); i++) {
            treeRow[i] = nullptr;
        }
        MorseNode** nextRow = new MorseNode*[winWidth];
        for(int i=0; i<(winWidth); i++) {
            nextRow[i] = nullptr;
        }
        
        // insert root into first row (division is rounded down)
        int rootPos = winWidth%2==0 ? (winWidth/2) : (winWidth/2)-1;
        treeRow[rootPos] = _root; // find middle of terminal
        
        // print Tree
        int linesPrinted = 0;
        int leftDistance = rootPos;
        while(linesPrinted<winHeight && leftDistance>=1) {
            cout << "In while loop? " << linesPrinted << winHeight << endl;
            for(int i=0; i<(winWidth); i++) { // Print, check for nodes to grab children of
                cout << (treeRow[i] ? treeRow[i]->character : " ");
            }
            
            // travel across row, putting nodes in their positions
            // so, for filled row 3 of tree, there should be 4 iterations because there are 4 nodes
            for(int i=0; i<=winWidth; i+=leftDistance) { // travel across row, looking for nodes in their natural positions
                if(treeRow[i]) {
                    if(treeRow[i]->left) {
                        nextRow[i-leftDistance/2] = treeRow[i]->left;
                    }
                    if(treeRow[i]->right) {
                        nextRow[i+leftDistance/2] = treeRow[i]->right;
                    }
                }
            } 
            
            for(int i=0; i<(winWidth); i++) { // Set row to next row
                treeRow[i] = nextRow[i];
                nextRow[i] = nullptr;
            }
            leftDistance/=2;
            linesPrinted++;
        }
        
        

        delete[] treeRow;
        delete[] nextRow;
        
        
        
        
        // cout << node->character << " " << node->depth << " " << node->height << endl;
        // if(node->left) {
        //     cout << "/" << endl;
        //     printDiagramHelper(node->left);
        // }
        // if(node->right) {
        //    cout << "\\" << endl;;
        //    printDiagramHelper(node->right);
        // }
    }
};