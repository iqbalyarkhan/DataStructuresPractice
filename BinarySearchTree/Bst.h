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
    
    int findHeight(){
        int height = findHeight(root);
        return height;
    }


    T findMinRecursively(){
        T min = findMinRecursively(root);
        return min;
    }

    T findMaxRecursively(){
        T max = findMaxRecursively(root);
        return max;
    }

    T findMin(){
        T min = findMin(root);
        return min;
    }


    T findMax(){
        T max = findMax(root);
        return max;
    }

    void insertWithoutRecursion(T data){

        insertWithoutRecursion(root,data);

    }

    
    //function to search whether data exists in tree
    bool search(T data){

        bool found = search(root, data);
        return found;

    }

    bool searchWithoutRecursion(T data){
        bool found = searchWithoutRecursion(root, data);
        return found;
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

    //Height = number of edges between the node and the root.
    int findHeight(Node<T> *curr){

        //Base case where the height of an empty tree is -1
        if (curr == nullptr){

            return -1;
        }

        int leftHeight = findHeight(curr->leftChild);
        int rightHeight = findHeight(curr->rightChild);

        if (leftHeight > rightHeight){

            int totalHeight = leftHeight;
            return (totalHeight + 1);
        }

        else{

            int totalHeight = rightHeight;
            return (totalHeight + 1);
        }


    }


     T findMinRecursively(Node<T>* curr){

        if (curr->leftChild == nullptr){
            return curr->data;
        }

        findMinRecursively(curr->leftChild);

    }

    T findMaxRecursively(Node<T>* curr){

        if (curr->rightChild == nullptr){
            return curr->data;
        }

        findMaxRecursively(curr->rightChild);

    }

    T findMin(Node<T> *curr){

        while (curr->leftChild != nullptr){
            curr = curr->leftChild;
            T currData = curr->data;
            int dummy = 0;
        }

        return curr->data;

    }

    T findMax(Node<T> *curr){

        while (curr->rightChild != nullptr){

            curr = curr->rightChild;
            T currData = curr->data;
            int dummy = 0;
        }

        return curr->data;

    }
    


    //Search method without recursion
    bool searchWithoutRecursion(Node<T> *curr, T data){

        if (curr == nullptr){
            return false;
        }

        while (curr != nullptr ){

            if (data < curr->data){
                curr = curr->leftChild;
            }

            else if (data == curr->data){

                return true;
            }

            else{

                curr = curr->rightChild;
            }

        }

        return false;

    }

    //Insert method witout using recursion
    void insertWithoutRecursion(Node<T> *curr, T data){

        Node<T> *temp = new Node<T>(data);

        if (curr == nullptr){
            root = temp;

        }

        else{

            Node<T> *parent = nullptr;

            while (curr != nullptr){

                parent = curr;

                if (data < curr->data ){
                    curr = curr->leftChild;
                }

                else if (data > curr->data){

                    curr = curr->rightChild;
                }

                else{
                    //duplicate, do nothing
                }

            }

            if (data < parent->data ){

                parent->leftChild = temp;

            }

            else{

                parent->rightChild = temp;
            }

        }
    }

    //Search with recursion
    bool search(Node<T>*curr, T data){

        if (curr == nullptr){
            return false;
        }

        if (curr->data == data){
            return true;
        }

        else if(data < curr->data){
            return search(curr->leftChild,data);
        }

        else {

            return search(curr->rightChild,data);

        }

    }

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
