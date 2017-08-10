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
    T returnTailData();


private:
    struct Node{
        Node *next;
        T data;
    };

    Node *tail;
    Node *head;
    int size;
};

template <typename T>
void List<T>::deleteFirstNode(){

    if (size > 1){

        Node *temp = head;
        temp = head->next;
        delete head;
        head = temp;
        size--;
    }

    else{

        delete head;
        head = nullptr;
        tail = nullptr;
        size--;

    }

}

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
        A->next = nullptr;
        size++;

    }

    else{

        Node *temp = new Node;
        temp->data = data;
        temp->next = head;
        head = temp;
        size++;

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

template<typename T>
T List<T>::returnTailData() {

    return tail->data;

}

#endif //LINKEDLISTCLASS_LIST_H
