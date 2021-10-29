#include "tree.h"

int main()
{
    MorseTree *tree = new MorseTree();

    tree->printInorder();
    tree->printPreorder();

    string convertedString = tree->convert("Convert.txt");

    // tree->printBasicDiagram();
}