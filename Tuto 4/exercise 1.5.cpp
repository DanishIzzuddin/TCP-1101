#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n => ";
    cin >> n;
    int y = 0;
    int x = 1;
    while (x <= n)
    {
        cout << x << ":" << y << " ";
        y = y + x;
        x = x + 1;
    }
}