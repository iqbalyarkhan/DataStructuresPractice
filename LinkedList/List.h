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
    void insertAtEnd(T d);
    void insertAtStart(T d);
    void insertAtPosition(int n, T data);
    void display();
    void deleteFirstNode();
    void deleteLastNode();
    void deleteAtPosition(int n);
    int count();
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
void List<T>::insertAtPosition(int n, T data) {
    if (n == 0){
        insertAtStart(data);
    }

    else if (n == size){
        insertAtEnd(data);
    }

    else{
        Node *newNode = new Node;
        newNode->data = data;
        Node *temp = head;
        for (int i = 1; i < n; ++i){
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        size++;

    }
}


template <typename T>
void List<T>::deleteAtPosition(int n) {

    if (n > size || n < 1){
        throw invalid_argument( "Position does not exist" );
        return;
    }

    else if (n == size){
        deleteLastNode();
        size--;
    }

    else if (n == 1){
        deleteFirstNode();
        size--;
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
        size--;

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

        temp1->next = tail->next;
        delete tail;
        tail = temp1;
        size--;

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
void List<T>::insertAtEnd(T d) {

    Node *temp = new Node;
    temp->next = nullptr;
    temp->data = d;
    tail->next = temp;
    tail = temp;
    size++;

}


template <typename T>
List<T>::List(){
    tail = nullptr;
    head = nullptr;
    size = 0;
}

template <typename T>
int List<T>::count(){
    return size;
}

template <typename T>
void List<T>::insertAtStart(T d) {

    if (size == 0){

        Node *A = new Node;
        A->data = d;
        head = A;
        tail = A;
        A->next = nullptr;
        size++;

    }

    else{

        Node *temp = new Node;
        temp->data = d;
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
