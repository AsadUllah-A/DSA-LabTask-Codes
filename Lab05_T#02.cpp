#include <iostream>
using namespace std;

// Define the structure of a node
struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at the end of the linked list
void insert(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Assign value to the new node
    newNode->next = nullptr;    // Set the next pointer to null

    if (head == nullptr)
    {
        head = newNode; // If the list is empty, make this node the head
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Add the new node at the end of the list
    }
}

// Function to reverse the linked list
void reverse(Node *&head)
{
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while (current != nullptr)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the `prev` to current
        current = next;       // Move to the next node
    }
    head = prev; // Update the head to the new first node
}

// Function to display the linked list
void display(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    int value;

    // Insert some values into the linked list
    cout << "Enter 5 values to insert in the linked list:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insert(head, value);
    }

    cout << "\nOriginal linked list: "<<endl;
    display(head);

    // Reverse the linked list
    reverse(head);
    cout << "\nReversed linked list: "<<endl;
    display(head);

    return 0;
}