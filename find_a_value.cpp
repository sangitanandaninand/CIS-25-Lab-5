#include <iostream>

using namespace std;

//Definition of the Node structure
struct Node {
    struct Node {
        int value;
        Node* next;
    };

    //Function to create a new node
    Node* createNode(int value) {
        Node* newNode = new Node;
        newNode -> value = value;
        newNode -> next = nullptr;
        return newNode;
    }

    //Function to insert a node at the end of the list
    void insertEnd(Node* &head, int value) {
        Node* newNode = createNode(value);
        if (head == nullptr) {
            head = newNode;
        }else{
            Node* current = head;
            while (current -> next != nullptr) {
                current = current -> next;
            }
            current -> next = newNode;
        }
}

//Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current -> value << " ";
        current = current -> next;
    }
    cout << endl;
}

Function to count the number of nodes in a linked list
int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current -> next;
    }
    return count;
}

//Function to check if a value is carried in the list
bool findValue(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current -> value == target) {
            return true;
        }
        current = current -> next;
    }
    return false;
}

int main() {
    Node* head = nullptr;

    //Make a linked list with 5 nodes: 10 -> 20 -> 30 -> 40 -> 50 -> nullptr
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    insertEnd(head, 40);
    insertEnd(head, 50);

    //Print the linked list
    cout << "Linked List: ";
    printList(head); //Output: 10 20 30 40 50

    //Count the number of nodes in the linked list
    int nodeCount = countNodes(head);
    cout << "Count: " << nodeCount << endl;

    //Test the contains function
    int target1 = 40;
    bool containsTarget1 = contains(head,target1);
    cout << "Contains " << target1 <<"?" >> containsTarget1 << endl;

    int target2 = 99;
    bool containsTarget2 = contains(head,target2);
    cout << "Contains " << target2 <<"?" >> containsTarget2 << endl;

    //Clean up the assigned memory. This prevents memory leaks
    Node* current = head;
    while (current != nullptr) {
        Node* next = current -> next;
        delete current;
        current = next;
}
head = nullptr; //Make sure the head pointer is null after deleating all nodes
return 0;
} 