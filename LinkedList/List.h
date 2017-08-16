//
// Created by Iqbal Khan on 8/9/17.
//

#ifndef LINKEDLISTS_LIST_H
#define LINKEDLISTS_LIST_H

#include <utility>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>
#include <set>

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
    bool isPalindrome();
    void detectCircularPoint();
    T getKElementFromEnd(int );
    void removeDuplicates();


private:
    struct Node{
        Node *next;
        T data;
    };

    Node *tail;
    Node *head;
    int size;
};

///Function to return whether a list is a palindrome

template <typename T>
bool List<T>::isPalindrome() {

    bool isPalindrome = true;
    stack<T> myStack;
    //To check the size of the list
    int remainder = size % 2;

    //Assuming that if the size is <= 1, it is a plaindrome
    if(size <= 1){
        return isPalindrome;
    }

    else{
        //Starting at head
        Node *curr = head;

        //Push half the list on to the stack
        for (int i = 0 ; i < (size/2); ++i){
            myStack.push(curr->data);
            curr = curr->next;
        }

        //If the size of the list was odd,
        if (remainder != 0){

            //skip the middle element
            curr = curr->next;
        }

        //While end of list is not reached
        while(curr != nullptr){
            //Start popping items from the stack
            T dataOnStack = myStack.top();
            myStack.pop();

            //And compare with the item on the list
            if (curr->data != dataOnStack){

                //If item on list and stack do not match,
                //the list wasn't a palindrome.
                isPalindrome = false;
                return isPalindrome;

            }

            else{
                curr = curr->next;
            }

        }

    }

    return isPalindrome;
}

/// Function to print the data of the node in the list
/// that is problem node in a circular list.
/// @tparam T
/// @return

template <typename T>
void List<T>::detectCircularPoint() {

    set<T> currSet;
    pair<typename set<T>::iterator, bool> ret;

    Node *curr = head;

    while (curr != nullptr){

        T currData = curr->data;
        ret = currSet.insert(currData);
        if (!ret.second){
            cout <<"Circular node is with data: " << curr->data << endl;
            break;
        }
        else{

            curr = curr->next;

        }

    }

}

/*
 * CCI get K element from end
 * */

/// Function to return Kth element from the of list
/// @param k: the position of the element to return
/// @return : the data present at position k.

template <typename T>
T List<T>::getKElementFromEnd(int k) {

    int target = size - k;
    Node *temp = head;
    for (size_t i = 0; i < target; ++i){
        temp = temp->next;
    }

    return temp->data;

}

/*
CCI linked list problem: remove duplicates
from the linked list without using a buffer
*/

template <typename T>
void List<T>::removeDuplicates(){

    //Set to hold current values
    set<T> currSet;

    //Pair to check if value
    // already exists in set
    pair<typename set<T>::iterator, bool> ret;

    Node *curr = head->next;
    Node *prev = head;
    currSet.insert(prev->data);
    while (curr != nullptr){

        ret = currSet.insert(curr->data);

        //If a duplicate is found
        if (!ret.second){

            prev->next = curr->next;
            delete curr;
            curr = nullptr;
            curr = prev->next;

        }
            //If no duplicate found
        else{
            //Move ahead
            curr = curr->next;
            prev = prev->next;
        }

    }

}

///
///  Function that inserts data at position n
/// @param n : Position to insert in
/// @param data : Data to be inserted


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

#endif //LINKEDLISTS_LIST_H
