#include <iostream>
#include <string>
using namespace std;

const int LETTER_NUMBER = 26;

void analyzeInput(string input, int letter[]);
bool compareString(const int letter1[], const int letter2[]);

int main() {
    string input1, input2;
    int letter1[LETTER_NUMBER] = {0}, letter2[LETTER_NUMBER] = {0};
    cout << "Enter the first sentence:" << endl;
    getline(cin, input1);
    cout << "Enter the second sentence:" << endl;
    getline(cin, input2);
    analyzeInput(input1, letter1);
    analyzeInput(input2, letter2);
    if (compareString(letter1, letter2)) {
        cout << "They are anagrams" << endl;
    }
    else {
        cout << "They are not anagrams" << endl;
    }
    return 0;
}

void analyzeInput(string input, int letter[]){
    int len = input.length();
    for (int i = 0; i < len; i++) {
        if (input[i] != ' ' && input[i] != ',' && input[i] != '.') {
            if (input[i] <= 'z' && input[i] >= 'a') {
                letter[input[i] - 'a']++;
            }
            else if (input[i] <= 'Z' && input[i] >= 'A') {
                letter[input[i] - 'A']++;
            }
        }
    }
}

bool compareString(const int letter1[], const int letter2[]) {
    for (int i = 0; i < LETTER_NUMBER; i++) {
        if (letter1[i] != letter2[i]) {
            return false;
        }
    }
    return true;
}
