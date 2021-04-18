#include <iostream>
using namespace std;

// set up the conversion value of the minutes, hours and days
const int MINUTE_TO_HOUR = 60;
const int HOUR_TO_DAY = 24;

int main() {
    int johnWorkDays, johnWorkHours, johnWorkMinutes, billWorkDays, billWorkHours, billWorkMinutes,
        totalDays, totalHours, totalMinutes, overHours, overMinutes;

    cout << "Please enter the number of days John has worked:";
    cin >> johnWorkDays;
    cout << "Please enter the number of hours John has worked:";
    cin >> johnWorkHours;
    cout << "Please enter the number of minutes John has worked:";
    cin >> johnWorkMinutes;

    cout << "\nPlease enter the number of days Bill has worked:";
    cin >> billWorkDays;
    cout << "Please enter the number of hours Bill has worked:";
    cin >> billWorkHours;
    cout << "Please enter the number of minutes Bill has worked:";
    cin >> billWorkMinutes;

    // calculate the total minute, and convert every 60 minutes into 1 hour
    totalMinutes = johnWorkMinutes + billWorkMinutes;
    overMinutes = totalMinutes / MINUTE_TO_HOUR;
    totalMinutes = totalMinutes - (overMinutes * MINUTE_TO_HOUR);

    // calculate the total hours, and convert every 24 hours into 1 day
    totalHours = johnWorkHours + billWorkHours + overMinutes;
    overHours = totalHours / HOUR_TO_DAY;
    totalHours = totalHours - (overHours * HOUR_TO_DAY);

    // calculate the total days
    totalDays = johnWorkDays + billWorkDays + overHours;

    cout << "\nThe total time both of them worked together is: "<< totalDays << " days, "
        << totalHours << " hours and "<< totalMinutes << " minutes.";

    return 0;
}
