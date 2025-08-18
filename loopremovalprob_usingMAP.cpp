#include <map>   // for using std::map

// Function to detect and remove a loop from the linked list
Node *removeLoop(Node *head)
{
    // If list is empty, nothing to do
    if (head == NULL)
        return NULL;

    // A map to store visited nodes
    // Key = Node pointer, Value = true if visited
    std::map<Node*, bool> visited;

    Node* temp = head;   // current pointer
    Node* prev = NULL;   // previous pointer (to break the loop later)

    // Traverse the linked list
    while (temp != NULL)
    {
        // If this node is already visited → loop detected
        if (visited[temp] == true)
        {
            // Break the loop by setting previous node's next to NULL
            prev->next = NULL;
            break;   // loop removed, exit
        }

        // Mark this node as visited
        visited[temp] = true;

        // Move pointers ahead
        prev = temp;
        temp = temp->next;
    }

    // Return head of modified list (now loop-free)
    return head;
}
