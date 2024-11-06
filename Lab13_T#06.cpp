#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime> // For timing
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Merge function for Merge Sort
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // Length of left subarray
    int n2 = right - mid;    // Length of right subarray

    vector<int> leftArray(n1), rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

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

    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Quick Sort function
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Use the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

// Function to run tests and measure performance
void runTests()
{
    vector<vector<int>> testCases = {
        {33, 12, 52, 3, 75, 29, 41, 6, 19},
        {1, 2, 3, 4, 5, 6},
        {6, 5, 4, 3, 2, 1},
        {10, 7, 8, 9, 1, 5},
        {2, 2, 2, 2, 2},
        {},
        {100},
        {5, 3, 8, 5, 2, 5, 6, 5}};

    for (const auto &testCase : testCases)
    {
        cout << "Original Array: ";
        printArray(testCase);

        // Test Merge Sort
        vector<int> arr1 = testCase; // Copy for Merge Sort
        clock_t startMerge = clock();
        mergeSort(arr1, 0, arr1.size() - 1);
        clock_t endMerge = clock();
        cout << "Sorted Array (Merge Sort): ";
        printArray(arr1);
        double timeTakenMerge = double(endMerge - startMerge) / CLOCKS_PER_SEC;
        cout << "Time taken by Merge Sort: " << timeTakenMerge << " sec" << endl;

        // Test Quick Sort
        vector<int> arr2 = testCase; // Copy for Quick Sort
        clock_t startQuick = clock();
        quickSort(arr2, 0, arr2.size() - 1);
        clock_t endQuick = clock();
        cout << "Sorted Array (Quick Sort): ";
        printArray(arr2);
        double timeTakenQuick = double(endQuick - startQuick) / CLOCKS_PER_SEC;
        cout << "Time taken by Quick Sort: " << timeTakenQuick << " sec" << endl;

        cout << "-------------------------------------------" << endl;
    }
}

int main()
{
    runTests(); // Run the test cases
    return 0;
}
