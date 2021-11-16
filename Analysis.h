#include "tree.h"

class DataAnalysis {
    AVLTree treePurchased;
    AVLTree treeSold;
    ifstream csvStream;
    
    void openFile() {
        csvStream.open("data.csv");
    };
    void readLines() {
        // loop through file
        // call makeComparison
        // display inOrder traversa;
        string line = "";
        getline(csvStream,line);// discard first line
        while(getline(csvStream,line)) {
            makeComparison(line);
        }
        
        treePurchased.printInorder();
        treeSold.printInorder();
        csvStream.close();
    };
    void makeComparison(string line) {
        istringstream lineStream(line);
        
        string data;
        getline(lineStream, data, ",");
        getline(lineStream, data, ",");
        
        string transaction;
        getline(lineStream, transaction, ",");
        
    }
    
    public:
    void runAnalysis() {
        openFile();
        readLines();
    }
    DataAnalysis() {
        runAnalysis();
    }
};