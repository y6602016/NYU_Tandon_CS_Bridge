#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int GUESS_TIME = 5;

int main() {
    int num, guess, leftGuessCount = 5, rangeLow = 1, rangeHigh = 100;
    bool correct = false;
    srand(time(0)); //NOLINT

    num = (rand() % 100) + 1;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;
    while (leftGuessCount > 0 && correct == false) {
        cout << "Range: [" << rangeLow << ", " << rangeHigh << "], Number of guesses left:" << leftGuessCount << endl;
        cout << "Your guess: ";
        cin >> guess;
        if (guess == num) {
            correct = true;
            leftGuessCount--;
        }
        else {
            if (guess > num) {
                rangeHigh = guess - 1;
                if (leftGuessCount > 1) {
                    cout << "Wrong! My number is smaller." << endl << endl;
                }
            }
            else if (guess < num) {
                rangeLow = guess + 1;
                if (leftGuessCount > 1) {
                    cout << "Wrong! My number is bigger." << endl << endl;
                }
            }
            leftGuessCount--;
        }
    }

    if (correct == true) {
        cout << "Congrats! You guessed my number in " << GUESS_TIME - leftGuessCount << " guesses.";
    }
    else {
        cout << "Out of guesses! My number is " << num << endl;
    }

    return 0;
}
