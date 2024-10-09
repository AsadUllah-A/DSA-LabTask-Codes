#include <iostream>
using namespace std;

// Define the structure of a node for the circular linked list
struct Node
{
    int data;
    Node *next;
};

// Function to insert a node at the End of the circular linked list
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to delete a node by value from the circular linked list
void deleteNode(Node *&head, int value)
{
    if (head == nullptr)
    {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    Node *temp = head;
    Node *prev = nullptr;

    // Case 1: If the node to be deleted is the head node
    if (head->data == value)
    {
        // If the list contains only one node
        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        // Otherwise, find the last node to update its next pointer
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next; // Last node points to the new head
        Node *toDelete = head;
        head = head->next; // Update head to the next node
        delete toDelete;
        return;
    }

    // Case 2: Deleting a node other than the head
    prev = head;
    temp = head->next;
    while (temp != head && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == head)
    {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    prev->next = temp->next; // Unlink the node to be deleted
    delete temp;
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
    char choice;
    int value;

    // Inserting nodes at the end of the circular linked list
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    // Displaying the circular linked list
    cout << "Circular Linked List:" << endl;
    display(head);

    // Manual deletion by user input
    do
    {
        cout << "\nEnter the value of the node to delete: ";
        cin >> value;
        deleteNode(head, value);
        display(head);

        cout << "Do you want to delete another node? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
