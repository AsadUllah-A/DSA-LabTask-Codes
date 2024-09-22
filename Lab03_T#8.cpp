#include <iostream>
using namespace std;

int main() 
{
    cout<<"Task # 08"<<endl;
    int searchValue;
    cout << "Enter Search Value: ";
    cin >> searchValue;
    int numbers[4][4] = 
    {
        {12, 34, 23, 84},
        {78, 69, 89, 12},
        {39, 12, 45, 67},
        {90, 23, 56, 78}
    };

    bool found = false;
    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if (numbers[i][j] == searchValue) 
            {
                found = true;
                cout << "*** Search Found at index [" << i << "][" << j << "] ***" << endl;
                break;
            }
        }
        if (found) break;
    }
    if (!found) 
    {
        cout << "\n*** Search Not Found ***" << endl;
    }
    return 0;
}
