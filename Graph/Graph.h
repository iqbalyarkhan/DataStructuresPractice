//
// Created by Iqbal Khan on 8/27/17.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <stdio.h>
#include <string>

using namespace std;

template <typename T>
class Graph{

private:
    template <typename T>
    struct AdjacencyListNode{

        T data;
        AdjacencyListNode* next;

    };
    template <typename T>
    struct AdjacencyList{

        AdjacencyListNode* head;

    };

    int numberOfVertices;
    AdjacencyList* arrayOfVertices;

public:
    /**
     * Constructor that initializes the list of
     * vertices with the number passed in by the user
     * @param num - number of vertices in the graph
     */
    Graph(int num):numberOfVertices(num){

        arrayOfVertices = new AdjacencyList[numberOfVertices];

        for (int i = 0; i < numberOfVertices; ++i){

            arrayOfVertices->head= nullptr;

        }


    }

};


#endif //GRAPHS_GRAPH_H
