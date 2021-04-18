#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int graduateYear, currentYear;

    cout << "Please enter your name:";
    cin >> name;

    cout << "Please enter your graduation year:";
    cin >> graduateYear;

    cout << "Please enter current year:";
    cin >> currentYear;

    // if the graduate year equals and less than the current year, then the student is graduated.
    if (graduateYear <= currentYear) {
        cout << name << ", you are graduated" << endl;
    }
    else {
        if (graduateYear - currentYear == 1) {
            cout << name << ", you are a Senior" << endl;
        }
        else if (graduateYear - currentYear == 2) {
            cout << name << ", you are a Junior" << endl;
        }
        else if (graduateYear - currentYear == 3) {
            cout << name << ", you are a Sophomore" << endl;
        }
        else if (graduateYear - currentYear == 4) {
            cout << name << ", you are a Freshman" << endl;
        }
        else {
            cout << name << ", you are not in college yet" << endl;
        }
    }

    return 0;
}
