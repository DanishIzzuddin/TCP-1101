#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n => ";
    cin >> n;
    int count = 0;
    while (count < n)
    {
        cout << count << " ";
        count = count + 1;
    }
}