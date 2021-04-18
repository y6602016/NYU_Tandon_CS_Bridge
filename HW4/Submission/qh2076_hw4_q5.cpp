#include <iostream>
using namespace std;

// To print a hourglass mode with 2n lines, we divide the mode into two parts: upper part and lower part
// For the upper part, it has n lines. And for line i, it has 2n - 2i - 1 stars, i >= 0 and <= n-1.
// ex: When n = 4, i = 0, star: 8 - 0 - 1 = 7.  When i = 1, star: 8 - 2 - 1 = 5. And so on.
// The lower part applies the reverse but similar rule.

int main() {
    int n, headSpace, star, tailSpace;
    cout << "Please enter a positive number:" << endl;
    cin >> n;
    // Upper part
    for (int i = 0; i < n; i++) {
        for (headSpace = 0; headSpace < i; headSpace++) {
            cout << " ";
        }
        for (star = 0; star < (2 * n - i * 2 - 1); star++) {
            cout <<"*";
        }
        for (tailSpace = 0; tailSpace < i; tailSpace++) {
            cout << " ";
        }
        cout << endl;
    }

    // Lower part
    for (int i = n - 1; i >= 0; i--) {
        for (headSpace = 0; headSpace < i; headSpace++) {
            cout << " ";
        }
        for (star = 0; star < (2 * n - i * 2 - 1); star++) {
            cout <<"*";
        }
        for (tailSpace = 0; tailSpace < i; tailSpace++) {
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
