#include <iostream>
#include <stdio.h>
#include <string>
#include "Queue.h"

using namespace std;

int main() {

    Queue<int> *q = new Queue<int>();
    cout << "Size before init: " << q->count() << endl;

    q->add(9);
    q->add(8);
    q->add(7);
    q->add(6);
    q->add(5);
    q->add(4);
    q->add(3);
    q->add(2);
    q->add(1);

    cout <<"Printing all elements in queue: " << endl;
    q->print();
    cout << endl;
    cout << "New size is: " << q->count() << endl;

    q->remove();
    cout << "After removing, new queue is: " << endl;
    q->print();

    cout <<"Peeking at the front of queue: " << q->peek() << endl;

    return 0;
}