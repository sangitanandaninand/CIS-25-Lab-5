#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

// Inserts a new node with the given value at the front of the list.
// Returns a pointer to the new head.
Node* push_front(Node* head, int value) {
    Node* node = new Node;
    node->value = value;
    node->next  = head;
    return node;
}

// Removes the first node in the list and returns the new head.
// If the list is empty, returns nullptr.
Node* remove_head(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* oldHead = head;
    head = head->next;
    delete oldHead;
    return head;
}

// Prints every value in the list on one line, separated by spaces.
void print_list(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->value << " ";
    }
    cout << endl;
}

// Part 2: Count the nodes in the list
int count_nodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Part 4: Find a value in the list
bool contains(Node* head, int target) {
    Node* current = head;
    while (current != nullptr) {
        if (current->value == target) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;
    // Part 1: Build and print a list
    head = push_front(head, 50);
    head = push_front(head, 40);
    head = push_front(head, 30);
    head = push_front(head, 20);
    head = push_front(head, 10);
    print_list(head);

    // Part 2: Count the nodes
    int node_count = count_nodes(head);
    cout << "Count: " << node_count << endl;

    // Part 3: Remove the first two nodes
    head = remove_head(head);
    print_list(head);

    head = remove_head(head);
    print_list(head);

    // Count again after removals
    node_count = count_nodes(head);
    cout << "Count: " << node_count << endl;

    // Part 4: Test the contains function
    bool result1 = contains(head, 40);
    cout << "Contains 40? " << result1 << endl;

    bool result2 = contains(head, 99);
    cout << "Contains 99? " << result2 << endl;

    // Clean up memory
    while (head != nullptr) {
        head = remove_head(head);
    }

    return 0;
}
