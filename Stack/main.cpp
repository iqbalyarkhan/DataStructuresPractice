#include <iostream>
#include <stdio.h>
#include <string>
#include "Stack.h"

using namespace std;


int main() {

    Stack<int> *s = new Stack<int>();
    s->push(4);
    s->push(3);
    s->push(2);
    s->push(1);
    s->push(0);
    s->print();
    cout << "Peeking: " << s->peek() << endl;
    cout << "Pop: " << s->pop() << endl;
    cout << "Pop: " << s->pop() << endl;
    cout << "Pop: " << s->pop() << endl;
    cout << "Pop: " << s->pop() << endl;
    cout << "Pop: " << s->pop() << endl;
    cout << "Pop: " << s->pop() << endl;

    return 0;
}
