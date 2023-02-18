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

void createGrid(int rows, int columns, int z);
void displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health);

void command();
void start();

void up();
void down();
void left();
void right();

int rows, columns, z;
int zombiePlaced = 0;
int a_row, a_col;

vector<vector<char>> grid;
int zombie_health = rand() % 100 + 1;
int alien_health = zombie_health + 20 + rand() % 10;

string com;
string movement;
int main()
{
    intro();
    selection();
    do
    {
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

    createGrid(rows, columns, z);
    displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health);
    start();
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
        cout << "Please customise the setting of the game first\n";
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
                createGrid(rows, columns, z);
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

void createGrid(int rows, int columns, int z)
{
    srand(time(0));
    int midRow = (rows + 1) / 2;
    int midCol = (columns + 1) / 2;
    int zombiePlaced = 0;
    grid = vector<vector<char>>(rows, vector<char>(columns));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (i == midRow - 1 && j == midCol - 1)
            {
                grid[i][j] = 'A';
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

    int a_row = midRow - 1;
    int a_col = midCol - 1;

    displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health);
}
void displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health)
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

    cout << "Alien Health: " << alien_health << endl;
    cout << "Zombie Health: " << zombie_health << endl;
    cout << " " << endl;
    cout << "Enter command: ";
    cin >> com;
    cout << " " << endl;
    command();
}

void start()
{
    cout << "The options for moving the alien are: up, down, left, right" << endl;
    while (true)
    {
        cout << "Enter the direction that you want to move (or enter a command): ";
        cin >> movement;
        cout << " " << endl;

        if (movement == "up")
        {
            up();
        }
        else if (movement == "down")
        {
            down();
        }
        else if (movement == "left")
        {
            left();
        }
        else if (movement == "right")
        {
            right();
        }
        else
        {
            start();
        }

        displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health);
    }
}

void command()
{
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
        displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health);
    }
}

void moveAlien(string move, vector<vector<char>> grid, int rows, int columns, int& a_row, int& a_col, int& alien_health) 
{
    if (move == "up") 
    {
        while (a_row - 1 >= 0 && grid[a_row - 1][a_col] != '|' && grid[a_row - 1][a_col] != '-') {
            if (grid[a_row - 1][a_col] == 'R') {
                alien_health += 5;
                grid[a_row - 1][a_col] = 'A'; // Replace the rock with the alien
                grid[a_row][a_col] = ' ';     // Clear the original position of the alien
                a_row--;                      // Move the alien to the new position
                break;
            } 
            else 
            {
                grid[a_row][a_col] = ' ';
                a_row--;
                grid[a_row][a_col] = 'A';
            }
        }
        displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health); // Display the updated grid
    } 
    else if (move == "down") {
        while (a_row + 1 < rows && grid[a_row + 1][a_col] != '|' && grid[a_row + 1][a_col] != '-') {
            if (grid[a_row + 1][a_col] == 'R') {
                alien_health += 5;
                grid[a_row + 1][a_col] = 'A'; // Replace the rock with the alien
                grid[a_row][a_col] = ' ';     // Clear the original position of the alien
                a_row++;                      // Move the alien to the new position
                break;
            } else {
                grid[a_row][a_col] = ' ';
                a_row++;
                grid[a_row][a_col] = 'A';
            }
        }
        displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health); // Display the updated grid
    } 
    else if (move == "left") {
        while (a_col - 1 >= 0 && grid[a_row][a_col - 1] != '|' && grid[a_row][a_col - 1] != '-') {
            if (grid[a_row][a_col - 1] == 'R') {
                alien_health += 5;
                grid[a_row][a_col - 1] = 'A'; // Replace the rock with the alien
                grid[a_row][a_col] = ' ';     // Clear the original position of the alien
                a_col--;                      // Move the alien to the new position
                break;
            } else {
                grid[a_row][a_col] = ' ';
                a_col--;
                grid[a_row][a_col] = 'A';
            }
        }
        displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health); // Display the updated grid
    } 
    else if (move == "right") {
        while (a_col + 1 < columns && grid[a_row][a_col + 1] != '|' && grid[a_row][a_col + 1] != '-') {
            if (grid[a_row][a_col + 1] == 'R') {
                alien_health += 5;
                grid[a_row][a_col + 1] = 'A'; // Replace the rock with the alien
                grid[a_row][a_col] = ' ';     // Clear the original position of the alien
                a_col++;                      // Move the alien to the new position
                break;
            } else {
                grid[a_row][a_col] = ' ';
                a_col++;
                grid[a_row][a_col] = 'A';
            }
        }
        displayGrid(vector<vector<char>> grid, int rows, int columns, int alien_health, int zombie_health); // Display the updated grid
    }
}
