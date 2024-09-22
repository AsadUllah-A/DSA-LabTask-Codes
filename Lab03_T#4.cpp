#include <iostream> 
using namespace std; 
int main()
{
    cout<<"Task # 04"<<endl;
    int size, pos;
    cout<<"\nSize of Array is : ";
    cin>>size;
    int array[size];
    cout<<"\nEnter Values for Array :- "<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"Vale#"<<i+1<<" : ";
        cin>>array[i];
    }
    cout<<"\nEnter The Position Of Element You Want to Delete : ";
    cin>>pos;
    for(int i=pos-1; i<size; i++)
    {
        array[i]=array[i+1];
    }
    size--;
    cout<<"\nNew Array After Deleting Element : "<<endl;
     for(int i=0; i<size; i++)
    {
        cout<<"Vale#"<<i+1<<" : "<<array[i]<<endl;
    }
}
