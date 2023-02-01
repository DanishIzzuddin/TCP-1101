#include<iostream>
using namespace std;

void displayH()
{
    cout << "H   H" << endl;
    cout << "H   H" << endl;
    cout << "HHHHH" << endl;
    cout << "H   H" << endl;
    cout << "H   H" << endl;
    cout << endl;

}
void displayO()
{
    cout << " OOO " << endl;
    cout << "O   O" << endl;
    cout << "O   O" << endl;
    cout << "O   O" << endl;
    cout << " OOO " << endl;
    cout << endl;

}
void displayE()
{
    cout << "EEEE" << endl;
    cout << "E" << endl;
    cout << "EEEE" << endl;
    cout << "E" << endl;
    cout << "EEEE" << endl;
    cout << endl;

}
void displayL()
{
    cout << "L" << endl;
    cout << "L" << endl;
    cout << "L" << endl;
    cout << "L" << endl;
    cout << "LLLL" << endl;
    cout << endl;

}
void displayExclamation()
{
    cout << " ! " << endl;
    cout << " ! " << endl;
    cout << " ! " << endl;
    cout << " " << endl;
    cout << " ! " << endl;
    cout << endl;
}
void display(char ch1, char ch2, char ch3, char ch4, char ch5, char ch6)
{
    switch (ch1)
    {
        case 'H':
        displayH();
        break;
        case 'O':
        displayO();
        break;
        case '!':
        displayExclamation();
        break;
        case 'E':
        displayE();
        break;
        case 'L':
        displayL();
        break;
    }
    switch (ch2)
    {
        case 'H':
        displayH();
        break;
        case 'O':
        displayO();
        break;
        case '!':
        displayExclamation();
        break;
        case 'E':
        displayE();
        break;
        case 'L':
        displayL();
        break;
    }
    switch (ch3)
    {
        case 'H':
        displayH();
        break;
        case 'O':
        displayO();
        break;
        case '!':
        displayExclamation();
        break;
        case 'E':
        displayE();
        break;
        case 'L':
        displayL();
        break;
    }
    switch (ch4)
    {
        case 'H':
        displayH();
        break;
        case 'O':
        displayO();
        break;
        case '!':
        displayExclamation();
        break;
        case 'E':
        displayE();
        break;
        case 'L':
        displayL();
        break;
    }
    switch (ch5)
    {
        case 'H':
        displayH();
        break;
        case 'O':
        displayO();
        break;
        case '!':
        displayExclamation();
        break;
        case 'E':
        displayE();
        break;
        case 'L':
        displayL();
        break;
    }
    switch (ch6)
    {
        case 'H':
        displayH();
        break;
        case 'O':
        displayO();
        break;
        case '!':
        displayExclamation();
        break;
        case 'E':
        displayE();
        break;
        case 'L':
        displayL();
        break;
    }
}

void rotate(char ch1, char ch2, char ch3, char ch4, char ch5, char ch6)
{
    char temp;
    temp = ch1;
    ch1 = ch2;
    ch2 = ch3;
    ch3 = ch4;
    ch4 = ch5;
    ch5 = ch6;
    ch6 = temp;
    display(ch1, ch2, ch3, ch4, ch5, ch6);
}    

int main()
{
    char ch1, ch2, ch3, ch4, ch5, ch6;
    cout << "Character #1 => "; 
    cin >> ch1;
    cout << "Character #2 => "; 
    cin >> ch2;
    cout << "Character #3 => "; 
    cin >> ch3;
    cout << "Character #4 => "; 
    cin >> ch4;
    cout << "Character #5 => "; 
    cin >> ch5;
    cout << "Character #6 => "; 
    cin >> ch6;

    cout << endl;

    display(ch1, ch2, ch3, ch4, ch5, ch6);
}

