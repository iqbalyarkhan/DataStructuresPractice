//
// Created by Iqbal Khan on 8/15/17.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <queue>

using namespace std;

//Struct node to hold particular node's information
template <typename T>
struct Node{

    T data;
    Node *leftChild;
    Node *rightChild;

    //Constructor
    Node (T d) : data(d), leftChild(nullptr), rightChild(nullptr){}

};

template <typename T>
class Bst{

public:

    //Constructor
    Bst(){

        root = nullptr;

    }

     /**
     * Helper function to delete a node from the tree
     * @param data - node to delete that holds data
     */
    void deleteNode(T data){

        deleteNode(root, data);

    }

    
    /**
     * Helper function to check whether given tree
     * is a BST
     * @return true if tree is a BST
     */
    bool isBinarySearchTree(){

        bool isBinary = isBinarySearchTree(root);
        return isBinary;

    }


    /**
     * Helper function that calls private function
     * to traverse the tree breadth first
     */

    void breadthFirstTraversal(){
        queue<T> unVisited;
        breadthFirstTraversal(root);

    }

    /**
     * Helper function to call private function
     * @return height of the tree
     */
    int findHeight(){
        int height = findHeight(root);
        return height;
    }

    /**
     * Helper function that calls private function to insert
     * data in tree without using recursion
     * @param data to be inserted
     *
     */
    void insertWithoutRecursion(T data){

        insertWithoutRecursion(root,data);

    }

    /**
     * Helper function that calls private function to find minimum
     * value in the tree using recursion
     * @return minimum value in the tree
     */
    T findMinRecursively(){
        T min = findMinRecursively(root);
        return min;
    }

    /**
    * Helper function that calls private function to find maximum
    * value in the tree using recursion
    * @return maximum value in the tree
    */
    T findMaxRecursively(){
        T max = findMaxRecursively(root);
        return max;
    }

    /**
     * Helper function that calls private function to find minimum
     * value in the tree iteratively
     * @return minimum value in the tree
     */
    T findMin(){
        T min = findMin(root);
        return min;
    }

    /**
    * Helper function that calls private function to find maximum
    * value in the tree iteratively
    * @return minimum value in the tree
    */
    T findMax(){
        T max = findMax(root);
        return max;
    }

    /**
    * Helper function that calls private function to find
    * value in the tree recursively
    *@param data to find
    *@return true if value found, false otherwise
    */
    bool search(T data){

        bool found = search(root, data);
        return found;

    }

    /**
   * Helper function that calls private function to find
   * value in the tree recursively
   *@param data to find
   *@return true if value found, false otherwise
   */
    bool searchWithoutRecursion(T data){
        bool found = searchWithoutRecursion(root, data);
        return found;
    }

    /**
   * Helper function that calls private function to insert
   * value in the tree
   *@param data to insert
   */
    void insert(T data){

        insert(root,data);

    }

    /**
   * Helper function that calls private function to print the tree
   */
    void print(){

        print(root);
    }

    /*Various print methods:*/

    /**
   * Helper function that calls private function to print tree
   * in pre-order
   */
    void printPreOrder(){
        printPreOrder(root);
    }

    /**
   * Helper function that calls private function to print tree
   * in order
   */
    void printInOrder(){
        printInOrder(root);
    }

    /**
   * Helper function that calls private function to print tree
   * in post-order
   */
    void printPostOrder(){
        printPostOrder(root);
    }

private:

    //root to hold entry point for the tree
    Node<T> *root;


/**
     * Function to delete a node from the tree
     * @param curr - root node of the tree
     * @param data - data to be deleted
     * @return - true if node deleted from tree, false otherwise
     */
    void deleteNode(Node<T>* curr, T data){

        bool left = false;
        bool right = false;

        Node<T> *prev = curr;

        //Node to be deleted is in the left subtree
        if (data < curr->data){

            curr = curr->leftChild;
            left = true;
        }

        //Node to be deleted is in the right subtree
        else if (data > curr->data) {

            curr = curr->rightChild;
            right = true;
        }

        //Node to be deleted is the root node
        else {

            //Go into the right subtree and find
            //the smallest element to make it the root.
            curr = curr->rightChild;
            while (curr->leftChild != nullptr){

                prev = curr;
                curr = curr->leftChild;

            }

            T newRootData = curr->data;
            delete curr;
            curr = nullptr;
            prev->leftChild = nullptr;
            root->data = newRootData;

        }

        while (curr != nullptr){

            if (data < curr->data){

                prev = curr;
                curr = curr->leftChild;
                left = true;
                right = false;

            }

            else if (data > curr->data){

                prev = curr;
                curr = curr->rightChild;
                right = true;
                left = false;

            }

            //Node to be deleted is found and is being pointed to by curr
            else {

                //If curr is right child of prev
                if (right){

                    //And curr is a leaf node
                    if (curr->leftChild == nullptr && curr->rightChild == nullptr){

                        delete curr;
                        curr = nullptr;
                        prev->rightChild = nullptr;
                    }

                    //Node to be deleted has a right child
                    else if (curr->rightChild != nullptr && curr->leftChild == nullptr){

                        prev->rightChild = curr->rightChild;
                        delete curr;
                        curr = nullptr;

                    }

                    //Node to be deleted has a left child
                    else if (curr->leftChild != nullptr && curr->rightChild == nullptr){

                        prev->rightChild = curr->leftChild;
                        delete curr;
                        curr = nullptr;

                    }

                    //Node to be deleted has both a left and a right child
                    else{

                        prev->rightChild = curr->rightChild;
                        prev->rightChild->leftChild = curr->leftChild;
                        delete curr;
                        curr = nullptr;

                    }

                }

                //If curr is left chlid of prev
                if (left){

                    //And curr is a leaf node
                    if (curr->leftChild == nullptr && curr->rightChild == nullptr){

                        delete curr;
                        curr = nullptr;
                        prev->leftChild = nullptr;
                    }

                        //Node to be deleted has a right child
                    else if (curr->rightChild != nullptr && curr->leftChild == nullptr){

                        prev->leftChild = curr->rightChild;
                        delete curr;
                        curr = nullptr;

                    }
                    //Node to be deleted has a left child
                    else if (curr->leftChild != nullptr && curr->rightChild == nullptr){

                        prev->leftChild = curr->leftChild;
                        delete curr;
                        curr = nullptr;

                    }

                    //Node to be deleted has both a left and a right child
                    else {

                        prev->leftChild = curr->rightChild;
                        prev->leftChild->leftChild = curr->leftChild;
                        delete curr;
                        curr = nullptr;

                    }

                }

            }



        }

    }



