#include <iostream>
using namespace std;

// set up the conversion value of different coin values
const int CENT_TO_QUARTER = 25;
const int CENT_TO_DIME = 10;
const int CENT_TO_NICKEL = 5;
const int DOLLAR_TO_CENT = 100;

int main() {
    int quarters, dimes, nickels, pennies, cents, dollars, totalCents;
    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    // convert the dollars and cents into cents
    totalCents = (dollars * DOLLAR_TO_CENT) + cents;

    // calculate the quarter value and the remaining cents
    quarters = totalCents / CENT_TO_QUARTER;
    totalCents = totalCents - (quarters * CENT_TO_QUARTER);

    // calculate the dime value and the remaining cents
    dimes = totalCents / CENT_TO_DIME;
    totalCents = totalCents - (dimes * CENT_TO_DIME);

    // calculate the nickel value and the remaining cents
    // the value of remaining cents is the value of pennies
    nickels = totalCents / CENT_TO_NICKEL;
    pennies = totalCents - (nickels * CENT_TO_NICKEL);

    cout << dollars << " dollars and " << cents << " cents are:" << endl;
    cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and "
        << pennies << " pennies";
    return 0;
}
