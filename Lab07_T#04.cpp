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

// Function to find the middle node of the doubly linked list
void findMiddle(Node *head)
{
    if (head == nullptr)
    {
        cout << "The list is empty.\n";
        return;
    }

    Node *slow = head;
    Node *fast = head;

    // Move fast by two nodes and slow by one node at a time
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Slow pointer moves one step
        fast = fast->next->next; // Fast pointer moves two steps
    }

    // When fast pointer reaches the end, slow pointer is at the middle
    cout << "\nThe middle element is: " << slow->data << endl;
}

// Function to display the doubly linked list
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
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = nullptr;
    int value, n;

    // Insert nodes interactively
    cout << "How many values would you like to insert initially? ";
    cin >> n;

    cout << "Enter " << n << " values to insert into the list:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertAtEnd(head, value); // Initial insertion is done at the end
    }

    cout << "\nInitial linked list: \n";
    display(head);

    // Find and display the middle of the linked list
    findMiddle(head);

    return 0;
}
