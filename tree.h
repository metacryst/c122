#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iterator>
#include <termios.h>
using namespace std;

class Node {
    string data;
    string morse;
    Node* left;
    Node* right;
    int height;
    int depth;
    
    friend class AVLTree;
  public:
    Node(string _data) {
        data=_data;
        left=nullptr;
        right=nullptr;
    }
    virtual ~Node()=0;
    virtual void printData()=0;
    
    bool setHeight() {
        int rightHeight = right ? right->height : -1;
        int leftHeight = left ? left->height : -1;
        height = max(rightHeight, leftHeight) + 1;
        
        int balanceFactor = abs(rightHeight-leftHeight);
        return balanceFactor<=1 ? true : false;
    }
};

class TransactionNode: public Node {
    int units;
    
    friend class AVLTree;
  public:
    TransactionNode(string _data, int _units) : Node(_data) {
        this->units=_units;
    };
    ~TransactionNode();
    void printData();
};

class AVLTree{
    Node* _root;
    
  public:
    AVLTree() {
        _root=nullptr;
    }
    
    void destroyAVLTree(Node* node) {
        if(!node->left && !node->right) {
            delete(node);
        } else if(node->left) {
            destroyAVLTree(node->left);
            node->left = nullptr;
        } else if(node->right) {
            destroyAVLTree(node->right);
            node->right = nullptr;
        }
    }
    ~AVLTree() {
        destroyAVLTree(_root);
    }
    
    string search(string data) {
        if(_root->data == data) return _root->data;
        else return searchHelper(data, _root);
    }
    string searchHelper(string data, Node* node) {
        if(node==nullptr) return "";
        if(node->data == data) return node->morse;
        
        return (data < node->data) ? searchHelper(data, node->left) : searchHelper(data, node->right);
    }
        
    Node* rotateRight(Node* root) {
		// 1. insert in right with old root values
		Node* newRight = new TransactionNode(root->data, static_cast<TransactionNode*>(root)->units);
		newRight->right = (root->right);
		root->right = (newRight);
		
		// 2. set root value to values of left
		Node* toDelete = root->left; 
		root->data = (toDelete->data);
        root->morse = (toDelete->morse);
		
		// 3. delete (now duplicated) left, storing away LR child
		Node* toDelete_left = toDelete->left;
		Node* toDelete_right = toDelete->right;
		root->left = toDelete_left;
            // calculate new left's height
        if(root->left){root->left->setHeight();}
		
		// 4. update new right with LR child
		newRight->left = toDelete_right;		
			// calculate new right's height
		newRight->setHeight();
								
		// Return the new root
		return root;
    }
    
    Node* rotateLeft(Node* root) {
        // 1. insert in left with old root values
		Node* newLeft = new TransactionNode(root->data, static_cast<TransactionNode*>(root)->units);
		newLeft->left = (root->left);
		root->left = (newLeft);
		
		// 2. set root value to values of right
		Node* toDelete = root->right;
		root->data = (toDelete->data);
        root->morse = (toDelete->morse);
		
		// 3. delete (now duplicated) right, storing away RL child
        Node* toDelete_right = toDelete->right;
		Node* toDelete_left = toDelete->left;
		root->right = toDelete_right;
            // calculate new right's height
        if(root->right){root->right->setHeight();}
		
		// 4. update new left with RL child
		newLeft->right = toDelete_left;	
			// calculate new left's height
		newLeft->setHeight();
								
		// Return the new root
		return root;
    }
    
    void balance(Node* root) {
        Node* left = root->left;
		Node* right = root->right;
		
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
    
    void setHeight(Node* node) {
        bool balanced = node->setHeight();
        if(!balanced) {
            balance(node);
        }
    }
    
    
    void insert(string data, int units){
        if(_root == nullptr) {
            Node* newNode = new TransactionNode(data, units);
             _root = newNode;
            _root->depth = 0;
            _root->height = 0;
            return;
        }
        insertHelper(data, units, _root);
    }
    Node* insertHelper(string data, int units, Node* currentNode) {
        if(currentNode == nullptr) {
            Node* newNode = new TransactionNode(data, units);
            newNode->height = 0;
            return newNode;
        }
        
        if(units < static_cast<TransactionNode*>(currentNode)->units) {
            currentNode->left = insertHelper(data, units, currentNode->left);
            currentNode->left->depth = currentNode->depth + 1;
        } else if(units > static_cast<TransactionNode*>(currentNode)->units) {
            currentNode->right = insertHelper(data, units, currentNode->right);
            currentNode->right->depth = currentNode->depth + 1;
        }
        
        setHeight(currentNode);
        return currentNode;
    }
    
    void printPreorder() {
        if(_root==nullptr) {return;};
        printPreorderHelper(_root);
        cout << endl;}
    void printPreorderHelper(Node* node) {
        if(node==nullptr) {return;};
        cout << node->data << " ";
        printPreorderHelper(node->left);
        printPreorderHelper(node->right);
    }
    
    public: void printInorder() {
        if(_root==nullptr) {return;};
        printInorderHelper(_root);
        cout << endl;}
    private: void printInorderHelper(Node* node) {
        if(node==nullptr) {return;};
        printInorderHelper(node->left);
        cout << node->data << " ";
        printInorderHelper(node->right);
    }
    
    public: void printDiagram() { // for a balanced tree
        if(_root==nullptr) return;
        printDiagramHelper(_root);}
    private: void printDiagramHelper(Node* node) {
        if(node==nullptr) return;
            
        // get width of terminal
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        int winWidth = w.ws_col;
        int winHeight = w.ws_row;
        
        // create list, initialize with spaces
        Node** treeRow = new Node*[winWidth];
        for(int i=0; i<(winWidth); i++) {
            treeRow[i] = nullptr;
        }
        Node** nextRow = new Node*[winWidth];
        for(int i=0; i<(winWidth); i++) {
            nextRow[i] = nullptr;
        }
        
        // insert root into first row (division is rounded down)
        int rootPos = winWidth%2==0 ? (winWidth/2) : (winWidth/2)-1;
        treeRow[rootPos] = _root; // find middle of terminal
        
        // print Tree
        int linesPrinted = 0;
        int leftDistance = rootPos;
        while(linesPrinted<winHeight) {
            
            bool rowEmpty = true;
            for(int i=0; i<(winWidth); i++) { // Print, check for nodes to grab children of
                if(treeRow[i]) rowEmpty=false;
                if(i>leftDistance && i<(winWidth-leftDistance)) {
                    if(treeRow[i]) {
                        printf("\033[1;91m%s\033[m", treeRow[i]->data.c_str());
                    } else {
                        printf("_");
                    }
                } else {
                    if(treeRow[i]) {
                        printf("\033[0;91m%s\033[m", treeRow[i]->data.c_str());
                    } else {
                        printf(" ");
                    }
                }
            }
            if(rowEmpty) return;

            // travel across row, putting nodes in their positions
            for(int i=0; i<(winWidth); i++) { // travel across row, looking for nodes in their natural positions
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
        
        cout << endl;

        delete[] treeRow;
        delete[] nextRow;
        
        
        
    }
    
    public: void printBasicDiagram() { // for a balanced tree
        if(_root==nullptr) return;
        printBasicDiagramHelper(_root);}
    private: void printBasicDiagramHelper(Node* node) {
        cout << node->data << " " << node->depth << " " << node->height << endl;
        if(node->left) {
            cout << "/" << endl;
            printBasicDiagramHelper(node->left);
        }
        if(node->right) {
           cout << "\\" << endl;;
           printBasicDiagramHelper(node->right);
        }
    }
};