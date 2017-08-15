//
// Created by Iqbal Khan on 8/13/17.
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

private:
    struct Node{
        Node *next;
        T data;
    };

    Node *head;
    int size;

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
        temp->next = nullptr;
        head = temp;
    }

    else{

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
