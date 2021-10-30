#include "tree.h"

int main()
{
    MorseTree *tree = new MorseTree();

    tree->printInorder();
    tree->printPreorder();

    cout << endl;
    cout << endl;
    tree->printDiagram();
    
    cout << endl;
    cout << endl;
    string convertedString = tree->convert("Convert.txt");
}