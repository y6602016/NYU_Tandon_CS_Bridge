#include <iostream>
using namespace std;

// set up the conversion value of different coin values
const int QUARTER_TO_CENT = 25;
const int DIME_TO_CENT = 10;
const int PENNY_TO_CENT = 1;
const int NICKEL_TO_CENT = 5;
const int CENT_TO_DOLLAR = 100;

int main() {
    int quarters, dimes, nickels, pennies, totalCents, dollars, remainCents;

    cout << "Please enter number of coins:" << endl;
    cout << "# of quarters:";
    cin >> quarters;
    cout << "# of dimes:";
    cin >> dimes;
    cout << "# of nickels:";
    cin >> nickels;
    cout << "# of pennies:";
    cin >> pennies;

    // convert the quarters, dimes, nickels and pennies into cents
    totalCents = (quarters * QUARTER_TO_CENT) + (dimes * DIME_TO_CENT) + (nickels * NICKEL_TO_CENT)
                 + (pennies * PENNY_TO_CENT);

    // convert the cents into dollars
    dollars = totalCents / CENT_TO_DOLLAR;

    // keep the remaining cents
    remainCents = totalCents % CENT_TO_DOLLAR;

    cout << "The total is " << dollars << " dollars and " << remainCents << " cents";
    return 0;
}
