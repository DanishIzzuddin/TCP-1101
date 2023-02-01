#include <iostream>
using namespace std;
void display(const char text[],int size )
{
    for (int i = 0; i < size; ++i)
    {
        cout << text[i];
    }
    cout << endl;
}
int main()
{
    const int textLength = 15;
    char greetText1[textLength] = {'P', 'R', 'O', 'G', 'R',
                                   'A', 'M', 'M', 'I', 'N',
                                   'G', ' ', ' ', ' ', ' '};
    char greetText2[textLength] = {'I', 'S', ' ', 'F', 'U',
                                   'N', '!', ' ', ' ', ' ',
                                   ' ', ' ', ' ', ' ', ' '};
    display(greetText1, textLength);
    display(greetText2, textLength);
}