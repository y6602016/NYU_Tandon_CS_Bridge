#include <iostream>
using namespace std;

// set the parameters of one half and club card discounts
const double ONE_HALF = 0.5;
const double CLUB_CARD = 0.9;

int main() {
    double basePrice, price1, price2, sum, taxRate, total;
    char club;
    cout << "Enter price of first item:";
    cin >> price1;
    cout << "Enter price of second item:";
    cin >> price2;

    // store the base price
    basePrice = price1 + price2;

    // The lower price item has half price
    if (price1 < price2) {
        sum = (price1 * ONE_HALF) + price2;
    }
    else {
        sum = (price2 * ONE_HALF) + price1;
    }

    cout << "Does customer have a club card? (Y/N):";
    cin >> club;
    // if the answer is yes, additional 10% off
    if (club == 'Y' || club == 'y') {
        sum = sum * CLUB_CARD;
    }


    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax:";
    cin >> taxRate;
    // total price with tax added
    total = sum * (1 + (taxRate / 100));

    cout << "Base price:" << basePrice << endl;
    cout << "Price after discounts:" << sum << endl;
    cout << "Total price:" << total << endl;
    return 0;
}
