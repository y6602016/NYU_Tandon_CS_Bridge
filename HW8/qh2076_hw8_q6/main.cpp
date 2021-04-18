#include <iostream>
#include <string>
using namespace std;

// I break down the program into one major function and two sub-functions
// 1. Analyze the input string
//      1-1. Check whether the word is a digit
//      1-2. Convert the digit into x

void analyzeStr(string & str);
bool isDigit(string & str, int & end);
void convertToX(string & str, int start, int end);

int main() {
    string str;
    cout << "Please enter a line of text:" << endl;
    getline(cin, str);
    analyzeStr(str);
    cout << str;
    return 0;
}

void analyzeStr(string & str) {
    for (int i = 0;i < str.length();i++){
        // if a digit appears, we check it
        if (str[i] <= '9' && str[i] >= '0' && (i == 0 || str[i - 1] == ' ')) {
                // the variable end is the index boundary of the word for checking
                int end = i;
                if (isDigit(str, end)) {
                    convertToX(str, i, end);
                }
                else {
                    i = end;
                }
        }
    }
}

bool isDigit(string & str, int & end) {
    // check whether it's a digit until the next space or the end of the string
    while (str[end] != ' ' && str[end] != '\0') {
        if (str[end] <= '9' && str[end] >= '0') {
            end++;
        }
        else {
            return false;
        }
    }
    return true;
}

void convertToX(string & str, int start, int end) {
    while (start < end) {
        str[start++] = 'x';
    }
}