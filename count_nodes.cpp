#include <iostream>

using namespace std;

//Definition of the Node structure
struct Node {
    int data;
    Node * next;
};

//Function to count the number of nodes in a linked list
int count_nodes(Node* head) {
    int count = 0; //Begin the counter to 0
    Node* current = head;//Intialize from the head of the list

    //Cross the list until the end is reached
    while (current != nullptr) {
        count++; //Increase the counter for each node 
        current = current -> next; //Move to the next node 
    }
    return count; //Return the total count of nodes
} 

int main () {
    //Create a linked list with 5 nodes
    Node* head = new Node;
    head -> data = 1;
    head -> next = new Node;
    head -> next = 2;
    head -> next -> next = Node;
    head -> next -> next -> = 3;
    head -> next -> next -> next -> = new Node;
      head -> next -> next -> next -> data = 4;
        head -> next -> next -> next -> next = new Node;
        head -> next -> next -> next -> next -> data = 5;
        head -> next -> next -> next -> next -> next = nullptr;

        
        //Call the count_nodes function to count the nodes
        int node_count = count_nodes(head);

        //Print the result
        cout << "Count:" << node_count << endl;

        //Clean up the assigned memory. It is optional but it is a good practice.
        Node* current = head;
        while (current != nullptr) {
            Node * next = current -> next;
            delete current;
            current = next; 
        }
        head = nullptr // Set head after freeing the memory

        return 0;
}