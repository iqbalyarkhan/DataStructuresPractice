//
// Created by Iqbal Khan on 8/31/17.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Graph{

public:

    Graph(int num);
    void initializeVertexList();
    void printVertexInfo();





private:

    struct Node{

        Node* next;
        T data;
        Node* neighbors;

    };

    int numberOfVertices;
    Node* head;
};
template <typename T>
Graph<T>::Graph(int num): numberOfVertices(num), head(nullptr) {

    initializeVertexList();

}

/**
 * Function to initialize vertex list by asking the user
 * for input. List is ordered based on user input. Similar to
 * add to head functionality of linked lists.
 * @tparam T - Data inside the body is vertex information
 */

template <typename T>
void Graph<T>::initializeVertexList() {

    T data;
    cout << "Enter name or number of each vertex: " << endl;
    cin >> data;
    Node* temp = new Node;
    temp->next = nullptr;
    temp->neighbors = nullptr;
    temp->data = data;
    head = temp;
    Node* curr = head;
    cin.clear();
    for (int i = 1; i < numberOfVertices; ++i){

        cout << "Enter data for vertex: " << endl;
        cin >> data;
        Node* newNode = new Node;
        newNode->data =data;
        curr->next = newNode;
        curr->neighbors = nullptr;
        curr = curr->next;

    }

}

/**
 * Function to print the vertices only.
 * @tparam T - Data held by the vertex
 */

template <typename T>
void Graph<T>::printVertexInfo() {

    Node* curr = head;

    while (curr != nullptr){

        cout << curr->data <<" ";
        curr = curr->next;

    }

    cout << endl;

}

#endif //GRAPHS_GRAPH_H
