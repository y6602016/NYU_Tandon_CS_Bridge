#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int PIN_NUMBER[5]= {0,6,4,2,1};
const int PIN_LENGTH = 5;
const int RANDOM_ASSIGN_NUMBER = 10;

// I break down the program into two functions:
// 1. generate a list of random numbers for corresponding
// 2. convert the user input into an array
// 3. verify the user input to check whether it's valid
void generateRandom(int randomNumber[], int arrSize);
void generateUserArr(int userInputArr[], int arrSize, int userInput);
bool verifyNumber(const int userInputArr[], int pinLength, const int randomNumber[], const int pinNumber[]);

int main() {
    int userInput, userInputArr[PIN_LENGTH],randomNumber[RANDOM_ASSIGN_NUMBER];
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN:\t0 1 2 3 4 5 6 7 8 9"<< endl;
    cout << "NUM:\t";
    generateRandom(randomNumber, RANDOM_ASSIGN_NUMBER);
    cout << endl;
    cin >> userInput;
    generateUserArr(userInputArr, PIN_LENGTH, userInput);
    if (verifyNumber(userInputArr, PIN_LENGTH ,randomNumber, PIN_NUMBER)) {
        cout << "Your PIN is correct";
    }
    else {
        cout << "Your PIN is not correct";
    }
    return 0;
}

void generateRandom(int randomNumber[], int arrSize) {
    srand(time(0));
    int random;
    for (int i = 0; i < arrSize; i++) {
        random = (rand() % 3) + 1;
        randomNumber[i] = random;
        cout << random << " ";
    }
}

void generateUserArr(int userInputArr[], int arrSize, int userInput) {
    for (int i = arrSize - 1; i >= 0; i--) {
        userInputArr[i] = userInput % 10;
        userInput /= 10;
    }
}


bool verifyNumber(const int userInputArr[], int pinLength, const int randomNumber[], const int pinNumber[]) {
    for (int i = 0; i < pinLength; i++) {
        int verifiedNum = randomNumber[pinNumber[i]];
        if (verifiedNum != userInputArr[i]) {
            return false;
        }
    }
    return true;
}