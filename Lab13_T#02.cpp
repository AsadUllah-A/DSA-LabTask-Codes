#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to partition the array around a random pivot
int randomPartition(vector<int> &arr, int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1); // Generate a random index
    swap(arr[randomIndex], arr[high]);                 // Swap random pivot with the last element
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

// Original partition function for fixed pivot (last element as pivot)
int fixedPartition(vector<int> &arr, int low, int high)
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

// QuickSort function with random pivot selection
void quickSortRandomPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = randomPartition(arr, low, high);
        quickSortRandomPivot(arr, low, pivotIndex - 1);
        quickSortRandomPivot(arr, pivotIndex + 1, high);
    }
}

// QuickSort function with fixed pivot selection
void quickSortFixedPivot(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = fixedPartition(arr, low, high);
        quickSortFixedPivot(arr, low, pivotIndex - 1);
        quickSortFixedPivot(arr, pivotIndex + 1, high);
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
    // Initialize random seed for random pivot selection
    srand(static_cast<unsigned>(time(0)));

    // Sample array to sort
    vector<int> arr = {33, 12, 52, 3, 75, 29, 41, 6, 19};

    cout << "Original Array: " << endl;
    printArray(arr);

    // Measure execution time for fixed pivot QuickSort
    vector<int> arrFixed = arr;
    clock_t startFixed = clock();
    quickSortFixedPivot(arrFixed, 0, arrFixed.size() - 1);
    clock_t endFixed = clock();
    double timeFixed = double(endFixed - startFixed) / CLOCKS_PER_SEC;

    cout << "Sorted Array with Fixed Pivot QuickSort: " << endl;
    printArray(arrFixed);
    cout << "Execution Time (Fixed Pivot): " << timeFixed << " seconds" << endl;

    // Measure execution time for random pivot QuickSort
    vector<int> arrRandom = arr;
    clock_t startRandom = clock();
    quickSortRandomPivot(arrRandom, 0, arrRandom.size() - 1);
    clock_t endRandom = clock();
    double timeRandom = double(endRandom - startRandom) / CLOCKS_PER_SEC;

    cout << "Sorted Array with Random Pivot QuickSort: " << endl;
    printArray(arrRandom);
    cout << "Execution Time (Random Pivot): " << timeRandom << " seconds" << endl;

    return 0;
}
