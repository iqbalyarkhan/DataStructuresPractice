#include <iostream>
#include "List.h"

int main() {

    List<int> *l = new List<int>();
    l->insertAtStart(6);
    l->insertAtStart(5);
    l->insertAtStart(4);
    l->insertAtStart(3);
    l->insertAtStart(5);
    l->insertAtStart(5);
    l->insertAtEnd(6);

    cout << "Before duplicate deletion: " << endl;
    l->display();

    //removing duplicates
    l->removeDuplicates();
    cout << "After deletion of duplicates: " << endl;
    l->display();
    
    delete l;
    
    return 0;
}
