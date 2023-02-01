#include <iostream>
using namespace std;

int main()
{
    int i;
    int n;
    i = 0;

    cout<<"enter your n:";
    cin>>n;

    while (i < n)
    {
        cout<<"\t";
        int j;
        j = n;
        i = i + 1;
        while (j > i)
        {
            cout << "-";
            j = j - 1;
        }
        cout << "*" << endl;
    }
}