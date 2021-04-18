#include <iostream>
#include <string>
using namespace std;


int main() {
    string firstName, middleName,lastName;
    cout << "Please Enter your first name, middle name or initial, last name" << endl;
    cin >> firstName;
    cin >> middleName;
    cin >> lastName;

    cout << lastName << ", " << firstName << " " << middleName[0] << ".";
    return 0;
}
