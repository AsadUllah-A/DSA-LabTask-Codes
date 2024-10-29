#include <iostream>
#include <string>
using namespace std;

// Student class definition
class Student
{
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    // Constructor to initialize data members
    Student() : reg_no(0), st_name(""), cgpa(0.0f) {}

    // Input function to take user input for student attributes
    void inputStudent()
    {
        cout << "Enter Student Registration Number: ";
        cin >> reg_no;
        cout << "Enter Student Name: ";
        cin.ignore(); // To clear the newline from the input buffer
        getline(cin, st_name);
        cout << "Enter Student CGPA: ";
        cin >> cgpa;
    }

    // Output function to display student details
    void outputStudent() const
    {
        cout << "Student Registration Number: " << reg_no << "\n";
        cout << "Student Name: " << st_name << "\n";
        cout << "Student CGPA: " << cgpa << "\n";
    }
};

// Stack class to implement a stack of Student objects
class Stack
{
private:
    Student *stackArray; // Dynamic array to hold Student objects
    int top;             // Index of the top element
    int capacity;        // Maximum size of the stack

public:
    // Constructor to initialize the stack with dynamic size
    Stack(int size)
    {
        stackArray = new Student[size]; // Allocate memory for the stack
        top = -1;                       // Stack is initially empty
        capacity = size;
    }

    // Destructor to deallocate memory used by the dynamic array
    ~Stack()
    {
        delete[] stackArray;
    }

    // Function to check if the stack is full
    bool isFull() const
    {
        return top == capacity - 1;
    }

    // Function to check if the stack is empty
    bool isEmpty() const
    {
        return top == -1;
    }

    // Function to push a Student object onto the stack
    void push(const Student &student)
    {
        if (isFull())
        {
            cout << "Stack Overflow: Cannot push. Stack is full.\n";
        }
        else
        {
            stackArray[++top] = student; // Increment top and add the student
            cout << "Student added to the stack.\n";
        }
    }

    // Function to pop a Student object from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow: Cannot pop. Stack is empty.\n";
        }
        else
        {
            cout << "Popped Student Details:\n";
            stackArray[top--].outputStudent(); // Display and remove the top student
        }
    }

    // Function to display all elements in the stack without removing
    void displayStack() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Current Stack:\n";
            for (int i = top; i >= 0; --i)
            {
                cout << "Student at position " << i + 1 << ":\n";
                stackArray[i].outputStudent();
                cout << endl;
            }
        }
    }
};

// Main function
int main()
{
    int stackSize;

    // Get the size of the stack from the user
    cout << "Enter the size of the stack: ";
    cin >> stackSize;

    // Create a stack of the given size
    Stack studentStack(stackSize);

    int choice;
    do
    {
        cout << "\nStack Menu:\n";
        cout << "1. Push Student onto Stack\n";
        cout << "2. Pop Student from Stack\n";
        cout << "3. Display All Students in Stack\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Student student;
            student.inputStudent();     // Input student details
            studentStack.push(student); // Push the student onto the stack
            break;
        }
        case 2:
            studentStack.pop(); // Pop student from the stack and display details
            break;
        case 3:
            studentStack.displayStack(); // Display all students currently in the stack
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
