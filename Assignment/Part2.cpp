// **
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: TT10L
// Names: SIVAHARRIHARANN A/L RAMANATHAN_1 | AHMAD DANISH IZZUDDIN BIN MOHD ANAS ZAHARI_2 | Muhammad Arief Fahmi Bin Syahril Anuar_3
// IDs: 1211101643_1 | 1211103286_2 | 1211100528_3
// Emails: 1211101643@student.mmu.edu.my_1 | 1211103286@student.mmu.edu.my_2 | 1211100528@student.mmu.edu.my_3
// Phones: 0105090887_1 | 0166319282_2 | 0124445379_3
// **

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

void intro();
void selection();
void customization();

int rows, columns, z;
int zombiePlaced;
int midRow, midCol;
void createGrid();

vector<vector<char>> grid;

string com;
string movement;
string layout;
bool validCommand;
void command();
void start();

void AposRow();
void AposCol();

int alien_health, zombie_health;

int a_row, a_col;
void up();
void down();
void left();
void right();

int main()
{
    string eleh;
    intro();
    selection();
    cout << "-----------------" << endl;
    cout << "Default Settings!" << endl;
    cout << "-----------------" << endl;
    cout << "Number Of Rows : 5" << endl;
    rows = 5;
    cout << "Number Of Columns : 7" << endl;
    columns = 7;
    cout << "Number Of Zombie : 3" << endl;
    z = 3;
    cout << "Do you want to proceed with this setting (Y/N): " << endl;
    cin >> eleh;
    if (eleh == "Y" || eleh == "y")
    {
        cout << "Have Fun!! :) \n";
        cout << " " << endl;
        cout << " " << endl;
        createGrid();
    }
    else if (eleh == "N" || eleh == "n")
    {
        do
        {
            cout << "Please customise the setting of the game first\n";
            cout << " ";
            cout << " ";
            cout << "Enter the number of rows: ";
            cin >> rows;
            cout << "Enter the number of columns: ";
            cin >> columns;
            cout << " " << endl;
            if (rows % 2 == 0 || columns % 2 == 0)
                cout << "Please enter odd numbers for the rows and columns" << endl;
        } while (rows % 2 == 0, columns % 2 == 0);
        do
        {
            cout << "Enter the amount of zombies that u want: ";
            cin >> z;
            cout << " " << endl;
            if (z < 2 || z > 9)
            {
                cout << "Please enter a number between 2 and 9" << endl;
            }
        } while (z < 2 || z > 9);
        createGrid();
    }
    else
    {
        cout << "Invalid input, please enter Y or N\n";
        selection();
    }
}

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
        cout << " " << endl;
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
                cout << " " << endl;
                createGrid();
            }
            else
            {
                cout << "Invalid input, please enter Y or N\n";
            }
        } while (answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n');
    }
    else
    {
        cout << "Invalid input, please enter Y or N\n";
        selection();
    }
}

void createGrid()
{
    srand(time(0));
    midRow = (rows + 1) / 2;
    midCol = (columns + 1) / 2;
    zombie_health = rand() % 100 + 1;
    alien_health = zombie_health + 20 + rand() % 10;
    zombiePlaced = 0;
    a_row = midRow - 1;
    a_col = midCol - 1;
    grid = vector<vector<char>>(rows, vector<char>(columns));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == midRow - 1 && j == midCol - 1)
            {
                grid[i][j] = 'A';
            }
            else if (i == a_row && j == a_col)
            {
                cout << 'A' << "  ";
            }
            else if (i == a_row && j == a_col)
            {
                cout << grid[i][j] << "  ";
            }
            else
            {
                int randomNum = rand() % 8;
                if (randomNum == 0 && zombiePlaced < z)
                {
                    grid[i][j] = 'Z';
                    zombiePlaced++;
                }
                else if (randomNum == 1)
                {
                    grid[i][j] = 'R';
                }
                else if (randomNum == 2)
                {
                    grid[i][j] = '^';
                }
                else if (randomNum == 3)
                {
                    grid[i][j] = '<';
                }
                else if (randomNum == 4)
                {
                    grid[i][j] = '>';
                }
                else if (randomNum == 5)
                {
                    grid[i][j] = 'v';
                }
                else if (randomNum == 6)
                {
                    grid[i][j] = 'P';
                }
                else if (randomNum == 7)
                {
                    grid[i][j] = 'H';
                }
                else
                {
                    grid[i][j] = ' ';
                }
            }
        }
    }

    string layout;
    while (true)
    {
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
        for (int i = 0; i < rows; i++)
        {
            cout << setw(2) << i + 1 << " |";
            for (int j = 0; j < columns; j++)
            {
                cout << setw(3) << grid[i][j] << "|";
            }
            cout << endl;
            cout << " ";
            for (int i = 0; i < (columns * 4) + 3; i++)
            {
                cout << "-";
            }
            cout << endl;
        }
        if (zombiePlaced == 0)
        {
            cout << "Congratulations! You have finished the game." << endl;
            break;
        }
        else
            (zombiePlaced != 0);
        {
            start();
        }
    }
}

void AposRow()
{
    grid[a_row][a_col] = 'A';
}

void AposCol()
{
    grid[a_row][a_col] = 'A';
}

