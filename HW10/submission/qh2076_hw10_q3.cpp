#include <iostream>
#include <vector>
using namespace std;

int * createArr(int & logicalSize);
void searchNum(int * arr, int logicalSize, int searchNumber);
void main1();

vector<int> createVector();
void searchNumVector(vector<int> arr, int searchNumber);
void main2();

int main() {
    main1();
    main2();
    return 0;
}

void main1() {
    int logicalSize = 0;
    cout<< "----main1----" << endl;
    int * arr = createArr(logicalSize);

    cout << "Please enter a number you want to search." << endl;
    int searchNumber;
    cin >> searchNumber;
    searchNum(arr, logicalSize, searchNumber);

    delete [] arr;
    arr = nullptr;
}

int * createArr(int & logicalSize) {
    int * arr = new int[1], physicalSize = 1, input;
    bool endOfInput = false;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;
    while (endOfInput == false) {
        cin >> input;
        if (input == -1) {
            endOfInput = true;
        }
        else {
            if (logicalSize == physicalSize) {
                // resize the array by doubling the size
                int * newArray = new int[physicalSize * 2];
                for (int i = 0; i < logicalSize; i++) {
                    newArray[i] = arr[i];
                }
                delete [] arr;
                arr = newArray;
                physicalSize *= 2;
            }
            arr[logicalSize++] = input;
        }
    }
    return arr;
}

void searchNum(int * arr, int logicalSize, int searchNumber) {
    bool noShow = true;
    for (int i = 0; i <= logicalSize; i++) {
        if (arr[i] == searchNumber) {
            if (noShow) {
                noShow = false;
                cout << searchNumber << " shows in lines " << i + 1;
            }
            else {
                cout << ", " << i + 1;
            }
        }
    }

    if (noShow) {
        cout << searchNumber << " does not show at all in the sequence.";
    }
    else {
        cout << ".";
    }
}



void main2() {
    cout<< "\n\n----main2----" << endl;
    vector<int> arr = createVector();

    cout << "Please enter a number you want to search." << endl;
    int searchNumber;
    cin >> searchNumber;
    searchNumVector(arr, searchNumber);
}

vector<int> createVector() {
    vector<int> arr;
    bool endOfInput = false;
    int input;
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;
    while (endOfInput == false) {
        cin >> input;
        if (input == -1) {
            endOfInput = true;
        }
        else {
            arr.push_back(input);
        }
    }
    return arr;
}

void searchNumVector(vector<int> arr, int searchNumber) {
    bool noShow = true;
    for (int i = 0; i <= arr.size(); i++) {
        if (arr[i] == searchNumber) {
            if (noShow) {
                noShow = false;
                cout << searchNumber << " shows in lines " << i + 1;
            }
            else {
                cout << ", " << i + 1;
            }
        }
    }

    if (noShow) {
        cout << searchNumber << " does not show at all in the sequence.";
    }
    else {
        cout << ".";
    }
}
