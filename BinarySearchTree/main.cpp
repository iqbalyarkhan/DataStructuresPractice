#include <iostream>
#include <stdio.h>
#include "Bst.h"

using namespace std;

int main() {
    Bst<int> *bst = new Bst<int>();
    bst->insert(5);
    bst->insert(10);
    bst->insert(4);
    bst->insert(13);
    bst->insert(2);
    bst->print();
    return 0;
}