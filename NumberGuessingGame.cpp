#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(time(0)); // random seed based on current time

    char playAgain = 'y';

    cout << "=====================================\n";
    cout << "     NUMBER GUESSING GAME (1-100)\n";
    cout << "=====================================\n";

    while (playAgain == 'y' || playAgain == 'Y') {

        int randomNumber = rand() % 100 + 1; // random number between 1 and 100
        int guess;
        int attempts = 0;
        bool guessedCorrectly = false;

        cout << "\nI have selected a number between 1 and 100.\n";
        cout << "Try to guess it!\n\n";

        while (!guessedCorrectly) {
            cout << "Enter your guess: ";

            // handle invalid (non-numeric) input
            if (!(cin >> guess)) {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            attempts++;

            if (guess < 1 || guess > 100) {
                cout << "Please guess a number within 1 and 100.\n";
            }
            else if (guess > randomNumber) {
                cout << "Too High! Try a smaller number.\n";
            }
            else if (guess < randomNumber) {
                cout << "Too Low! Try a bigger number.\n";
            }
            else {
                cout << "\nCorrect! The number was " << randomNumber << ".\n";
                cout << "You guessed it in " << attempts << " attempt(s).\n";
                guessedCorrectly = true;
            }
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}