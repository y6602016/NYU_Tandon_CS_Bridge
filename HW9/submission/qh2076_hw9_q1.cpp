#include <iostream>
#include <string>
using namespace std;
const int LETTER_NUMBER = 26;

int analyzeInput(string input, int letter[]);
void printAnswer(int wordCount, int letter[]);

int main() {
    string input;
    int letter[LETTER_NUMBER] = {0}, wordCount;
    cout << "Please enter a line of text:" << endl;
    getline(cin, input);
    wordCount = analyzeInput(input, letter);
    printAnswer(wordCount, letter);
    return 0;
}

int analyzeInput(string input, int letter[]){
    int wordCount = 0, len = input.length();
    for (int i = 0; i < len; i++) {
        if (input[i] != ' ' && input[i] != ',' && input[i] != '.') {
            if (input[i] <= 'z' && input[i] >= 'a') {
                letter[input[i] - 'a']++;
            }
            else if (input[i] <= 'Z' && input[i] >= 'A') {
                letter[input[i] - 'A']++;
            }
            if (input[i+1] == ' ' || input[i+1] == ','
            || input[i+1] == '.' || i + 1 == len) {
                wordCount++;
            }
        }
    }
    return wordCount;
}

void printAnswer(int wordCount, int letter[]){
    cout << wordCount << "\twords" << endl;
    for (int i = 0; i < LETTER_NUMBER; i++) {
        if (letter[i] > 0) {
            cout << letter[i] << "\t" << (char)('a'+i) << endl;
        }
    }
}