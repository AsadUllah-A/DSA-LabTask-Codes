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
    newNode->left = nullptr;    // Initialize the left child as null
    newNode->right = nullptr;   // Initialize the right child as null
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

    // Insert nodes into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    /* 
           TREE
            50
          /    \
        30      70
        /  \    /  \
       20  40  60  80
    */

    // Perform and print the results of the tree traversals
    cout << "\nIn-Order Traversal of the BST: ";
    InOrderTraversal(root); // Should print nodes in ascending order

    cout << "\nPre-Order Traversal of the BST: ";
    PreOrderTraversal(root); // Should print root before subtrees

    cout << "\nPost-Order Traversal of the BST: ";
    PostOrderTraversal(root); // Should print root after subtrees

    return 0; 
}
