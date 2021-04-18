#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    // section a
    cout << "section a" << endl;
    int len, numA, numSumA = 1;
    double resultA;
    cout << "Please enter the length of the sequence:" << endl;
    cin >> len;
    cout << "Please enter your sequence:" << endl;
    // read the input and multiply all of them
    for (int i = 0; i < len; i++) {
        cin >> numA;
        numSumA *= numA;
    }
    // if len = 0, print 0
    if (len == 0) {
        resultA = 0;
    }
    else {
        resultA = pow((double)numSumA, 1 / (double)len);
    }
    cout << "The geometric mean is: " << fixed << setprecision(4) << resultA << endl;
    cout << endl;


    // Section b
    cout << "section b" << endl;
    int numB = 0, numSumB = 1, count = 0;
    double resultB;
    // We set a flag variable named end to check whether the input is -1
    bool end = false;
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line."
            " End your sequence by typing -1:" << endl;
    while (end == false) {
        cin >> numB;
        // if the input is -1, end = true, and jump out the loop
        if (numB == -1) {
            end = true;
        }
        else {
            numSumB *= numB;
            count++;
        }
    }
    // if count is 0, print 0
    if (count == 0) {
        resultB = 0;
    }
    else {
        resultB = pow((double)numSumB, 1 / (double)count);
    }
    cout << "The geometric mean is: " << fixed << setprecision(4) << resultB << endl;
    return 0;
}
