#include <iostream>
using namespace std;

const int MONTHS = 12;
const int LEAP_YEAR_DAYS = 29;
const int NON_LEAP_DAYS = 28;
const int BIG_MONTH = 31;
const int SMALL_MONTH = 30;


// section a
int printMonthCalender(int numOfDays, int startingDay);

// section b
bool leapYear(int year);

// section c
void printYearCalender(int year, int startingDay);


int main() {
    int year, startDay;
    cout << "Please enter the year:" << endl;
    cin >> year;
    cout << "Please enter the start day of January(from 1 to 7):" << endl;
    cin >> startDay;
    printYearCalender(year, startDay);
    return 0;
}

// section a
int printMonthCalender(int numOfDays, int startingDay) {
    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
    for (int i = 1; i < startingDay; i++) {
        cout << " \t";
    }
    int weekDay = startingDay - 1;
    for (int i = 1; i <= numOfDays; i++) {
        if (weekDay == 7) {
            cout << endl;
            weekDay = 0;
        }
        cout << i << "\t";
        weekDay++;
    }
    return weekDay;
}

// section b
bool leapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0 && year % 400 != 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

// section c
void printYearCalender(int year, int startingDay) {
    for (int month = 1; month <= MONTHS; month++) {
        if (startingDay == 8) {
            startingDay = 1;
        }
        switch(month) {
            case 1:
                cout << "January " << year << endl;
                startingDay = printMonthCalender(BIG_MONTH, startingDay) + 1;
                break;
            case 2:
                cout << "February " << year << endl;
                if (leapYear(year)) {
                    startingDay = printMonthCalender(LEAP_YEAR_DAYS, startingDay) + 1;
                }
                else {
                    startingDay = printMonthCalender(NON_LEAP_DAYS, startingDay) + 1;
                }
                break;
            case 3:
                cout << "March " << year << endl;
                startingDay = printMonthCalender(BIG_MONTH, startingDay) + 1;
                break;
            case 4:
                cout << "April " << year << endl;
                startingDay = printMonthCalender(SMALL_MONTH, startingDay) + 1;
                break;
            case 5:
                cout << "May " << year << endl;
                startingDay = printMonthCalender(BIG_MONTH, startingDay) + 1;
                break;
            case 6:
                cout << "June " << year << endl;
                startingDay = printMonthCalender(SMALL_MONTH, startingDay) + 1;
                break;
            case 7:
                cout << "July " << year << endl;
                startingDay = printMonthCalender(BIG_MONTH, startingDay) + 1;
                break;
            case 8:
                cout << "August " << year << endl;
                startingDay = printMonthCalender(BIG_MONTH, startingDay) + 1;
                break;
            case 9:
                cout << "September " << year << endl;
                startingDay = printMonthCalender(SMALL_MONTH, startingDay) + 1;
                break;
            case 10:
                cout << "October " << year << endl;
                startingDay = printMonthCalender(BIG_MONTH, startingDay) + 1;
                break;
            case 11:
                cout << "November " << year << endl;
                startingDay = printMonthCalender(SMALL_MONTH, startingDay) + 1;
                break;
            case 12:
                cout << "December " << year << endl;
                startingDay = printMonthCalender(BIG_MONTH, startingDay) + 1;
                break;
            default:
                break;
        }
        cout << endl << endl;
    }
}