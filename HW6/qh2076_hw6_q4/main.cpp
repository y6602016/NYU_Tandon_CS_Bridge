#include <iostream>
#include <cmath>
using namespace std;

// section a
void printDivisors(int num);

// section b
int main() {
    int num2;
    cout << "Please enter a positive number >= 2:" << endl;
    cin >> num2;
    printDivisors(num2);
    return 0;
}

// section a
void printDivisors(int num) {
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    for (int i = sqrt(num); i >= 1; i--) {
        if (num % i == 0 && num / i != i) {
            cout << num / i << " ";
        }
    }
}