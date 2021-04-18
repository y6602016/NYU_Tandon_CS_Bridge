#include <iostream>
using namespace std;

// section a
void printShiftedTriangle(int n, int m, char symbol);
// section b
void printPineTree(int n, char symbol);

int main() {
    int triangle;
    char symbol;
    cout << "Please enter the number of triangles:" << endl;
    cin >> triangle;
    cout << "Please enter the character (ex:+ or * or $):" << endl;
    cin >> symbol;
    printPineTree(triangle, symbol);
    return 0;
}


// section a
void printShiftedTriangle(int n, int m, char symbol) {
    int spaceCount = n - 1, starCount = 1;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            cout << " ";
        }
        for (int k = 0; k < spaceCount; k++) {
            cout << " ";
        }
        for (int k = 0; k < starCount; k++) {
            cout << symbol;
        }
        spaceCount--;
        starCount += 2;
        cout << endl;
    }
}


// section b
void printPineTree(int n, char symbol) {
    int lineCount = 2, spaceCount = n - 1;
    for (int i = 0; i < n; i++) {
        printShiftedTriangle(lineCount, spaceCount, symbol);
        lineCount++;
        spaceCount--;
    }
}
