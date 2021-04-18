#include <iostream>
#include <cmath>
using namespace std;

// section a
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);

// section b
bool isPerfect(int num);


int main() {
    int num;
    cout << "Please enter a positive integer >= 2:" << endl;
    cin >> num;
    cout << "All the perfect numbers between 2 and " << num << " are:" << endl;
    for (int i = 2; i <= num; i++) {
        if (isPerfect(i)) {
            cout << i << " ";
        }
    }
    cout << "\n\nAll pairs of amicable numbers between 2 and " << num << " are:" << endl;
    for (int i = 2; i <= num; i++) {
        int outCountDivs1 = 0, outSumDivs1 = 0, outCountDivs2 = 0, outSumDivs2 = 0;
        analyzeDividors(i, outCountDivs1, outSumDivs1);
        if (i != outSumDivs1 && outSumDivs1 <= num && outSumDivs1 >= 2) {
            analyzeDividors(outSumDivs1, outCountDivs2, outSumDivs2);
            if (i == outSumDivs2 && i < outSumDivs1) {
                cout << i << " and " << outSumDivs1 << endl;
            }
        }
    }
    cout << endl;
    return 0;
}

// section a
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
    for (int i = 1; i <= sqrt((double)num); i++) {
        if (num % i == 0) {
            if (((double)num / i) == sqrt((double)num)) {
                outCountDivs++;
                outSumDivs += i;
            }
            else {
                outCountDivs += 2;
                outSumDivs += i;
                outSumDivs += (num / i);
            }
        }
    }
    outCountDivs--;
    outSumDivs -= num;
}

// section b
bool isPerfect(int num) {
    int outCountDives = 0, outSumDives = 0;
    analyzeDividors(num, outCountDives, outSumDives);
    return (num == outSumDives);
}
