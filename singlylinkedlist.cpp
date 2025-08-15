#include <iostream>
using namespace std;

// Node structure for singly linked list
class Node {
public:
    int data;       // stores data
    Node* next;     // pointer to next node

    // Constructor to create a new node
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Insert a new node at the head of the list
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d); // create new node

    // If list is empty
    if (head == NULL) {
        head = temp;
    }
    else {
        temp->next = head; // link new node to old head
        head = temp;       // update head
    }
}

// Insert a new node at the tail of the list
void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d); // create new node

    // If list is empty
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }

    // Otherwise, attach at tail and update tail
    tail->next = temp;
    tail = temp;
}

// Insert a new node at a specific position (1-based index)
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    // Case 1: Insert at beginning
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the node just before the desired position
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    // Case 2: Insert at the end
    if (temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    // Case 3: Insert in the middle
    Node* node2insert = new Node(d);
    node2insert->next = temp->next;
    temp->next = node2insert;
}

//Delete at head
void deleteAtHead(Node* &head, Node* &tail)
{
    if(head==NULL)
    {
        return;
    }
    Node* temp =head;
    head=head->next;
    delete temp;

    // If list became empty after deletion
    if (head == NULL)
        tail = NULL;
}

// Print the linked list
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) { // traverse until NULL
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create first node
    Node* node1 = new Node(10);

    // Head and tail initially point to the same node
    Node* head = node1;
    Node* tail = node1;

    print(head); // prints: 10

    // Insert nodes at tail
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 13);
    print(head); // prints: 10 9 12 13

    // Insert node at position 2
    insertAtPosition(head, tail, 2, 111);
    print(head); // prints: 10 111 9 12 13

    // Print last node's data (tail)
    cout << "Tail data: " << tail->data << endl; // 13

    return 0;
}
