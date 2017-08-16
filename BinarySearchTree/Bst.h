//
// Created by Iqbal Khan on 8/15/17.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//Struct node to hold particular node's information
template <typename T>
struct Node{

    T data;
    Node *leftChild;
    Node *rightChild;

    //Constructior
    Node (T d) : data(d), leftChild(nullptr), rightChild(nullptr){}

};

template <typename T>
class Bst{

public:

    //Constructor
    Bst(){

        root = nullptr;

    }

    //Calling private insert method with root
    //and data to be inserted
    //data: data for new node
    void insert(T data){

        insert(root,data);

    }

    //Calling private print method
    void print(){

        print(root);
    }

    /*Various print methods:*/

    //pre
    void printPreOrder(){
        printPreOrder(root);
    }

    //in
    void printInOrder(){
        printInOrder(root);
    }

    //post
    void printPostOrder(){
        printPostOrder(root);
    }

private:

    //root to hold entry point for the tree
    Node<T> *root;

    //prints tree in Order
    void printInOrder(Node<T> *curr){

        if (curr == nullptr){
            return;
        }

        printInOrder(curr->leftChild);
        cout << curr->data << endl;
        printInOrder(curr->rightChild);


    }

    //prints tree in post order
    void printPostOrder(Node<T> *curr){

        if (curr == nullptr){
            return;
        }

        printPostOrder(curr->leftChild);
        printPostOrder(curr->rightChild);
        cout << curr->data << endl;


    }

    //prints tree in preOrder
    void printPreOrder(Node<T> *curr){

        if (curr == nullptr){
            return;
        }
        cout << curr->data << endl;
        printPreOrder(curr->leftChild);
        printPreOrder(curr->rightChild);



    }

    //Prints tree in sorted order
    //curr: root node
    void print(Node<T> *curr){

        //While empty leaf is not reached
        if (curr != nullptr){

            //Call print recursively starting from left most nodes
            print(curr->leftChild);
            cout << " " << curr->data << endl;
            print(curr->rightChild);
        }

    }

    //Insert method to add new node to tree
    //root: reference to root node
    //data: data to be inserted
    void insert(Node<T> *& root, T data){

        //If this is first node
        if (root == nullptr){

            //create new node and return
            root = new Node<T>(data);
            return;
        }

        //if condition below is true
            //call insert method with left child
        else if(data < root->data){
            insert (root->leftChild, data);
        }

        //if condition below is true
            //call insert with right child
        else if (data > root->data){
            insert (root->rightChild, data);
        }

            //Duplicate, do nothing
        else{}

    }

};

#endif //BINARYSEARCHTREE_BST_H
