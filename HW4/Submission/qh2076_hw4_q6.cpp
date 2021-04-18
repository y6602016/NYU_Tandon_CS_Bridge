#include <iostream>
using namespace std;

// To find the numbers that with more even digits, we calculate the number of
// even digit and the number of odd digit of every number.

int main() {
    int num, allNum = 1;
    cout << "Please enter a positive number" << endl;
    cin >> num;
    if (num == 1) {
        cout << "none";
        return 0;
    }
    while(allNum <= num) {
        // We set variable oddCount and evenCount to count the number of even and odd digit
        int oddCount = 0, evenCount = 0, copyNum = allNum;
        // We use the copyNum to calculate
        while (copyNum > 0) {
            if (copyNum % 2 == 0) {
                evenCount++;
            }
            else {
                oddCount++;
            }
            copyNum /= 10;
        }
        // if it has more even digits, print it
        if (evenCount > oddCount) {
            cout << allNum << endl;
        }
        allNum++;
    }
    return 0;
}
