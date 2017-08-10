#include <iostream>
#include "List.h"

int main() {

  List<int> *l = new List<int>();
  l->insertAtStart(5);
  l->insertAtStart(4);
  l->insertAtStart(3);
  l->insertAtStart(2);
  l->insertAtStart(1);
  l->display();
  cout << "Deleting last node: " << endl;
  l->deleteLastNode();
  cout << "After deleting last node, tail points to: " << endl;
  cout << l->returnTailData() << endl;
  cout << "And new list is: " << endl;
  l->display();


    return 0;
}
