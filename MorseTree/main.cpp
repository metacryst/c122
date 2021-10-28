#include "tree.h"

int main() {
    MorseTree* tree = new MorseTree();    
    
    tree->printInorder();
    tree->printPreorder();
    tree->printDiagram();
    
    string convertedString = tree->convert("Convert.txt");
}