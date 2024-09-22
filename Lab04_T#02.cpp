#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int target)
{
    int low = 0;
    int high = size -1 ;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid]== target)
        {
            return mid;
        }
        if(arr[mid]>target)
        {
            high = mid -1;
        }
        else
        {
            low = mid +1;
        }
    }
    return -1;
}
int main()
{
    int arr[10];
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the array element at index["<<i<<"] : ";
        cin>>arr[i];
    }
    size = sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the search value : ";
    cin>>target;
    int result = binarySearch(arr,size,target);
    if(result !=-1)
    {
        cout<<"Serach Found at index["<<result<<"]"<<endl;
    }
    else
    {
        cout<<"Search Not Found"<<endl;
    }
    return 0;
}