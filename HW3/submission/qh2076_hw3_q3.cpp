#include <iostream>
#include <cmath>
using namespace std;

// To classify the possible solutions for ax^2 + bx + c = 0, we need to consider 4 cases:
// 1. a != 0, then we consider three cases:
//    (1) b^2 - 4ac > 0, we have two real solutions
//    (2) b^2 - 4ac = 0, we have one real solution
//    (3) b^2 - 4ac < 0, we have no real solution
// 2. a == 0, and b != 0, then we have bx + c = 0 and we have 1 real solution
// 3. a == 0, b == 0, and c != 0, then we have no solution
// 4. a == 0, b == 0, and c == 0, then we have infinite solutions


int main() {
    double a, b, c, solution1, solution2;
    cout << "Please enter value of a:";
    cin >> a;
    cout << "Please enter value of b:";
    cin >> b;
    cout << "Please enter value of c:";
    cin >> c;

    // if a != 0, then we check the value of check: (b * b) - (4 * a * c)
    if (a != 0) {
        double check = ((b * b) - (4 * a * c));
        // if check > 0, then we have two different solutions
        if (check > 0) {
            solution1 = ((b * (-1) + sqrt(check))) / (2 * a);
            solution2 = ((b * (-1) - sqrt(check))) / (2 * a);
            cout << "This equation has two real solutions, x1 = " << solution1
            << " x2 = " << solution2 << endl;
        }
        // if check = 0, then we have a solution
        else if (check == 0) {
            solution1 = (b * (-1)) / (2 * a);
            if (solution1 == -0) {
                solution1 += 0;
            }
            cout << "This equation has a single real solution, x = " << solution1 << endl;
        }
        // if check < 0, then we have no real solution
        else  {
            cout << "This equation has no real solution" << endl;
        }
    }

    // if a == 0, then we first check whether b != 0
    else {
        // if a == 0 and b != 0, then we have one solution
        if (b != 0) {
            solution1 = (c * (-1)) / b;
            cout << "This equation has a single real solution, x = " << solution1 << endl;
        }
        // if a == 0, b == 0, then we check the value of c
        else {
            // if a == 0, b == 0, and c != 0, then we have no solution
            if (c != 0) {
                cout << "This equation has no solution" << endl;
            }
            // if a == 0, b == 0, and c == 0, then we have infinite number of solutions
            else {
                cout << "This equation has infinite number of solutions" << endl;
            }
        }
    }
    return 0;
}
