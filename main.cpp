#include <iostream>
#include "List.h"

int main() {

    List<int> *mylist = new List<int>;
    mylist->insertAtStart(5);
    mylist->display();
    mylist->insertAtStart(4);
    mylist->insertAtStart(3);
    mylist->display();

    return 0;
}
