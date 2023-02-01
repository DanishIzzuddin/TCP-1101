// **
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT10L
// Names: SIVAHARRIHARANN A/L RAMANATHAN_1 | AHMAD DANISH IZZUDDIN BIN MOHD ANAS ZAHARI_2 | Muhammad Arief Fahmi Bin Syahril Anuar_3
// IDs: 1211101643_1 | 1211103286_2 | 1211100528_3
// Emails: 1211101643@student.mmu.edu.my_1 | 1211103286@student.mmu.edu.my_2 | 1211100528@student.mmu.edu.my_3
// Phones: 0105090887_1 | 0166319282_2 | +60 12-444 5379_3
// **

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
#include <iomanip>

void intro()
{
    string x;
    string greeting = "=============(>-<)===============\n";
    string greeting1 = " \n";
    string greeting2 = "|WELCOME TO GAME ALIEN VS ZOMBIE|\n";
    string greeting3 = "|WELCOME ";
    string greeting4 = " TO GAME ALIEN VS ZOMBIE|\n";
    string greeting5 = "===============(>-<)===================\n";
    cout << greeting;
    cout << greeting2;
    cout << greeting;
    cout << greeting1;
    cout << greeting1;
    cout << "Please enter your name: ";
    cin >> x;
    cout << greeting1;
    cout << greeting1;
    cout << greeting5;
    cout << greeting3 << x << greeting4;
    cout << greeting5;
    cout << greeting1;
    cout << greeting1;
}

void selection()
{
    char answer;
    cout << "Do you want to start the game (Y/N) :";
    cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        cout << "Have Fun!! :) \n";
        cout << "Please customise the setting of the game first\n";
    }
    else if (answer == 'N' || answer == 'n')
    {
        do
        {
            cout << "Are you sure you want to exit? (Y/N) :";
            cin >> answer;
            if (answer == 'Y' || answer == 'y')
            {
                exit(0);
            }
            else if (answer == 'N' || answer == 'n')
            {
                cout << "Let's start the game then!\n";
                cout << "Please customise the setting of the game first\n";
                break;
            }
            else
            {
                cout << "Invalid input, please enter Y or N\n";
            }
        } while (answer != 'Y' || answer != 'y' || answer != 'N' || answer != 'n');
    }
    else
    {
        cout << "Invalid input, please enter Y or N\n";
        selection();
    }
}

void createGrid(int rows, int columns, int z)
{
    srand(time(0));
    int midRow = (rows + 1) / 2;
    int midCol = (columns + 1) / 2;
    int zombiePlaced = 0;
    cout << "  ";
    for (int i = 1; i <= columns; i++)
    {
        cout << setw(3) << i << " ";
    }
    cout << endl;
    cout << "  ";
    for (int i = 0; i < (columns * 4) + 3; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 1; i <= rows; i++)
    {
        cout << setw(2) << i << " |";
        for (int j = 1; j <= columns; j++)
        {
            if (i == midRow && j == midCol)
            {
                cout << setw(3) << "A"
                     << "|";
            }
            else
            {
                int randomNum = rand() % 8;
                if (randomNum == 0 && zombiePlaced < z)
                {
                    cout << setw(3) << "Z"
                         << "|";
                    zombiePlaced++;
                }
                else if (randomNum == 1)
                {
                    cout << setw(3) << "R"
                         << "|";
                }
                else if (randomNum == 2)
                {
                    cout << setw(3) << "^"
                         << "|";
                }
                else if (randomNum == 3)
                {
                    cout << setw(3) << "<"
                         << "|";
                }
                else if (randomNum == 4)
                {
                    cout << setw(3) << ">"
                         << "|";
                }
                else if (randomNum == 5)
                {
                    cout << setw(3) << "v"
                         << "|";
                }
                /*else if (randomNum == 6)
                {
                    cout << setw(3) << "P"
                         << "|";
                }
                else if (randomNum == 7)
                {
                    cout << setw(3) << "H"
                         << "|";
                }*/
                else
                {
                    cout << setw(3) << " "
                         << "|";
                }
            }
        }
        cout << endl;
        cout << " ";
        for (int i = 0; i < (columns * 4) + 3; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
}

int main()
{
    intro();
    selection();
    int r, c, z;
    do
    {
        cout << "Enter the number of rows: ";
        cin >> r;
        cout << "Enter the number of columns: ";
        cin >> c;
        if (r % 2 == 0 || c % 2 == 0)
            cout << "Please enter odd numbers for the rows and columns" << endl;
    } while (r % 2 == 0, c % 2 == 0);
    do
    {
        cout << "Enter the amount of zombies that u want: ";
        cin >> z;
        if (z < 2 || z > 9)
        {
            cout << "Please enter a number between 2 and 9" << endl;
        }
    } while (z < 2 || z > 9);

    createGrid(r, c, z);
    return 0;
}
