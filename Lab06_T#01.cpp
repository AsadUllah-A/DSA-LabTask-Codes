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
        head = newNode;        // If the list is empty, make this node the head
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

// Function to find the middle node using slow and fast pointer approach
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

    cout << "\nLinked list: "<<endl;
    display(head);

    // Find and display the middle of the linked list
    findMiddle(head);

    return 0;
}
