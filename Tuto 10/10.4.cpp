#include <iostream>
#include <chrono> // reequired to use sleep_for()
#include <thread> // reequired to use sleep_for()
using namespace std;
void delay(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}
void display(const, )
{
    for (int i = 0; i < size; ++i)
    {
        cout << text[i];
    }
    cout << endl;
}
void rotateLeft(, )
{
    int tempChar = text[0];
    for (int i = 0; i < size - 1; ++i)
    {
        text[i] = text[i + 1];
    }
    text[size - 1] = tempChar;
}
void rotateRight(, )
{
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
    while (true)
    {
        system("cls"); // or system("clear"); for Linux/MacOS
        display(greetText1, textLength);
        rotateLeft(greetText1, textLength);
        display(greetText2, textLength);
        rotateRight(greetText2, textLength);
        delay(200); // delay for certain milliseconds
    }
}