#include <iostream>
using namespace std;

// Define the structure of a node for the binary search tree (BST)
struct Node
{
    int data;    // Data stored in the node
    Node *left;  // Pointer to the left child node
    Node *right; // Pointer to the right child node
};

// Function to create a new node
Node *createNode(int value)
{
    Node *newNode = new Node(); // Allocate memory for the new node
    newNode->data = value;      // Assign the value to the node's data field
    newNode->left = nullptr;    // Set the left child to null initially
    newNode->right = nullptr;   // Set the right child to null initially
    return newNode;             // Return the new node
}

// Function to insert a node into the BST
Node *insert(Node *root, int value)
{
    // Base case: If the tree is empty, create a new node and return it
    if (root == nullptr)
    {
        return createNode(value);
    }

    // Recursive case: Traverse the tree to find the correct location
    if (value < root->data)
    {
        // If the value is smaller, insert into the left subtree
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        // If the value is larger, insert into the right subtree
        root->right = insert(root->right, value);
    }

    return root; // Return the updated root node
}

// Function to search for a value in the BST
bool search(Node *root, int value)
{
    if (root == nullptr)
        return false; // Base case: if the tree is empty or value is not found

    if (root->data == value)
        return true; // If the current node's data matches the value, return true

    if (value < root->data)
    {
        // If the value is smaller, search in the left subtree
        return search(root->left, value);
    }
    else
    {
        // If the value is larger, search in the right subtree
        return search(root->right, value);
    }
}

int main()
{
    Node *root = nullptr; // Initialize the root of the BST as null (empty tree)
    int node, value;      // Variables for number of nodes and node values

    // Ask the user for the number of nodes to insert
    cout << "Enter how many nodes you want to insert: ";
    cin >> node;

    // Loop to take input for each node and insert it into the BST
    for (int i = 0; i < node; i++)
    {
        cout << "Node#" << i + 1 << " : "; // Prompt for node value
        cin >> value;                      // Take input for node value
        root = insert(root, value);        // Insert the node value into the BST
    }

    // Ask the user for the value to search in the BST
    int key;
    cout << "Enter the value you want to search: ";
    cin >> key;

    // Search the value and print the result
    if (search(root, key))
    {
        cout << key << " Found in the BST";
    }
    else
    {
        cout << key << " Not Found in the BST";
    }

    return 0;
}
