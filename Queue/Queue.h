//
// Created by Iqbal Khan on 8/15/17.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#include <stdio.h>
#include <iostream>

using namespace std;


template <typename T>
class Queue{

public:
    Queue();
    void add(T data);
    void remove();
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
void Queue<T>::print() {
    Node *temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

template <typename T>
int Queue<T>::count() {
    return size;
}

template <typename T>
bool Queue<T>::isEmpty() {
    bool empty;
    if (size == 0){
        empty = true;
        return empty;
    }

    else{
        empty = false;
        return empty;

    }

}

//Returns the item in
//front of the queue.
template <typename T>
T Queue<T>::peek() {
    return head->data;
}

//Removes the first item from the list.
template <typename T>
void Queue<T>::remove() {

    Node *temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    size--;

}

template <typename T>
void Queue<T>::add(T data) {

    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;

    if (size == 0){

        head = temp;

    }

    else{

        temp->next = head;
        head = temp;

    }

    size++;

}

template <typename T>
Queue<T>::Queue() {
    head = nullptr;
    size = 0;
}

#endif //QUEUE_QUEUE_H
