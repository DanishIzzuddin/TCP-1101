#include <iostream>
using namespace std;

int main()
{
    int i;
    i = 0;

    while (i < 9)
    {
        cout<<"\t";
        int j;
        j = 0;
        while (j < 9)
        {
            cout << j << "_";
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
}