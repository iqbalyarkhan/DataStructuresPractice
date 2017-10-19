//
// Created by Iqbal Khan on 8/14/17.
//

#ifndef STACKCLASS_STACK_H
#define STACKCLASS_STACK_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    void push(T data);
    T pop();
    T peek();
    bool isEmpty();
    int count();
    void print();
    T getMin();
    void setMin(T data);


private:
    struct Node{
        Node *next;
        T data;
    };

    Node *head;
    int size;
    int min;

};

/**
 * Function to print elements of stack starting from head
 */
template <typename T>
void Stack<T>::print() {
    Node *curr = head;
    while (curr != nullptr){
        cout << curr->data <<" ";
        curr = curr->next;
    }

    cout << endl;

}

/**
 * Function to set the minimum value of the stack
 * @param data - data to be set as minimum
 */
template <typename T>
void Stack<T>::setMin(T data) {

    if (data < min){
        min = data;
    }

}

/**
 * Function to get the minimum value from stack
 * @return T - the minimum value on stack
 */
template <typename T>
T Stack<T>::getMin() {

    return min;
}

/**
 * To keep track of size of stack
 * @return - the size of stack
 */
template <typename T>
int Stack<T>::count() {
    return size;
}

/**
 * To check whether stack is empty
 * @return - True if stack is empty, else false
 */
template <typename T>
bool Stack<T>::isEmpty() {
    if (size == 0){
        return true;
    }

    else{
        return false;
    }
}

/**
 * To check the value on top of stack
 * @return - Returns the peeked value
 */
template <typename T>
T Stack<T>::peek() {
    return head->data;
}

/**
 * To pop a value from top of stack
 * @return - Popped the value from top of stack
 */
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

/**
 * Function to push items on stack
 * @param data: Item pushed on stack
 */
template <typename T>
void Stack<T>::push(T data) {

    Node *temp = new Node;
    temp->data = data;
    if (size == 0){
        min = data;
        temp->next = nullptr;
        head = temp;

    }

    else{

        setMin(data);
        temp->next = head;
        head = temp;
    }

    size++;

}

/**
 * Constructor
 */
template <typename T>
Stack<T>::Stack(){

    head = nullptr;
    size = 0;
}


/**
 * Destructor
 */
template <typename T>
Stack<T>::~Stack() {

    while (head != nullptr){
        pop();

    }
}

#endif //STACKCLASS_STACK_H
