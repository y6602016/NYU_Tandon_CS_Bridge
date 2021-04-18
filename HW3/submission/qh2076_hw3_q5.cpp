#include <iostream>
#include <string>
using namespace std;

const double POUND_TO_KG = 0.453592;
const double INCH_TO_M = 0.0254;
const double UNDERWEIGHT = 18.5;
const double NORMAL_UP = 25;
const double NORMAL_BOTTOM = 18.5;
const double OVERWEIGHT_UP = 30;
const double OVERWEIGHT_BOTTOM = 25;

int main() {
    double pounds, inches, kg, m, BMI;
    string status;
    cout << "Please enter weight (in pounds):";
    cin >> pounds;
    cout << "Please enter height (in inches):";
    cin >>inches;

    // convert the pounds to kg, inches to meters
    kg = pounds * POUND_TO_KG;
    m = inches * INCH_TO_M;

    // calculate the BMI
    BMI = kg / (m * m);

    if (BMI < UNDERWEIGHT) {
        status = "Underweight";
    }
    else if (BMI >= NORMAL_BOTTOM && BMI < NORMAL_UP) {
        status = "Normal";
    }
    else if (BMI >= OVERWEIGHT_BOTTOM && BMI < OVERWEIGHT_UP) {
        status = "Overweight";
    }
    else {
        status = "Obese";
    }

    cout << "The weight status is: " << status;
    return 0;
}
