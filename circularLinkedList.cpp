#include <iostream>
using namespace std;

// Node structure for circular linked list
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

// Function to print circular linked list
void print(Node* head, Node* tail)
{
    Node* curr=head;
    if(head==NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    cout << "List: ";
    do
    {  
        cout<<curr->data<<" ";
        curr=curr->next;
    } while (curr!=head);
    cout << endl;
}

// Function to get length of circular linked list
int getlen(Node* head, Node* tail)
{   
    int count=0;
    Node* curr=head;
    if(head==NULL)
    {
        return 0;
    }
    do
    {  
        count++;
        curr=curr->next;
    } while (curr!=head);
    return count;    
}

// Insert after a given element
void insert(Node* &tail,Node* &head, int element, int data)
{    
    if(tail==NULL)  // empty list
    {
        Node* newnode=new Node(data);
        newnode->next=newnode;
        head=newnode;
        tail=newnode;
        return;
    }
    Node* curr=head;
    while (curr->data!=element)
    {
        curr=curr->next;
        if(curr==head)   // searched all list, element not found
        {
            cout<<"Element not found"<<endl;
            return;
        }
    }
    Node* insertnode=new Node(data);
    insertnode->next=curr->next;
    curr->next=insertnode;

    if(curr==tail)   // if element was tail, update tail
    {
        tail=insertnode;
    }    
}

// Insert at beginning
void insertatbegin(Node* &head, Node* &tail, int data)
{
    Node* newnode=new Node(data);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
        tail=newnode;
        return;
    }
    else
    {
        newnode->next=head;
        tail->next=newnode;
        head=newnode;
    }
}

// Insert at end
void insertattail(Node* &head, Node* &tail, int data)
{
   Node* newnode =new Node(data);
   if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
        tail=newnode;
        return;
    }
    else
    {
        tail->next=newnode;
        newnode->next=head;
        tail=newnode;
    }
}

// Delete at beginning
void deleteatbegin(Node* &head, Node* &tail)
{
    if(head==NULL)
    {
        return;
    }
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp = head;
    head=temp->next;
    tail->next=head;
    delete temp;
}

// Delete at end
void deleteatend(Node* &head, Node* &tail)
{
     if(head==NULL)
    {
        return;
    }
    if (head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp=head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    Node* curr=temp->next;
    temp->next=head;
    delete curr;
    tail=temp;
}

// Delete a specific element
void deletenode(Node* &head, Node* &tail, int element)
{
    if(head==NULL)
        return;

    Node* curr= head;
    Node* prev=tail;

    do
    {   
        if(curr->data==element)
        {
            if(head==tail) // only one node
            {
                delete head;
                tail=NULL;
                head=NULL;
                return;
            }
            if(curr==head)  // first node
            {
                deleteatbegin(head,tail);
                return;
            }
            if(curr==tail)  // last node
            {
                deleteatend(head,tail);
                return;
            }

            // middle node
            prev->next=curr->next;
            delete curr;
            return;
        }
        prev=curr;
        curr=curr->next;
    } while (curr!=head);

    cout << "Value " << element << " not found in list!" << endl;
}

// MAIN function to test
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Insert at tail
    insertattail(head, tail, 10);
    insertattail(head, tail, 20);
    insertattail(head, tail, 30);
    print(head, tail);

    // Insert at beginning
    insertatbegin(head, tail, 5);
    print(head, tail);

    // Insert after an element
    insert(tail, head, 20, 25); // insert 25 after 20
    print(head, tail);

    // Delete at beginning
    deleteatbegin(head, tail);
    print(head, tail);

    // Delete at end
    deleteatend(head, tail);
    print(head, tail);

    // Delete specific element
    deletenode(head, tail, 20);
    print(head, tail);

    deletenode(head, tail, 100); // not in list
    print(head, tail);

    cout << "Length of list: " << getlen(head, tail) << endl;

    return 0;
}
