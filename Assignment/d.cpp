#include <iostream>
using namespace std;
#include <iomanip>

void createGrid(int rows, int columns) {
    int space = 3;
    cout << "  ";
    for (int i = 1; i <= columns; i++) {
        cout << i << "   ";
    }
    cout << endl;
    for (int i = 0; i < columns*2; i++) {
        if(i%2==0)
        cout << "-";
        else
        cout << "-";
        if(i%2!=0)
        cout << "-";
        else
        cout << "-";
    }
    cout << endl;
    for (int i = 1; i <= rows; i++) {
        cout << setw(space+1) << i << "|";
        for (int k = 0; k < space; k++) {
            cout << " ";
        }
        for (int j = 1; j <= columns; j++) {
            cout << "|";
            for (int k = 0; k < space; k++) {
                cout << " ";
            }
        }
        cout << endl;
        for (int i = 0; i < columns*2; i++) {
            if(i%2==0)
            cout << "-";
            else
            cout << "-";
            if(i%2!=0)
            cout << "-";
            else
            cout << "-";
        }
        cout << endl;
    }

}

int main()
{
    int r, c;
    do
    {
        cout << "Enter the number of rows: ";
        cin >> r;
        cout << "Enter the number of columns: ";
        cin >> c;
        if (r % 2 == 0 , c % 2 == 0)
            cout << "Please enter odd numbers for the rows and columns" << endl;
    } while (r % 2 == 0 , c % 2 == 0);
    createGrid(r, c);
    return 0;
}

/* Grid */