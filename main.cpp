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
    cout << "Tail points to data: " << l->returnTailData() << endl;



    return 0;
}
