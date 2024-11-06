#include <iostream>
using namespace std;

// Function to implement Insertion Sort with comparison and swap counters
void insertionSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j = j - 1;
            swaps++;
        }

        arr[j + 1] = key;
        if (j >= 0)
            comparisons++; // For the last comparison when while condition fails
    }
}

// Function to implement Bubble Sort with comparison and swap counters
void bubbleSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
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
    int comparisons, swaps;

    // Test cases for Insertion Sort
    cout << "Testing Insertion Sort:\n";

    // Sorted array
    int arr1[] = {5, 12, 15, 17, 20};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    insertionSort(arr1, n1, comparisons, swaps);
    cout << "Test 1 - Sorted Array: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    // Reverse sorted array
    int arr2[] = {20, 15, 10, 5, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    insertionSort(arr2, n2, comparisons, swaps);
    cout << "Test 2 - Reverse Sorted Array: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    // Random unsorted array
    int arr3[] = {7, 3, 9, 1, 5};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, n3, comparisons, swaps);
    cout << "Test 3 - Random Unsorted Array: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    // Test cases for Bubble Sort
    cout << "\nTesting Bubble Sort:\n";

    // Sorted array
    int arr4[] = {1, 2, 3, 4, 5};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    bubbleSort(arr4, n4, comparisons, swaps);
    cout << "Test 1 - Sorted Array: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    // Reverse sorted array
    int arr5[] = {10, 8, 6, 4, 2};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    bubbleSort(arr5, n5, comparisons, swaps);
    cout << "Test 2 - Reverse Sorted Array: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    // Random unsorted array
    int arr6[] = {7, 3, 9, 1, 5};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    bubbleSort(arr6, n6, comparisons, swaps);
    cout << "Test 3 - Random Unsorted Array: Comparisons = " << comparisons << ", Swaps = " << swaps << endl;

    return 0;
}