void start()
{
    cout << "Alien Health :" << alien_health << "\n";
    cout << "Zombie Health :" << zombie_health << "\n";
    cout << " " << endl;
    cout << "The options for moving the alien are: up, down, left, right" << endl;
    cout << " " << endl;
    cout << "Enter the direction that you want to move (or enter a help): ";
    cin >> movement;
    cout << " " << endl;

    validCommand = false;
    if (movement == "up")
    {
        up();
        validCommand = true;
    }
    else if (movement == "down")
    {
        down();
        validCommand = true;
    }
    else if (movement == "left")
    {
        left();
        validCommand = true;
    }
    else if (movement == "right")
    {
        right();
        validCommand = true;
    }
    else if (movement == "help")
    {
        command();
    }
    else
    {
        cout << "Invalid command, please enter up, down, left, right" << endl;
        start();
    }
}

void command()
{
    cout << "Enter command: \n";
    cin >> com;
    cout << " " << endl;

    bool validCommand = true;
    if (com == "start")
    {
        start();
    }
    else if (com == "arrow")
    {
        // Switch the direction of an arrow object
    }
    else if (com == "save")
    {
        // Save the current game to a file
    }
    else if (com == "load")
    {
        // Load a saved game from a file
    }
    else if (com == "quit")
    {
        // Quit the game while still in play
        std::cout << "Thanks for playing! Exiting the game..." << std::endl;
        // Call any necessary cleanup functions or close any resources
        exit(0); // This will immediately exit the program with a status code of 0
    }
    else if (com == "help" || com == "Help")
    {
        cout << " " << endl;
        cout << " " << endl;
        cout << "Commands: " << endl;
        cout << "Start - to move the alien" << endl;
        cout << "  up - Move alien up" << endl;
        cout << "  down - Move alien down" << endl;
        cout << "  left - Move alien left" << endl;
        cout << "  right - Move alien right" << endl;
        cout << "  arrow - Switch the direction of an arrow object" << endl;
        cout << "  save - Save the current game to a file" << endl;
        cout << "  load - Load a saved game from a file" << endl;
        cout << "  quit - Quit the game while still in play" << endl;
        cout << " " << endl;
        cout << " " << endl;
    }
    else
    {
        validCommand = false;
    }

    if (!validCommand)
    {
        cout << " " << endl;
        cout << "Invalid command entered." << endl;
        cout << " " << endl;
        command();
    }
}

void up()
{
    while (a_row - 1 >= 0 && grid[a_row - 1][a_col] != '|' && grid[a_row - 1][a_col] != '-')
    {
        if (grid[a_row - 1][a_col] == 'R')
        {
            alien_health += 5;
            grid[a_row - 1][a_col] = 'A'; // Replace the rock with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_row--;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row - 1][a_col] == 'Z')
        {
            grid[a_row - 1][a_col] = 'A'; // Replace the zombie with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_row--;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row - 1][a_col] == 'H')
        {
            alien_health += 10;
            grid[a_row][a_col] = ' ';
            a_row--;
            grid[a_row][a_col] = 'A';
        }
        else
        {
            grid[a_row][a_col] = ' ';
            a_row--;
            grid[a_row][a_col] = 'A';
        }
    }
}

void down()
{
    while (a_row + 1 < rows && grid[a_row + 1][a_col] != '|' && grid[a_row + 1][a_col] != '-')
    {
        if (grid[a_row + 1][a_col] == 'R')
        {
            alien_health += 5;            // Alien Health Increase by 5
            grid[a_row + 1][a_col] = 'A'; // Replace the rock with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_row++;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row + 1][a_col] == 'Z')
        {
            grid[a_row + 1][a_col] = 'A'; // Replace the zombie with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_row++;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row + 1][a_col] == 'H')
        {
            alien_health += 10;
            grid[a_row][a_col] = ' ';
            a_row++;
            grid[a_row][a_col] = 'A';
        }
        else
        {
            grid[a_row][a_col] = ' ';
            a_row++;
            grid[a_row][a_col] = 'A';
        }
    }
}

void left()
{
    while (a_col - 1 >= 0 && grid[a_row][a_col - 1] != '|' && grid[a_row][a_col - 1] != '-')
    {
        if (grid[a_row][a_col - 1] == 'R')
        {
            alien_health += 5;
            grid[a_row][a_col - 1] = 'A'; // Replace the rock with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_col--;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row][a_col - 1] == 'Z')
        {
            grid[a_row][a_col - 1] = 'A'; // Replace the zombie with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_row++;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row][a_col - 1] == 'H')
        {
            alien_health += 10;
            grid[a_row][a_col] = ' ';
            a_col--;
            grid[a_row][a_col] = 'A';
        }
        else
        {
            grid[a_row][a_col] = ' ';
            a_col--;
            grid[a_row][a_col] = 'A';
        }
    }
}

void right()
{
    while (a_col + 1 < columns && grid[a_row][a_col + 1] != '|' && grid[a_row][a_col + 1] != '-')
    {
        if (grid[a_row][a_col + 1] == 'R')
        {
            alien_health += 5;
            grid[a_row][a_col + 1] = 'A'; // Replace the rock with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_col++;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row][a_col + 1] == 'Z')
        {
            grid[a_row][a_col + 1] = 'A'; // Replace the zombie with the alien
            grid[a_row][a_col] = ' ';     // Clear the original position of the alien
            a_row++;                      // Move the alien to the new position
            break;
        }
        else if (grid[a_row][a_col + 1] == 'H')
        {
            alien_health += 10;
            grid[a_row][a_col] = ' ';
            a_col--;
            grid[a_row][a_col] = 'A';
        }
        else
        {
            grid[a_row][a_col] = ' ';
            a_col++;
            grid[a_row][a_col] = 'A';
        }
    }
}