    /**
    * Function to find whether a tree is a BST
    * @param root - root of the tree and subsequent subtrees
    * @return true if tree is a BST, false otherwise
    */
    bool isBinarySearchTree(Node<T>* root)
    {
        // Base case
        if (root == nullptr)
            return true;

        // if left node exists check if
        // data in left node < root data
        if (root->leftChild != nullptr && root->data < root->leftChild->data)
            return false;

        // if right node exists check if
        // data in right node > root data
        if (root->rightChild != nullptr && root->data > root->rightChild->data)
            return false;

        // checking recursively for each subsequent node.
        return isBinarySearchTree(root->leftChild) &&
               isBinarySearchTree(root->rightChild);
    }

    /**
     * Traverses the tree in breadthFirst fashion,
     * printing out the values
     * @param root of the tree
     */
    void breadthFirstTraversal(Node<T>*root){

        if (root == nullptr){
            return;
        }

        queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()){


            Node<T> *curr = q.front();
            cout << curr->data << " ";

            if (curr->leftChild != nullptr){

                q.push(curr->leftChild);
            }

            if (curr->rightChild != nullptr){

                q.push(curr->rightChild);
            }

            q.pop();

        }



    }

    /**
     * Function to find the height of the tree
     * @param curr - root of the tree
     * @return height of the tree
     */
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

    /**
     * Function to find the minimum value present in the tree
     * using recursive approach
     * @param curr - root of the tree
     * @return minimum value in the tree
     */
    T findMinRecursively(Node<T>* curr){

        if (curr->leftChild == nullptr){
            return curr->data;
        }

        findMinRecursively(curr->leftChild);

    }

    /**
     * Function to find the max value present in
     * the tree using recursive approach
     * @param curr - root of the tree
     * @return maximum value in the tree
     */
    T findMaxRecursively(Node<T>* curr){

        if (curr->rightChild == nullptr){
            return curr->data;
        }

        findMaxRecursively(curr->rightChild);

    }

    /**
     * Function to find minimum value in the tree using
     * iterative approach
     * @param curr - root of the tree
     * @return minimum value in the tree
     */
    T findMin(Node<T> *curr){

        while (curr->leftChild != nullptr){
            curr = curr->leftChild;
            T currData = curr->data;
            int dummy = 0;
        }

        return curr->data;

    }

    /**
     * Function to find the maximum value in the tree
     * using iterative approach
     * @param curr - root of the tree
     * @return maximum value in the tree
     */
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

    /**
     * Function to insert data in the tree iteratively
     * @param curr - root of the tree
     * @param data - data to be inserted
     */
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

    /**
     * Function to search for data recursively
     * @param curr - root of the tree
     * @param data - data to search for
     * @return true if data found, false otherwise
     */
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

    /**
     * Function to print tree in order
     * @param curr - root of the tree
     */
    void printInOrder(Node<T> *curr){

        if (curr == nullptr){
            return;
        }

        printInOrder(curr->leftChild);
        cout << curr->data << endl;
        printInOrder(curr->rightChild);


    }


    /**
     * Function to print tree in post-order
     * @param curr - root of the tree
     */
    void printPostOrder(Node<T> *curr){

        if (curr == nullptr){
            return;
        }

        printPostOrder(curr->leftChild);
        printPostOrder(curr->rightChild);
        cout << curr->data << endl;


    }

    /**
     * Function to print tree in pre-order
     * @param curr - root of the tree
     */
    void printPreOrder(Node<T> *curr){

        if (curr == nullptr){
            return;
        }
        cout << curr->data << endl;
        printPreOrder(curr->leftChild);
        printPreOrder(curr->rightChild);



    }

    /**
     * Function to print tree in sorted-order
     * @param curr - root of the tree
     */
    void print(Node<T> *curr){

        //While empty leaf is not reached
        if (curr != nullptr){

            //Call print recursively starting from left most nodes
            print(curr->leftChild);
            cout << " " << curr->data << endl;
            print(curr->rightChild);
        }

    }

    /**
     * Function to insert data in the tree
     * @param root - root of the tree
     * @param data - data to be inserted
     */
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
