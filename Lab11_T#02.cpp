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

// Function for in-order traversal (Left -> Root -> Right)
void InOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;                    // Base case: if the node is null, return
    InOrderTraversal(root->left);  // Traverse the left subtree
    cout << root->data << " ";     // Visit the root node
    InOrderTraversal(root->right); // Traverse the right subtree
}

// Function for pre-order traversal (Root -> Left -> Right)
void PreOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;                     // Base case: if the node is null, return
    cout << root->data << " ";      // Visit the root node
    PreOrderTraversal(root->left);  // Traverse the left subtree
    PreOrderTraversal(root->right); // Traverse the right subtree
}

// Function for post-order traversal (Left -> Right -> Root)
void PostOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;                      // Base case: if the node is null, return
    PostOrderTraversal(root->left);  // Traverse the left subtree
    PostOrderTraversal(root->right); // Traverse the right subtree
    cout << root->data << " ";       // Visit the root node
}

int main()
{
    Node *root = nullptr; // Initialize the root of the BST as null (empty tree)
    int node, value;      // Variables for number of nodes and node values

    // Ask the user for the number of nodes to insert
    cout << "Enter how many Nodes you want to enter: ";
    cin >> node;

    // Loop to take input for each node and insert it into the BST
    for (int i = 0; i < node; i++)
    {
        cout << "Node#" << i + 1 << " : "; // Prompt for node value
        cin >> value;                      // Take input for node value
        root = insert(root, value);        // Insert the node value into the BST
    }

    // Perform and print the results of the tree traversals
    cout << "\nIn-Order Traversal of the BST: ";
    InOrderTraversal(root); // Should print nodes in ascending order

    cout << "\nPre-Order Traversal of the BST: ";
    PreOrderTraversal(root); // Should print root first, then left and right subtrees

    cout << "\nPost-Order Traversal of the BST: ";
    PostOrderTraversal(root); // Should print left and right subtrees first, then root

    return 0; 
}
