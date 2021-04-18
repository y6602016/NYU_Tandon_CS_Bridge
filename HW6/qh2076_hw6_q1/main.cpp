#include <iostream>
using namespace std;

// section 1
int fib(int n);

// section 2
int main() {
    int num;
    cout << "Please enter a positive integer:";
    cin >> num;
    cout << fib(num);
    return 0;
}

// section 1
int fib(int n) {
    int fn_2 = 1, fn_1 = 1, ans, count = 3;
    if (n == 1 || n == 2) {
        return 1;
    }
    else {
        while (count <= n) {
            ans = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = ans;
            count ++;
        }
        return ans;
    }
}