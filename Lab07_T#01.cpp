#include <iostream>
using namespace std;

// Define the structure of a node for the doubly linked list
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node(); // Create a new node
    newNode->data = value;      // Assign value to the new node
    newNode->next = head;       // Point the new node's next to the current head
    newNode->prev = nullptr;    // The previous of the new node is null

    if (head != nullptr)
    {
        head->prev = newNode; // Update the previous head's prev pointer
    }
    head = newNode; // Update head to point to the new node
}

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

// Function to insert a node at a specific position
void insertAtPosition(Node *&head, int value, int position)
{
    if (position == 1)
    {
        insertAtBeginning(head, value); // If position is 1, insert at beginning
        return;
    }

    Node *newNode = new Node(); // Create a new node
    newNode->data = value;

    Node *temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next; // Traverse to the desired position
    }

    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    newNode->next = temp->next; // Set newNode's next to temp's next
    newNode->prev = temp;       // Set newNode's prev to temp

    if (temp->next != nullptr)
    {
        temp->next->prev = newNode; // Update the next node's prev pointer
    }
    temp->next = newNode; // Set temp's next to the new node
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is already empty.\n";
        return;
    }
    Node *temp = head;
    head = head->next; // Move head to the next node

    if (head != nullptr)
    {
        head->prev = nullptr; // Set the new head's previous to null
    }
    delete temp; // Free memory of the deleted node
}

// Function to delete a node from the end
void deleteFromEnd(Node *&head)
{
    if (head == nullptr)
    {
        cout << "List is already empty.\n";
        return;
    }

    Node *temp = head;
    if (head->next == nullptr)
    {
        // If there's only one node
        head = nullptr;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next; // Traverse to the last node
        }
        temp->prev->next = nullptr; // Set the second last node's next to null
    }
    delete temp; // Free memory of the deleted node
}

// Function to delete a node at a specific position
void deleteFromPosition(Node *&head, int position)
{
    if (head == nullptr)
    {
        cout << "List is already empty.\n";
        return;
    }
    if (position == 1)
    {
        deleteFromBeginning(head); // If position is 1, delete the first node
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position && temp != nullptr; i++)
    {
        temp = temp->next; // Traverse to the desired position
    }

    if (temp == nullptr)
    {
        cout << "Position out of range." << endl;
        return;
    }

    temp->prev->next = temp->next; // Update the previous node's next
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev; // Update the next node's prev
    }

    delete temp; // Free memory of the deleted node
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
    int value, n, position;

    // Step 1: Create the linked list by inserting initial values
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

    // Step 2: Ask the user for further operations
    char choice;
    do
    {
        cout << "\nWhat would you like to do next?\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "Enter your choice (1-6): ";
        int option;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAtBeginning(head, value);
            break;
        case 2:
            cout << "Enter the value to insert: ";
            cin >> value;
            insertAtEnd(head, value);
            break;
        case 3:
            cout << "Enter the value to insert: ";
            cin >> value;
            cout << "Enter the position: ";
            cin >> position;
            insertAtPosition(head, value, position);
            break;
        case 4:
            deleteFromBeginning(head);
            break;
        case 5:
            deleteFromEnd(head);
            break;
        case 6:
            cout << "Enter the position to delete: ";
            cin >> position;
            deleteFromPosition(head, position);
            break;
        default:
            cout << "Invalid choice!\n";
            break;
        }

        cout << "\nUpdated linked list: \n";
        display(head);

        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
