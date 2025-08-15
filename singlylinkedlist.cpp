#include <iostream>
using namespace std;

// Node structure for singly linked list
class Node {
public:
    int data;       // stores the value
    Node* next;     // pointer to the next node

    // Constructor to initialize a new node
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

//////////////////// INSERT FUNCTIONS ////////////////////

// Insert a new node at the head (beginning) of the list
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d); // create new node

    if (head == NULL) { // if list is empty
        head = temp;
    } else {
        temp->next = head; // new node points to old head
        head = temp;       // update head pointer
    }
}

// Insert a new node at the tail (end) of the list
void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* temp = new Node(d); // create new node

    if (head == NULL) { // if list is empty
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp; // link old tail to new node
    tail = temp;       // update tail pointer
}

// Insert a node at a specific position (1-based index)
void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    // Case 1: insert at head
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    // move temp to the node before the desired position
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Case 2: insert at end if position is last
    if (temp->next == NULL) {
        insertAtTail(head, tail, d);
        return;
    }

    // Case 3: insert in middle
    Node* node2insert = new Node(d);
    node2insert->next = temp->next;
    temp->next = node2insert;
}

//////////////////// DELETE FUNCTIONS ////////////////////

// Delete node at head
void deleteAtHead(Node* &head, Node* &tail) {
    if (head == NULL) // empty list
        return;

    Node* temp = head;    // store current head
    head = head->next;    // move head to next node
    delete temp;          // free old head

    if (head == NULL)     // if list becomes empty
        tail = NULL;
}

// Delete node at tail
void deleteAtTail(Node* &head, Node* &tail) {
    if (head == NULL) // empty list
        return;

    if (head == tail) { // only one node
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    // find the second last node
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;       // delete last node
    temp->next = NULL; // set new tail's next to NULL
    tail = temp;       // update tail pointer
}

// Delete node at a specific position
void deleteAtPosition(Node* &head, Node* &tail, int position) {
    if (head == NULL) // empty list
        return;

    // Case 1: delete at head
    if (position == 1) {
        deleteAtHead(head, tail);
        return;
    }

    // traverse to node before target position
    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1 && temp->next != NULL) {
        temp = temp->next;
        cnt++;
    }

    // if position is out of range
    if (temp->next == NULL) {
        cout << "Out of Bound" << endl;
        return;
    }

    // Case 2: delete at tail
    if (temp->next == tail) {
        deleteAtTail(head, tail);
        return;
    }

    // Case 3: delete in middle
    Node* node2delete = temp->next;
    temp->next = node2delete->next;
    delete node2delete;
}

// Delete Whole list //

void deleteList(Node* &head, Node* &tail)
{
    Node* temp = head;

    while(temp!=NULL)
    {
        Node* nextnode = temp->next;
        delete temp;
        temp = nextnode;
    }

    head=NULL;
    tail=NULL;
}

//////////////////// PRINT FUNCTION ////////////////////

// Print linked list
void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) { // traverse until NULL
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//////////////////// MAIN FUNCTION ////////////////////
int main() {
    // Create first node
    Node* node1 = new Node(10);

    // Head and tail initially point to the same node
    Node* head = node1;
    Node* tail = node1;

    print(head); // Output: 10

    // Insert at tail
    insertAtTail(head, tail, 9);
    insertAtTail(head, tail, 12);
    insertAtTail(head, tail, 13);
    print(head); // Output: 10 9 12 13

    // Insert at position 2
    insertAtPosition(head, tail, 2, 111);
    print(head); // Output: 10 111 9 12 13

    // Delete head
    deleteAtHead(head, tail);
    print(head); // Output: 111 9 12 13

    // Delete tail
    deleteAtTail(head, tail);
    print(head); // Output: 111 9 12

    // Delete at position 2
    deleteAtPosition(head, tail, 2);
    print(head); // Output: 111 12
