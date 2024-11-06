#include <iostream>
#include <vector>
using namespace std;

// Merge function that combines two sorted halves of the array
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Length of the left subarray
    int n2 = right - mid;    // Length of the right subarray

    // Create temporary arrays to hold the left and right halves
    vector<int> leftArray(n1), rightArray(n2);

    // Copy data to temporary arrays leftArray and rightArray
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left...right]
    int i = 0;    // Initial index of leftArray
    int j = 0;    // Initial index of rightArray
    int k = left; // Initial index of merged array

    // Merge elements from leftArray and rightArray in sorted order
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArray, if there are any
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArray, if there are any
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort function that divides the array and sorts each half
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // Find the middle point to divide the array

        // Recursively sort the first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Utility function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Test function to run multiple test cases
void runTests()
{
    vector<vector<int>> testCases = {
        {33, 12, 52, 3, 75, 29, 41, 6, 19}, // Unsorted
        {1, 2, 3, 4, 5, 6},                 // Already sorted
        {6, 5, 4, 3, 2, 1},                 // Reverse sorted
        {10, 7, 8, 9, 1, 5},                // Random order
        {2, 2, 2, 2, 2},                    // All duplicates
        {},                                 // Empty array
        {100},                              // Single element
        {5, 3, 8, 5, 2, 5, 6, 5}            // Contains duplicates
    };

    for (const auto &testCase : testCases)
    {
        cout << "Original Array: ";
        printArray(testCase); // Print the original array

        vector<int> arr = testCase;        // Make a copy for sorting
        mergeSort(arr, 0, arr.size() - 1); // Sort the array

        cout << "Sorted Array:   ";
        printArray(arr); // Print the sorted array
        cout << endl;
    }
}

int main()
{
    runTests(); // Run the test cases
    return 0;
}
