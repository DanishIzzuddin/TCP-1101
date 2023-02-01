#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int num;
    srand(56);
    int count = 0;
    while (count < 50)
    {
        num = rand() % 6 + 1;
        cout << num << " ";
        count = count + 1;
    }
}