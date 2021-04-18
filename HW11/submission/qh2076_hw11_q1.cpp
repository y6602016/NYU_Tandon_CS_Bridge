#include <iostream>
using namespace std;

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {
    cout << "printTriangle function:" << endl;
    printTriangle(4);
    cout << "\nprintOppositeTriangles function:" << endl;
    printOppositeTriangles(4);
    cout << "\n\nprintRuler function:" << endl;
    printRuler(4);
    return 0;
}

void printTriangle(int n) {
    if (n == 1) {
        cout << "*" << endl;
    }
    else {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printOppositeTriangles(int n) {
    if (n == 1) {
        cout << "*" << endl;
        cout << "*" ;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
        printOppositeTriangles(n - 1);
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
    }
}

void printRuler(int n) {
    if (n == 1) {
        cout << "-";
    }
    else {
        printRuler(n - 1);
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << endl;
        printRuler(n - 1);
    }
}