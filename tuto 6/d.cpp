#include <iostream>
using namespace std;
int fun(int x, int y = 33)
{
    return y;
}
int main()
{
    int x = 13, y = 23;
    int z = fun(x);
    cout << z;
}