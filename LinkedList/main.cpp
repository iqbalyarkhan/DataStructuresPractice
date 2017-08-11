#include <iostream>
#include "List.h"

int main() {

    List<int> *l = new List<int>();
    l->insertAtStart(4);
    l->insertAtEnd(8);
    l->insertAtStart(3);
    l->insertAtStart(6);
    l->insertAtStart(9);
    l->insertAtStart(12);
    l->insertAtStart(5);
    cout << "Insert at position 0: 1" << endl;
    l->insertAtPosition(0,1);
    cout <<"Insert at position 1: 100" << endl;
    l->insertAtPosition(1, 100);
    l->display();
    cout << "size is "<<l->count() << endl;
    cout <<"After deleting first node: " << endl;
    l->deleteFirstNode();
    l->display();
    cout <<"Deleting last node: " << endl;
    l->deleteLastNode();
    l->display();
    cout << "New size is " << l->count() << endl;
    cout << "deleting at position 4: " << endl;
    l->deleteAtPosition(4);
    l->display();
    cout << "Total count after all operations: " << endl;
    cout << l->count() << endl;

    return 0;
}
