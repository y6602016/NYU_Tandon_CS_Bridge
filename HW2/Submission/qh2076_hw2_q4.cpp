#include <iostream>
using namespace std;

int main() {
    int numberA, numberB, add, subtract, multiply, div, mod;
    double divide;
    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> numberA >> numberB;

    // calculate the result of each calculation
    add = numberA + numberB;
    subtract = numberA - numberB;
    multiply = numberA * numberB;
    divide = (double)numberA / (double)numberB; // cast the integer for calculating division
    div = numberA / numberB;
    mod = numberA % numberB;

    cout << numberA << " + " << numberB << " = " << add << endl;
    cout << numberA << " - " << numberB << " = " << subtract << endl;
    cout << numberA << " * " << numberB << " = " << multiply << endl;
    cout << numberA << " / " << numberB << " = " << divide << endl;
    cout << numberA << " div " << numberB << " = " << div << endl;
    cout << numberA << " mod " << numberB << " = " << mod << endl;
    return 0;
}
