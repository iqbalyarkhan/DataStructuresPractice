//
// Created by Iqbal Khan on 8/9/17.
//

#ifndef LINKEDLISTCLASS_LIST_H
#define LINKEDLISTCLASS_LIST_H

#include <utility>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

template <typename T>
class List {

public:
    List();
    void insertAtEnd();
    void insertAtStart(T);
    void display();
    void deleteFirstNode();
    void deleteLastNode();
    void delteAtPosition();
    T count();


private:
    struct Node{
        Node *next;
        T data;
    };

    Node *tail;
    Node *head;
    int size;
};

#endif //LINKEDLISTCLASS_LIST_H

template <typename T>
List<T>::List(){
    tail = nullptr;
    head = nullptr;
    size = 0;
}

template <typename T>
T List<T>::count(){
    return size;
}

template <typename T>
void List<T>::insertAtStart(T data) {

    if (size == 0){

        Node *A = new Node;
        A->data = data;
        head = A;
        tail = A;

    }

}

template <typename T>
void List<T>::display() {

    Node *temp = head;
    while (temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }

}

