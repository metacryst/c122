#include "tree.h"

int main()
{
    system("clear");
    cout << "\033[1;91m--. --- .-. .. .-.. .-.. .-\033[m" << endl;
    
    MorseTree *tree = new MorseTree();

    // tree->printInorder();
    // tree->printPreorder();

    cout << endl;
    cout << endl;
    tree->printDiagram();
    
    // cout << endl;
    // cout << endl;
    // string convertedString = tree->convert("Convert.txt");
    
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    tree->readInput();
    cout << endl;
}