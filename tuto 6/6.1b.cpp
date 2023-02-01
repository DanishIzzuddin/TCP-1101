#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int totalSecrets = 4;
    int secret1, secret2, secret3, secret4;
    int guess1, guess2, guess3, guess4;
    // srand(time(NULL)); // in actual play
    srand(98189812); // for testing
    secret1 = rand() % 6 + 1;
    secret2 = rand() % 6 + 1;
    secret3 = rand() % 6 + 1;
    secret4 = rand() % 6 + 1;
    // For testing purpose only
    cout << "secrets = " << secret1 << " "
         << secret2 << " " << secret3 << " " << secret4 << endl;
    cout << "I have 4 Secret Numberds!" << endl;
    cout << "Each number is in range of 1 to 6." << endl;
    cout << "there maybe a repeating number" << endl;

    cout << endl;
    bool win = false;
    int maxTrials = 10;
    int trialNum = 1;
    while (trialNum <= maxTrials)
    {
        cout << "Trial number = " << trialNum << endl;
        int totalCorrect = 0;
        cout << "Your guesses => ";
        cin >> guess1 >> guess2 >> guess3 >> guess4;
        cout << "guesses = " << guess1 << " "
             << guess2 << " " << guess3 << " " << guess4 << endl;

        if (guess1 == secret1)
        {
            totalCorrect = totalCorrect + 1;
        }
        if (guess2 == secret2)
        {
            totalCorrect = totalCorrect + 1;
        }
        if (guess3 == secret3)
        {
            totalCorrect = totalCorrect + 1;
        }
        if (guess4 == secret4)
        {
            totalCorrect = totalCorrect + 1;
        }
        cout << "Total correct = " << totalCorrect << endl;
        cout << endl;
        if (totalCorrect == totalSecrets)
        {
            win = true;
            break;
        }
        trialNum = trialNum + 1;
    }
    if (win)
    {
        cout << "You Win!" << endl;
    }
    else
    {
        cout << "You Lose!" << endl;
    }
}