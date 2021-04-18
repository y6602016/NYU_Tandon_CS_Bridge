#include <iostream>
#include <string>
using namespace std;

const double WORK_RATE = 0.4;
const double WORK_OFF_RATE = 0.25;
const double WEEKEND_RATE = 0.15;

int main() {
    string day;
    int hour, minute, length;
    double cost;
    char dot;
    cout << "Please enter the day of the week with two character string" << endl;
    cout << "(Mo / Tu / We / Th / Fr / Sa / Su):";
    cin >> day;

    cout << "\nPlease enter the time the call started" << endl;
    cout << "(The time is in 24-hour notation, ex: 13:30):";
    cin >> hour >> dot >> minute;

    cout << "\nPlease enter the length of the call in minutes:";
    cin >> length;

    // if the day is Sa or Su, it's rate is same no matter the time the call start
    if (day == "Sa" || day == "Su") {
        cost = (double)length * WEEKEND_RATE;
    }

    // if the day is between Mo and Fr, then we check the start time
    else {
        if ((hour >= 8 && hour <= 17) ||(hour == 18 && minute == 0)) {
            cost = (double)length * WORK_RATE;
        }
        else {
            cost = (double)length * WORK_OFF_RATE;
        }
    }

    cout << "The cost of the call is: " << cost;
    return 0;
}
