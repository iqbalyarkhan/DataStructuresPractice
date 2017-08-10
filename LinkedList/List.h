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
void List<T>::delteAtPosition(int n) {

    if (n > size || n < 1){
        throw invalid_argument( "Position does not exist" );
        return;
    }

    else if (n == size){
        deleteLastNode();
    }

    else if (n == 1){
        deleteFirstNode();
    }

    else{
        Node *temp = head;
        for (int i = 1; i < n; ++i){
            temp = temp->next;
        }

        Node *deleteThis = temp->next;
        temp->next = deleteThis->next;
        delete deleteThis;
        deleteThis = nullptr;
    }
}

template <typename T>
void List<T>::deleteLastNode(){

    if (size == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
    }

    else{
        Node *temp1 = head;
        for (int i = 0; i < size-2; ++i){
            temp1 = temp1->next;

        }

        Node *oldTail = tail;
        temp1->next = tail->next;
        delete oldTail;
        tail = temp1;
    }
}

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
