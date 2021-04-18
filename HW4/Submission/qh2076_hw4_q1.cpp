#include <iostream>
using namespace std;

// set a constant number as even base
const int EVEN = 2;

int main() {
    // section a is the while loop version
    cout << "Section a" << endl;
    int numA, count = 1;
    cout << "Please enter a positive integer:";
    cin >> numA;
    while (count <= numA) {
        cout << EVEN * count << endl;
        count ++;
    }
    cout << endl;

    // section b is the for loop version
    int numB;
    cout << "Section b" << endl;
    cout << "Please enter a positive integer:";
    cin >> numB;
    for (int i = 1; i <= numB; i++) {
        cout << EVEN * i << endl;
    }

    return 0;
}
