//
<<<<<<< HEAD
// Created by Iqbal Khan on 8/13/17.
=======
// Created by Iqbal Khan on 8/14/17.
>>>>>>> stack
//

#ifndef STACKCLASS_STACK_H
#define STACKCLASS_STACK_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    int count();
    void print();
<<<<<<< HEAD
=======
    T getMin();
    void setMin(T data);
>>>>>>> stack

private:
    struct Node{
        Node *next;
        T data;
    };

    Node *head;
    int size;
<<<<<<< HEAD
=======
    int min;
>>>>>>> stack

};

template <typename T>
void Stack<T>::print() {
    Node *curr = head;
    while (curr != nullptr){
        cout << curr->data <<" ";
        curr = curr->next;
    }

    cout << endl;

}

template <typename T>
<<<<<<< HEAD
=======
void Stack<T>::setMin(T data) {

    if (data < min){
        min = data;
    }

}

template <typename T>
T Stack<T>::getMin() {

    return min;
}

template <typename T>
>>>>>>> stack
int Stack<T>::count() {
    return size;
}

template <typename T>
bool Stack<T>::isEmpty() {
    if (size == 0){
        return true;
    }

    else{
        return false;
    }
}

template <typename T>
T Stack<T>::peek() {
    return head->data;
}

template <typename T>
T Stack<T>::pop() {
    if (size <= 0){

        cout << "No more items left to pop" << endl;
        exit;

    }
    Node *temp = head;
    T poppedItem = temp->data;
    head = head->next;
    delete temp;
    temp = nullptr;
    size--;
    return poppedItem;

}

template <typename T>
void Stack<T>::push(T data) {

    Node *temp = new Node;
    temp->data = data;
    if (size == 0){
<<<<<<< HEAD
=======
        min = data;
>>>>>>> stack
        temp->next = nullptr;
        head = temp;
    }

    else{

<<<<<<< HEAD
=======
        setMin(data);
>>>>>>> stack
        temp->next = head;
        head = temp;
    }

    size++;

}


template <typename T>
Stack<T>::Stack(){

    head = nullptr;
    size = 0;

}

#endif //STACKCLASS_STACK_H
