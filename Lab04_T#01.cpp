#include<iostream>
using namespace std;

int linearSearch(int arr[], int size, int target)
{
    for(int i=0; i<size; i++)
    {
        if(arr[i]==target)
        {
            return i;
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
    int result = linearSearch(arr,size,target);
    if(result !=-1)
    {
        cout<<"Search Found at index["<<result<<"]"<<endl;
    }
    else
    {
        cout<<"Search Not Found"<<endl;
    }
    return 0;
}