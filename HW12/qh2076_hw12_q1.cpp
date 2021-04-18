#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

class Money {
public:
    friend Money operator+(const Money & amount1, const Money & amount2);
    friend Money operator-(const Money & amount1, const Money & amount2);
    friend Money operator-(const Money & amount1);
    friend Money operator==(const Money & amount1, const Money & amount2);
    friend Money operator<(const Money & amount1, const Money & amount2);
    Money(long dollars, int cents);
    Money(long dollars);
    Money();
    void set_value(long dollars);
    double get_value() const;
    friend istream & operator>>(istream & ins, Money & amount);
    friend ostream & operator<<(ostream & outs, const Money & amount);

private:
    long all_cents;
};

int digit_to_int(char c);

class Check {
public:
    friend istream & operator>>(istream & ins, Check & amount);
    friend ostream & operator<<(ostream & outs, const Check & amount);
    Check();
    Check(int number, double amount, bool cashed);
    void setCheck(int number, double amount, bool cashed);
    int getNumber();
    double getAmount();
    bool getCashed();
private:
    int number;
    Money amount;
    bool cashed;
};

int main() {
    vector<Check> checkArr;
    int input, i = 0;
    bool endInput = false;
    while (endInput == false) {
        cout << "Please enter 1 to key in the info of checks, enter -1 to end the input" << endl;
        cin >> input;
        if (input == -1) {
            endInput = true;
        }
        else if (input == 1) {
            Check temp;
            cin >> temp;
            checkArr.push_back(temp);
        }
        else {
            cout << "Please enter 1 or -1" <<endl;
            exit(1);
        }
    }

    vector<double> deposits;
    endInput = false;
    double deposit, sumOfDeposit = 0;
    while(endInput == false) {
        cout << "Please enter deposit, enter -1 to end the loop" << endl;
        cin>>deposit;
        if (deposit == -1) {
            endInput = true;
        }
        else {
            deposits.push_back(deposit);
            sumOfDeposit+=deposit;
        }
    }
    double oldBalance, bankNewBalance;
    cout << "Please enter the old balance" << endl;
    cin >> oldBalance;
    cout << "Please enter the new balance" << endl;
    cin >> bankNewBalance;
    double sumOfCashed = 0;
    for (int i = 0; i < checkArr.size(); i++) {
        if (checkArr[i].getCashed()) {
            sumOfCashed += checkArr[i].getAmount();
        }
    }
    double newBalance;
    newBalance = oldBalance + sumOfDeposit - sumOfCashed;
    cout << "The total of the checks cashed: $" << sumOfCashed << endl;
    cout << "The total of the deposits: $" << sumOfDeposit << endl;
    cout << "The new balance: $" << newBalance << endl;
    cout << "The new balance differs from the bank balance is: $" << newBalance - bankNewBalance;
    sort(checkArr.begin(), checkArr.end(), [](auto & lhs, auto & rhs){
        return (lhs.getNumber() < rhs.getNumber());
    });
    cout << "The cashed checks are below:" << endl;
    for(int i = 0; i < checkArr.size(); i++) {
        if (checkArr[i].getCashed()) {
            cout << checkArr[i] << endl;
        }
    }
    cout << "The un-cashed checks are below:" << endl;
    for(int i = 0; i < checkArr.size(); i++) {
        if (!checkArr[i].getCashed()) {
            cout << checkArr[i] << endl;
        }
    }
    return 0;
}

Money operator+(const Money & amount1, const Money & amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator-(const Money & amount1, const Money & amount2){
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator-(const Money & amount1){
    Money temp;
    temp.all_cents = amount1.all_cents * -1;
    return temp;
}

Money operator==(const Money & amount1, const Money & amount2) {
    return(amount1.all_cents == amount2.all_cents);
}

Money operator<(const Money & amount1, const Money & amount2) {
    return(amount1.all_cents < amount2.all_cents);
}

Money::Money(long dollars, int cents) {
    if (dollars * cents < 0) {
        cout << "Illegal values for dollars and cents";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars): all_cents(dollars){};
Money::Money():all_cents(0){};

double Money::get_value() const {
    return (all_cents * 0.01);
}

void Money::set_value(long dollars) {
    this->all_cents = dollars;
}

istream & operator>>(istream & ins, Money & amount){
    char one_char, decimal_point, digit1, digit2;
    long dollars;
    int cents;
    bool negative;

    ins >> one_char;
    if (one_char == '-'){
        negative = true;
        ins >> one_char;
    }
    else {
        negative = false;
    }
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2)) {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + (int)digit2;
    amount.all_cents = dollars + cents;
    if (negative) {
        amount.all_cents *= -1;
    }
    return ins;
}

ostream & operator<<(ostream & outs, const Money & amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;
    if (amount.all_cents < 0) {
        outs << "- $" << dollars << '.';
    }
    else {
        outs << "$" << dollars << '.';
    }
    if (cents < 0) {
        outs << '0';
    }
    outs << cents;
    return outs;
}

int digit_to_int(char c) {
    return (static_cast<int>(c) - static_cast<int>('0'));
}


Check::Check() {
    Money money;
    number = 0;
    cashed = false;
}
Check::Check(int number, double amount, bool cashed) {
    this->number = number;
    this->amount = Money((long)amount);
    this->cashed = cashed;
}

void Check::setCheck(int number, double amount, bool cashed) {
    this->number = number;
    this->amount.set_value((long)(amount * 100));
    this->cashed = cashed;
}

int Check::getNumber() {
    return number;
}

double Check::getAmount() {
    double temp = (double)amount.get_value();
    return temp;
}

bool Check::getCashed() {
    return cashed;
}

istream & operator>>(istream & ins, Check & amount) {
    int input_number;
    double input_amount;
    int input_cashed;
    cout << "Please enter check number, ex: 345654" << endl;
    ins >> input_number;
    cout << "Please enter check amount in dollars, ex: 200.99" << endl;
    ins >> input_amount;
    cout << "Please enter 1 if check is cashed, 0 if check is not cashed" << endl;
    ins >> input_cashed;
    amount.setCheck(input_number, input_amount, input_cashed);
    return ins;
}

ostream & operator<<(ostream & outs, const Check & amount) {
    outs << "The check number is " << amount.number << endl;
    outs << "The check amount is " << amount.amount <<endl;
    if (amount.cashed) {
        outs << "The check is cashed" << endl;
    }
    else {
        outs << "The check is not cashed" << endl;
    }
    return outs;
}


