#include <iostream>
#include <stdio.h>
#include "Bst.h"
#include <queue>

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
    bst->insert(16);

    //cout << "min is: " << bst->findMin() << endl;
    //cout << "max is: " << bst->findMax() << endl;
    //cout << "height is: " << bst->findHeight() << endl;

    bst->breadthFirstTraversal();

    /*bool found = bst->searchWithoutRecursion(8);
    cout <<"found 8?: " << found << endl;*/

    /*
    bst->print();
    cout << "Pre order: " << endl;
    bst->printPreOrder();
    cout << endl;

    cout << "In order: " << endl;
    bst->printInOrder();
    cout << endl;

    cout << "Post order: " << endl;
    bst->printPostOrder();
    cout << endl;

    //cout << "Is 10 in the tree?: " << bst->search(10) << endl;
    //cout << "Is 14 in the tree?: " << bst->searchWithoutRecursion(14) << endl;*/
    delete bst;
    return 0;
}
