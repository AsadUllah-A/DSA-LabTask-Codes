#include <iostream>
using namespace std;

// Function to implement Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    int arr1[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Original Array 1: ";
    display(arr1, n1);
    bubbleSort(arr1, n1);
    cout << "Sorted Array 1: ";
    display(arr1, n1);
    cout << endl;

    // Test 2: Reverse sorted array
    int arr2[] = {10, 8, 6, 4, 2};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Original Array 2: ";
    display(arr2, n2);
    bubbleSort(arr2, n2);
    cout << "Sorted Array 2: ";
    display(arr2, n2);
    cout << endl;

    // Test 3: Random unsorted array
    int arr3[] = {7, 3, 9, 1, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Original Array 3: ";
    display(arr3, n3);
    bubbleSort(arr3, n3);
    cout << "Sorted Array 3: ";
    display(arr3, n3);
    cout << endl;

    return 0;
}
