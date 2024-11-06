#include <iostream>
#include <vector>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a; // Store the value of 'a' in 'temp'
    a = b;        // Assign the value of 'b' to 'a'
    b = temp;     // Assign the value of 'temp' to 'b', completing the swap
}

// Function to partition the array around a pivot (the first element)
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];            // Choose the first element as the pivot
    int i = high + 1;                // Initialize the index of the greater element
    for (int j = high; j > low; j--) // Iterate from high to low
    {
        // If the current element is greater than or equal to the pivot
        if (arr[j] > pivot)
        {
            i--;                  // Decrement the index of the greater element
            swap(arr[i], arr[j]); // Swap the current element with the element at index 'i'
        }
    }
    swap(arr[i - 1], arr[low]); // Place the pivot in its correct position
    return i - 1;               // Return the index of the pivot
}

// QuickSort function that sorts the array
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high) // Check if the array has more than one element
    {
        int pivotIndex = partition(arr, low, high); // Partition the array and get the pivot index
        // Recursively sort the elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " "; // Print each number followed by a space
    }
    cout << endl; // Print a newline after the array
}

int main()
{
    // Sample array to sort
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};
    cout << "Original Array: " << endl;
    printArray(arr); // Print the original array

    quickSort(arr, 0, arr.size() - 1); // Sort the array using QuickSort

    cout << "Sorted Array: " << endl;
    printArray(arr); // Print the sorted array

    return 0; // Return success
}
