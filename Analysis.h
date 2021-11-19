#include "tree.h"

class DataAnalysis {
    AVLTree* treePurchased;
    AVLTree* treeSold;
    ifstream csvStream;
    
    void openFile() {
        csvStream.open("data.csv");
    };
    void readLines() {
        cout << endl;
        string line = "";
        getline(csvStream,line);// discard first line
        while(getline(csvStream,line)) {
            makeComparison(line);
        }
        
        cout << endl;
        cout << "Purchased: "; treePurchased->printInorder();
        cout << endl;
        cout << "Sold: "; treeSold->printInorder();
        cout << endl;
        csvStream.close();
    };
    void makeComparison(string line) {
        istringstream lineStream(line);
                
        string unitsString;
        getline(lineStream, unitsString, ',');
        int units = stoi(unitsString);
        // cout << units << " | ";
        
        string type;
        getline(lineStream, type, ',');
        // cout << type << " | ";
        
        string transaction;
        getline(lineStream, transaction, ',');
        // cout << transaction << endl;
        
        if (transaction.find("Purchased") != string::npos) {
            treePurchased->insert(type, units);
        }   
        else if(transaction.find("Sold") != string::npos) {
            treeSold->insert(type, units);
        }
        
    }
    
    public:
    void runAnalysis() {
        treePurchased = new AVLTree;
        treeSold = new AVLTree;
        
        openFile();
        readLines();
        
        TransactionNode* largestSold = treeSold->findLargest();
        TransactionNode* smallestSold = treeSold->findSmallest();
        TransactionNode* largestPurchased = treePurchased->findLargest();
        TransactionNode* smallestPurchased = treePurchased->findSmallest();
        
        cout << "Largest Sold: " << largestSold->getUnits() << "|" << largestSold->getData() << endl;
        cout << "Smallest Sold: " << smallestSold->getUnits() << "|" << smallestSold->getData() << endl;
        cout << endl;
        cout << "Largest Purchased: " << largestPurchased->getUnits() << "|" << largestPurchased->getData() << endl;
        cout << "Smallest Purchased: " << smallestPurchased->getUnits() << "|" << smallestPurchased->getData() << endl;
        
        cout << endl;
    }
};