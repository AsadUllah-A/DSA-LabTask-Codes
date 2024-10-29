#include <iostream>
using namespace std;

// Define the structure for a Node in the BST
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Function to create a new node
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into the BST
Node *insert(Node *root, int value)
{
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to find the minimum value node in the right subtree (in-order successor)
Node *findMin(Node *root)
{
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Function to delete a node from the BST
Node *deleteNode(Node *root, int value)
{
    if (root == nullptr)
        return root; // Base case: tree is empty or node not found

    // Traverse the tree to find the node to delete
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else
    {
        // Case 1: Node to be deleted is a leaf node or has one child
        if (root->left == nullptr)
        {
            Node *temp = root->right; // Store the right child
            delete root;              // Free the current node
            return temp;              // Return the right child
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left; // Store the left child
            delete root;             // Free the current node
            return temp;             // Return the left child
        }

        // Case 2: Node to be deleted has two children
        Node *temp = findMin(root->right);                 // Find the in-order successor (smallest node in right subtree)
        root->data = temp->data;                           // Replace the node's data with the successor's data
        root->right = deleteNode(root->right, temp->data); // Delete the successor node
    }
    return root;
}

// Function to perform in-order traversal of the BST (to display the tree)
void InOrderTraversal(Node *root)
{
    if (root == nullptr)
        return;
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

int main()
{
    Node *root = nullptr;
    int n, value, delValue;

    // Insert nodes into the BST
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Node#" << i + 1 << " : ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "In-order traversal of the BST: ";
    InOrderTraversal(root);
    cout << endl;

    // Deleting a node from the BST
    cout << "Enter value to delete: ";
    cin >> delValue;

    root = deleteNode(root, delValue); // Perform deletion

    cout << "In-order traversal of the BST after deletion: ";
    InOrderTraversal(root); // Display the updated BST
    cout << endl;

    return 0;
}
