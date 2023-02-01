#include <iostream>
using namespace std;
int main()
{
    int number;
    int sum;
    int counter;
    sum = 0;
    counter = 0;
    while (counter < 4)
    {
        cout << "Enter a number => ";
        cin >> number;
        sum = sum + number;
        counter = counter + 1;
    }
    cout << "Sum = " << sum << endl;
}