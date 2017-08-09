#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

struct Node{

    int data;
    Node *next;

};

/* This function takes in a reference to the
 head pointer and prints the data field of
 each of the links.
*/
void PrintElements(Node *&head){

    Node *temp = head;

    while (temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }

}

int main() {

    //Creating a head pointer
    Node *head = nullptr;

    //Populating sample nodes with sample data
    Node *A = new Node;
    A->data = 1;
    A->next = nullptr;

    Node *B = new Node;
    B->data = 2;
    B->next = nullptr;

    Node *C = new Node;
    C->data = 3;
    C->next = nullptr;

    //Creating the links between each node
    A->next = B;
    B->next = C;

    //Head pointer pointing to A
    head = A;

    PrintElements(head);

    return 0;
}
