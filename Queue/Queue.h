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
    void dequeue();
    T peek();
    bool isEmpty();
    int count();
    void print();
    ~Queue();

private:

    struct Node{

        Node *next;
        T data;

    };

    Node *head;
    int size;


};

/**
 * Function to print items in queue
 */

template <typename T>
void Queue<T>::print() {
    Node *temp = head;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

/**
 * Function to return count of items in queue
 * @return - size of the queue
 */
template <typename T>
int Queue<T>::count() {
    return size;
}

/**
 * To check if queue is empty
 * @return - returns true if list is empty
 */
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

/**
 * Function to peek at item at head of queue
 * @return T - item at the front of the queue
 */
template <typename T>
T Queue<T>::peek() {
    return head->data;
}

/**
 * Function to remove items from the list
 * 
 */
template <typename T>
void Queue<T>::dequeue() {

    Node *temp = head;
    head = head->next;
    delete temp;
    temp = nullptr;
    size--;

}

/*
 * Adds data to the queue
 * @param data - data to be added to the queue 
 */

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

/**
 *
 * Constructor
 */
template <typename T>
Queue<T>::Queue() {
    head = nullptr;
    size = 0;
}

/*
 * Destructor to free allocated memory by calling
 * remove method
 */
template <typename T>
Queue<T>::~Queue() {

    while (head != nullptr){

        cout <<"removing " << head->data << endl;
        dequeue();

    }

}

#endif //QUEUE_QUEUE_H
