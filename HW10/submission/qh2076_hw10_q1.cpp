#include <iostream>
#include <string>
using namespace std;

string * createWordsArray(string sentence, int& outWordsArrSize);
int countWords(string sentence);
void printArray(string * wordsArray, int arrSize);

int main() {
    string str;
    cout << "Please enter a sentence: " << endl;
    getline(cin, str);

    int outWordsArrSize;
    string * wordsArray = createWordsArray(str, outWordsArrSize);
    printArray(wordsArray, outWordsArrSize);

    delete [] wordsArray;
    wordsArray = nullptr;

    return 0;
}

string * createWordsArray(string sentence, int& outWordsArrSize) {
    // call countWords function to count the words.
    outWordsArrSize = countWords(sentence);

    // use the result of countWords function as the size to create an array
    string * wordsArray = new string[outWordsArrSize];
    int wordStart = 0, i = 0;

    // in case that the sentence starting with spaces
    // ex: "  You can do it"
    while(sentence[wordStart] == ' ') {
        wordStart++;
    }

    // use find() and substr()
    // find the space starting from the wordStart index
    // then store the value of sentence.find(' ', wordStart), which is the index of the space
    // then we put the sub-string from the wordStart index to the indexOfSpace index - 1 into the array
    // set wordStart index as indexOfSpace + 1 for the next space finding
    while(sentence.find(' ', wordStart) != string::npos) {
        int indexOfSpace = sentence.find(' ', wordStart);
        wordsArray[i++] = sentence.substr(wordStart, indexOfSpace - wordStart);
        wordStart = (int)sentence.find(' ', wordStart) + 1;
    }

    // the last word will be ignore by the above while loop
    // we need to put the last word into the array
    if (i == outWordsArrSize - 1) {
        wordsArray[i] = sentence.substr(wordStart, sentence.length() - wordStart);
    }

    return wordsArray;
}

int countWords(string sentence) {
    // the words are separated by the single space
    // count the words by checking the space or the end of the sentence
    int wordsCount = 0;
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {
            if (sentence[i + 1] == ' ' || i + 1 == sentence.length()) {
                wordsCount++;
            }
        }
    }
    return wordsCount;
}

void printArray(string * wordsArray, int outWordsArrSize) {
    cout << "The logical size is: " << outWordsArrSize << endl;
    cout << "The array is: [";
    for (int i = 0; i < outWordsArrSize; i++) {
        cout << "\"" << wordsArray[i] << "\"";
        if (i < outWordsArrSize - 1) {
            cout << ",";
        }
    }

    cout << "]";
}
