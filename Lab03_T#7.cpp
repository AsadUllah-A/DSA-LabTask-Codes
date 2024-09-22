#include <iostream>
using namespace std;

int main() 
{
    cout<<"Task # 07"<<endl;
    int size, key, position = -1;
    cout << "Enter the size of the array: ";
    cin >> size;
    int array[size];
    cout << "Enter " << size << " elements of the array:" << endl;
    for(int i = 0; i < size; i++) 
    {
        cin >> array[i];
    }
    cout << "Enter the key value to search: ";
    cin >> key;
    for(int i = 0; i < size; i++) 
    {
        if(array[i] == key) 
        {
            position = i;
            break;
        }
    }
    if(position != -1) 
    {
        cout << "Key value found at position " << position + 1 << " in the array." << endl;
    } 
    else 
    {
        cout << "Key value not found in the array." << endl;
    }
    return 0;
}