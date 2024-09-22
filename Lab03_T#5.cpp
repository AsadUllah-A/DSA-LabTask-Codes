#include<iostream>
using namespace std;
int main() 
{
    cout<<"Task # 05"<<endl;
    int size=6;
    int array[size];
    cout << "\nEnter 6 integer values: "<<endl;
    for (int i = 0; i < size; i++) 
    {
        cin >> array[i];
    }

    bool isPalindrome = true;
    for (int i = 0; i < size / 2; i++) 
    {
        if (array[i] != array[size - 1 - i]) 
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) 
    {
        cout << "The array represents a palindrome." << endl;
    } 
    else 
    {
        cout << "The array does not represent a palindrome." << endl;
    }
    return 0;
}
