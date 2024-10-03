#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

// Linked List class
class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    // Function to check if the list is empty
    bool isEmpty()
    {
        return head == nullptr;
    }

    // Insert at the end of the list
    void insertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position)
    {
        Node *newNode = new Node();
        newNode->data = value;

        if (position < 1)
        {
            cout << "Invalid position!" << endl;
            delete newNode; // Avoid memory leak
            return;
        }

        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Position is greater than the length of the list!" << endl;
            delete newNode; // Avoid memory leak
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Delete a node at the start of the list
    void deleteFromStart()
    {
        if (isEmpty())
        {
            cout << "List is empty, cannot delete!" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete all nodes one by one
    void deleteAllNodes()
    {
        while (!isEmpty())
        {
            deleteFromStart();
        }
    }

    // Print the linked list
    void printList()
    {
        if (isEmpty())
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, value, position;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at position\n";
        cout << "3. Delete from start\n";
        cout << "4. Delete all nodes\n";
        cout << "5. Print list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position to insert at: ";
            cin >> position;
            list.insertAtPosition(value, position);
            break;

        case 3:
            list.deleteFromStart();
            break;

        case 4:
            list.deleteAllNodes();
            break;

        case 5:
            list.printList();
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
