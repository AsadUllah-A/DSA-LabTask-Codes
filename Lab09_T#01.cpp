#include <iostream>
#include <string>
using namespace std;

// Class definition for Person
class Person
{
private:
    int per_id;
    string per_name;
    int per_age;

public:
    // Constructor
    Person() : per_id(0), per_name(""), per_age(0) {}

    // Input function to take user input
    void inputPerson()
    {
        cout << "Enter Person ID: ";
        cin >> per_id;
        cout << "Enter Person Name: ";
        cin.ignore(); // To clear the newline from the buffer
        getline(cin, per_name);
        cout << "Enter Person Age: ";
        cin >> per_age;
    }

    // Output function to display person details
    void outputPerson() const
    {
        cout << "Person ID: " << per_id << "\n";
        cout << "Person Name: " << per_name << "\n";
        cout << "Person Age: " << per_age << "\n";
    }
};

// Node structure for the linked list
struct Node
{
    Person person;
    Node *next;
};

// Queue class to manage linked list-based queue
class Queue
{
private:
    Node *front; // Points to the front of the queue
    Node *rear;  // Points to the rear of the queue

public:
    // Constructor to initialize an empty queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to check if the queue is empty (marked as const to fix the error)
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Function to add a person to the queue (enqueue)
    void addQueue(const Person &newPerson)
    {
        Node *newNode = new Node;
        newNode->person = newPerson;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode; // If queue is empty, front and rear both point to the new node
        }
        else
        {
            rear->next = newNode; // Link the new node at the end of the queue
            rear = newNode;       // Update the rear pointer to the new node
        }

        cout << "Person added to the queue.\n";
    }

    // Function to remove a person from the queue (dequeue)
    void removeQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot remove from an empty queue.\n";
        }
        else
        {
            Node *temp = front;  // Store the front node temporarily
            front = front->next; // Move front pointer to the next node

            if (front == nullptr)
            { // If the queue becomes empty, set rear to nullptr
                rear = nullptr;
            }

            cout << "Person removed from the queue:\n";
            temp->person.outputPerson();
            delete temp; // Delete the old front node
        }
    }

    // Function to display the front person in the queue without removing
    void displayFrontPerson() const
    {
        if (!isEmpty())
        {
            cout << "Person at the front of the queue:\n";
            front->person.outputPerson();
        }
        else
        {
            cout << "Queue is empty.\n";
        }
    }

    // Destructor to clean up the memory used by the queue
    ~Queue()
    {
        while (!isEmpty())
        {
            removeQueue();
        }
    }
};

// Main function
int main()
{
    Queue personQueue;
    Person person;
    int choice;
    char wants;

    do
    {
        cout << "\nQueue Menu:\n";
        cout << "1. Add Person to Queue\n";
        cout << "2. Remove Person from Queue\n";
        cout << "3. Display Front Person\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            person.inputPerson();
            personQueue.addQueue(person);
            break;

        case 2:
            personQueue.removeQueue();
            break;

        case 3:
            personQueue.displayFrontPerson();
            break;

        case 4:
            if (personQueue.isEmpty())
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Queue is not empty.\n";
            }
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> wants;

    } while (wants == 'y' || wants == 'Y');

    return 0;
}
