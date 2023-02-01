#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n => ";
    cin >> n;
    int term1 = 0;
    int term2 = 1;
    int count = 0;
    while (count < n)
    {
        // cout << count << " ";
        // some operations
        int newTerm = term1 + term2;
        term1 = term2;
        term2 = newTerm;
        cout << newTerm << " ";
        count = count + 1;
    }
}