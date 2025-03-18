#include <iostream>
#include <ctime>
#include <windows.h>

char playerValidSymbol(char playerChoice);

using namespace std;

int main() {

    char playerChoice;

    int playerDiff, playerAttemptsLimit;

        cout << "Welcome to the Number Guessing Game!\n" << endl;
        cout << "I'm thinking of a number between 1 and 100." << endl << "You have 5 chances to guess the correct number." << endl;
    do {
        cout << "\nPlease select the difficulty level:\n";
        cout << "1. Easy (10 chances)\n" << "2. Medium (5 chances)\n" << "3. Hard (3 chances)\n" << endl;
        cout << "Enter your choice:"; cin >> playerDiff;

        switch (playerDiff) {
        case 1:
            playerAttemptsLimit = 10;
            cout << "Great! You have selected the Easie difficulty level.";
                break;
        case 2:
            playerAttemptsLimit = 5;
            cout << "Great! You have selected the Medium difficulty level.";
            break;
        case 3:
            playerAttemptsLimit = 3;
            cout << "Great! You have selected the Hard difficulty level.";
            break;
      } 

        int i_guessNum, i_guess;

        
            int i_attempts = 0;

        srand(time(NULL));
        i_guessNum = (rand() % 50) + 1;
     

        cout << "\nLet's start the game!\n";

        do {
            
            cout << "\n\Enter your guess: "; 

            cin >> i_guess;

            i_attempts++;
            if (i_guess < i_guessNum) {
                cout << "Incorrect! The number is greater than " << i_guess << "." << endl;
            }
            else if (i_guess > i_guessNum) {
                cout << "Incorrect! The number is less than " << i_guess << "." << endl;
            }
            else if (i_guess == i_guessNum){

                cout << "\nCongratulations! You guessed the correct number in " << i_attempts << " attempts." << endl;
                i_attempts = 0;
                break;
            }

        } while (i_guess != i_guessNum && i_attempts < playerAttemptsLimit);

        if (i_guess != i_guessNum) {
            cout << "\nYou've used all attempts! The correct number was " << i_guessNum << "." << endl;
        }

        do {
            cout << "\n\nDo you wanna continue? (Y/N): ";
            cin >> playerChoice;

            playerValidSymbol(playerChoice);

        } while (playerChoice != 'Y' && playerChoice != 'y' && playerChoice != 'N' && playerChoice != 'n');

            

    } while (playerChoice == 'Y' || playerChoice == 'y');

    return 0;
}



char playerValidSymbol(char playerChoice) {
    if ((playerChoice != 'Y' && playerChoice != 'y') && (playerChoice != 'N' && playerChoice != 'n')) {
        cout << "\nWrong character. Please enter 'Y' to continue or 'N' to exit ";
    } else
     return playerChoice;
}
