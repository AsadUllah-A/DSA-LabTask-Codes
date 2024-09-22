#include<iostream>
using namespace std;
int main()
{
    cout<<"Task # 01"<<endl;
    int array[10]={1,2,3,4,5,6,7,8,9,10};
    for(int i=0; i<10; i++)
    {
        cout<<"Natural Number "<<i+1<<" : "<<array[i]<<endl;
    }
    
    cout<<"\nTask # 02"<<endl;
    int searchValues;
    cout << "Enter Search Value: ";
    cin >> searchValues;
    bool found = false;
    for (int i = 0; i < 10; i++)
    {
        if (array[i] == searchValues)
        {
            found = true;
            cout << "*** Search Found ***" << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "*** Search Not Found ***" << endl;
    }
    
    cout<<"\nTask # 03"<<endl;
    int pos,value;
    cout<<"Enter the location of Insertion : ";
    cin>>pos;
    cout<<"Enter the value of Insertion : ";
    cin>>value;
    array[pos-1]=value;
    cout<<"Array After Insertion : "<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<"Natural Number "<<i+1<<" : "<<array[i]<<endl;
    }
}