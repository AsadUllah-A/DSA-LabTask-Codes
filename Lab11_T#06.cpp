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

// Function for In-order Traversal (Left, Root, Right)
// This function stores sorted elements in the provided array
void InOrderTraversal(Node *root, int arr[], int &index)
{
    if (root == nullptr)
        return;
    InOrderTraversal(root->left, arr, index);  // Visit left subtree
    arr[index++] = root->data;                 // Visit root and store in array
    InOrderTraversal(root->right, arr, index); // Visit right subtree
}

// Function to sort an array using BST
void sortArrayUsingBST(int arr[], int size)
{
    Node *root = nullptr;

    // Insert elements into the BST
    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }

    // In-order traversal to get the sorted elements
    int index = 0; // Index to keep track of the position in the array
    InOrderTraversal(root, arr, index);
}

int main()
{
    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Sort the array using BST
    sortArrayUsingBST(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
