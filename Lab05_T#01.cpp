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
        head = newNode;         // If the list is empty, make this node the head
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

// Function to delete a node by value
void deleteNode(Node *&head, int value)
{
    if (head == nullptr)
    {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    if (head->data == value)
    { // If the node to be deleted is the head node
        Node *temp = head;
        head = head->next; // Update the head pointer
        delete temp;
        return;
    }
    Node *current = head;
    Node *prev = nullptr;
    while (current != nullptr && current->data != value)
    {
        prev = current;
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Node with value " << value << " not found.\n";
        return;
    }

    prev->next = current->next; // Remove the node from the list
    delete current;
}

// Function to search for a node by value
void search(Node *head, int value)
{
    Node *temp = head;
    int pos = 1;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            cout << "Value " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value " << value << " not found in the list.\n";
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

    // Taking input for 5 nodes
    cout << "Enter 5 values to insert in the linked list:"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        insert(head, value);
    }

    cout << "\nLinked list after insertion: "<<endl;
    display(head);

    // Deletion
    cout << "\nEnter value to delete from the linked list: ";
    cin >> value;
    deleteNode(head, value);
    cout << "\nLinked list after deletion: "<<endl;
    display(head);

    // Search
    cout << "\nEnter value to search in the linked list: ";
    cin >> value;
    search(head, value);

    return 0;
}