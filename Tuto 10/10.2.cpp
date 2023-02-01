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
void rotateLeft(char text[],int size )
{
    int tempChar = text[0];
    for (int i = 0; i < size - 1; ++i)
    {
        text[i] = text[i + 1];
    }
    text[size - 1] = tempChar;
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
    rotateLeft(greetText1, textLength);
    display(greetText1, textLength);
    rotateLeft(greetText1, textLength);
    display(greetText1, textLength);
    rotateLeft(greetText1, textLength);
    display(greetText1, textLength);
    rotateLeft(greetText1, textLength);
    display(greetText1, textLength);
    rotateLeft(greetText1, textLength);
    display(greetText2, textLength);
}