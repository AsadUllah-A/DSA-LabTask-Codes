#include <iostream>
using namespace std;

// Function to implement Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to display the array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    // Test 1: Sorted array
    int arr1[] = {5, 12, 15, 17, 20};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original Array 1: ";
    display(arr1, n1);
    insertionSort(arr1, n1);
    cout << "Sorted Array 1: ";
    display(arr1, n1);
    cout << endl;

    // Test 2: Reverse sorted array
    int arr2[] = {20, 15, 10, 5, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original Array 3: ";
    display(arr2, n2);
    insertionSort(arr2, n2);
    cout << "Sorted Array 2: ";
    display(arr2, n2);
    cout << endl;

    // Test 3: Random unsorted array
    int arr3[] = {7, 3, 9, 1, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Original Array 3: ";
    display(arr3, n3);
    insertionSort(arr3, n3);
    cout << "Sorted Array 3: ";
    display(arr3, n3);
    cout << endl;

    return 0;
}
