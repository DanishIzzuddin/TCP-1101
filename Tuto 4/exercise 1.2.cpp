#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n => ";
    cin >> n;
    int count = n;
    while (count > 0)
    {
        cout << count << " ";
        count = count - 1;
    }
}