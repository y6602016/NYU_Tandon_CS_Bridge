#include <iostream>
using namespace std;

// To convert the decimal number to the binary representation,
// we usually use a series of mod and division calculations.
// Ex: Convert decimal number 6 to binary representation
// 6 mod 2 = 0; (6 / 2 = 3)
// 3 mod 2 = 1; (3 / 2 = 1)
// 1 mod 2 = 1; (1 / 2 = 0)
// The binary representation of 6 is 110.
//
// However, to print out the result via a program, we need to reverse the order of getting the results
// We use two while loops (one is a nested loop) to calculate the results.
// We set a copy_num to store the input number, and set a base_line as a boundary to divide the copy_num
// 1. If the copy_num is less than the base_line, we reach out the smallest digit.
//      We end the inner while loop and print the mod of copy_num
// 2. If the base_line is larger than num * 2, end the outer while loop
// After every inner loop, we raise up the baseline by multiply 2, and reset the copy_num as the input number
// Ex: Convert decimal number 6 to binary representation
//      Iteration 1: base_line is initialized as 2, copy_num = 6
//                      6 >= 2, so 6/2 = 3;  3 >= 2, so 3/2 = 1; 1 < 2, so we print 1 % 2 = 1
//      Iteration 2: base_line raise up, 2 * 2 = 4. copy_num reset as 6
//                      6 >= 4, so 6/2 = 3; 3 < 4, so we print 3 % 2 = 1;
//      Iteration 3: base_line raise up, 4 * 2 = 8, copy_num reset as 6
//                      6 < 8, so we print 6 % 2 = 0
//      Iteration 4: base_line raise up, 8 * 2 = 16, which is larger than num * 2 = 6 * 2 = 12
//                    not executed

int main() {
    int num, copy_num, base_line = 2;
    cout << "Enter decimal number:" << endl;
    cin >> num;
    while (base_line <= (num * 2)) {
        copy_num = num;
        while (copy_num >= base_line) {
            copy_num /= 2;
        }
        cout << copy_num % 2;
        base_line *= 2;
    }
    return 0;
}
