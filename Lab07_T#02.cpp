#include <iostream>
using namespace std;

// Define the structure of a node for the doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Assign value to the new node
    newNode->next = nullptr;    // Set the next pointer to null

    if (head == nullptr)
    {
        newNode->prev = nullptr; // If list is empty, make newNode the head
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Add the new node at the end
        newNode->prev = temp; // Set the previous pointer of the new node
    }
}

// Function to traverse the list in forward direction
void forwardTraversal(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    cout << "Forward Traversal: ";
    while (temp != nullptr)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to traverse the list in backward direction
void backwardTraversal(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    // Traverse to the last node
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Traverse backwards from the last node to the head
    cout << "Backward Traversal: ";
    while (temp != nullptr)
    {
        cout << temp->data << "-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    int value;

    // Insert at least 5 nodes
    cout << "Enter 5 values to insert into the list:\n";
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insertAtEnd(head, value);
    }

    // Display forward traversal
    cout << "\nTraversing the list in forward direction:\n";
    forwardTraversal(head);

    // Display backward traversal
    cout << "\nTraversing the list in backward direction:\n";
    backwardTraversal(head);

    return 0;
}
