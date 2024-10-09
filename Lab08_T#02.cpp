#include <iostream>
using namespace std;

// Define the structure of a node for the circular linked list
struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at the Beginning of the circular linked list
void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;

    if (head == nullptr)
    {
        // If list is empty, the new node points to itself
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        // Traverse to the last node
        while (temp->next != head)
        {
            temp = temp->next;
        }
        newNode->next = head; // New node points to the current head
        temp->next = newNode; // Last node now points to the new node
        head = newNode;       // New node becomes the new head
    }
}

// Function to insert a node at the End of the circular linked list
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;

    if (head == nullptr)
    {
        // If list is empty, the new node points to itself
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        // Traverse to the last node
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode; // Add the new node at the end
        newNode->next = head; // Set the new node to point to head
    }
}

// Function to traverse and print the elements of the circular linked list
void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD\n";
}

int main()
{
    Node *head = nullptr;

    // Inserting nodes at the end of the circular linked list
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    // Inserting a node at the beginning of the circular linked list
    insertAtBeginning(head, 10);

    // Displaying the circular linked list
    cout << "\nCircular Linked List After Insertion at Beginning:" << endl;
    display(head);

    return 0;
}
