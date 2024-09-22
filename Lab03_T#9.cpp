#include <iostream>
using namespace std;

int main() 
{
    cout<<"Task # 09"<<endl;
    int matrix[3][3];
    int swapedMatrix[3][3];
    cout << "Enter the elements of the 3x3 matrix:" << endl;
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            cout << "Element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            swapedMatrix[j][i] = matrix[i][j];
        }
    }
    cout << "\nThe transposed matrix is:" << endl;
    for(int i = 0; i < 3; i++) 
    {
        for(int j = 0; j < 3; j++) 
        {
            cout << swapedMatrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}