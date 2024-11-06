#include <iostream>
#include <vector>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Insertion Sort function for small arrays
void insertionSort(vector<int> &arr, int low, int high)
{
    for (int i = low + 1; i <= high; i++)
    {
        int key = arr[i];
        int j = i - 1;

        // Sort in ascending order
        while (j >= low && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Partition function for QuickSort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
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

// QuickSort with fallback to Insertion Sort for small subarrays
void quickSort(vector<int> &arr, int low, int high)
{
    while (low < high)
    {
        // Use Insertion Sort for small subarrays
        if (high - low + 1 < 10)
        { // Directly using 10 instead of a constant
            insertionSort(arr, low, high);
            break;
        }
        else
        {
            // Standard QuickSort logic
            int pivotIndex = partition(arr, low, high);

            // Tail call optimization: Sort smaller part first to reduce stack depth
            if (pivotIndex - low < high - pivotIndex)
            {
                quickSort(arr, low, pivotIndex - 1);
                low = pivotIndex + 1;
            }
            else
            {
                quickSort(arr, pivotIndex + 1, high);
                high = pivotIndex - 1;
            }
        }
    }
}

// Function to print the array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19, 88, 21, 54, 17, 35, 2, 1, 44};
    cout << "Original Array: " << endl;
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: " << endl;
    printArray(arr);

    return 0;
}
