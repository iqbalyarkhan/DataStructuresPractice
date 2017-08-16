#include <iostream>
#include <stdio.h>
#include "Bst.h"


using namespace std;

int main() {
    Bst<int> *bst = new Bst<int>();
    bst->insert(8);
    bst->insert(10);
    bst->insert(4);
    bst->insert(13);
    bst->insert(9);
    bst->insert(5);
    bst->insert(2);

    bst->insertWithoutRecursion(16);

    //bst->print();
    cout << "Pre order: " << endl;
    bst->printPreOrder();
    cout << endl;

    cout << "In order: " << endl;
    bst->printInOrder();
    cout << endl;

    cout << "Post order: " << endl;
    bst->printPostOrder();
    cout << endl;

    return 0;
}