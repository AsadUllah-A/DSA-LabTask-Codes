#include <iostream>
#include <vector>
#include <cstdlib> // For generating random numbers
using namespace std;

// Global variables to count comparisons and swaps
long long comparisonCount = 0;
long long swapCount = 0;

// Function to swap two elements and count swaps
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    swapCount++; // Increment swap count
}

// Function to partition the array around a pivot
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        comparisonCount++; // Increment comparison count
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// QuickSort function that sorts the array
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Function to generate a random array of a given size
vector<int> generateRandomArray(int size)
{
    vector<int> arr(size);
    for (int &num : arr)
    {
        num = rand() % 1000; // Random numbers from 0 to 999
    }
    return arr;
}

int main()
{
    vector<int> sizes = {100, 1000, 10000}; // Different array sizes to test

    for (int size : sizes)
    {
        // Generate a random array of the specified size
        vector<int> arr = generateRandomArray(size);

        // Reset counts
        comparisonCount = 0;
        swapCount = 0;

        // Perform QuickSort on the array
        quickSort(arr, 0, arr.size() - 1);

        // Output results
        cout << "Array size: " << size << endl;
        cout << "Comparisons: " << comparisonCount << endl;
        cout << "Swaps: " << swapCount << endl;
        cout << "---------------------------------" << endl;
    }

    return 0;
}
