#include <iostream>
#include <string>
using namespace std;

// section 1
bool isPalindrome(string str);

// section 2
int main() {
    string str;
    cout << "Please enter a word:";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout << str << " is a palindrome";
    }
    else {
        cout << str << " is not a palindrome";
    }
    return 0;
}

// section 1
bool isPalindrome(string str) {
    int low = 0, high = str.length() - 1;
    while (low < high) {
        if (str[low++] != str[high--]) {
            return false;
        }
    }
    return true;
}
