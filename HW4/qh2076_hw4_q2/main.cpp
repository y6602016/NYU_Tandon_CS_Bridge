#include <iostream>
using namespace std;

// set constant number as Roman digit number
const int ROMAN_I = 1;
const int ROMAN_V = 5;
const int ROMAN_X = 10;
const int ROMAN_L = 50;
const int ROMAN_C = 100;
const int ROMAN_D = 500;
const int ROMAN_M = 1000;

int main() {
    int num;
    cout << "Enter decimal number:" << endl;
    cin >> num;
    cout << num << " is:";

    // use a while loop to convert the number
    while (num > 0) {
        if (num >= ROMAN_M) {
            num -= ROMAN_M;
            cout << 'M';
        }
        else if (num >= ROMAN_D) {
            num -= ROMAN_D;
            cout << 'D';
        }
        else if (num >= ROMAN_C) {
            num -= ROMAN_C;
            cout << 'C';
        }
        else if (num >= ROMAN_L) {
            num -= ROMAN_L;
            cout << 'L';
        }
        else if (num >= ROMAN_X) {
            num -= ROMAN_X;
            cout << 'X';
        }
        else if (num >= ROMAN_V) {
            num -= ROMAN_V;
            cout << 'V';
        }
        else {
            num -= ROMAN_I;
            cout << 'I';
        }
    }
    return 0;
}
