#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double num, answer;
    int option;
    cout << "Please enter a Real number:" << endl;
    cin >> num;

    cout << "Choose your rounding method:\n"
            "1. Floor round\n"
            "2. Ceiling round\n"
            "3. Round to the nearest whole number" << endl;
    cin >> option;

    switch(option) {
        case FLOOR_ROUND:
            // first check whether the number is positive or negative
            if (num >= 0) {
                answer = (int)num;
            }
            else {
                answer = (int)num - 1;
            }
            break;
        case CEILING_ROUND:
            // first check whether the number is positive or negative
            if (num >= 0 && num - (int)num > 0) {
                answer = (int)num + 1;
            }
            else {
                answer = (int)num;
            }
            break;
        case ROUND:
            // first check whether the number is positive or negative
            if (num >= 0) {
                // if the number adding 0.5 is larger than or equal to its ceiling number
                // then it's near to its ceiling number
                if ((num + 0.5) >= ((int)num + 1)) {
                    answer = (int)num + 1;
                }
                    // if the number adding 0.5 is less than its ceiling number
                    // then it's near to its floor number
                else {
                    answer = (int)num;
                }
            }
            else {
                // if the negative number subtracting 0.5 is less than or equal to its floor number
                // then it's near to its floor number
                if ((num - 0.5) <= ((int)num - 1)) {
                    answer = (int)num - 1;
                }
                    // if the negative number subtracting 0.5 is larger than its ceiling number
                    // then it's near to its ceiling number
                else {
                    answer = (int)num;
                }
            }
            break;
        default:
            answer = 0;
            cout << "Please restart the program and enter 1 or 2 or 3" << endl;
            break;
    }

    cout << answer;
    return 0;
}
