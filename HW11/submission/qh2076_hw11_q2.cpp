#include <iostream>
using namespace std;

const int ARR_SIZE = 4;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr[ARR_SIZE] = {1,2,3,5};

    cout << "The sum of the squares of the array is " << sumOfSquares(arr, ARR_SIZE) << endl;

    if(isSorted(arr, ARR_SIZE)) {
        cout << "The array is in an ascending order.";
    }
    else {
        cout << "The array is not in an ascending order.";
    }
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0] * arr[0];
    }
    else {
        int sum = sumOfSquares(arr, arrSize - 1);
        return sum + (arr[arrSize - 1] * arr[arrSize - 1]);
    }
}

bool isSorted(int arr[], int arrSize) {
    if (arrSize == 1) {
        return true;
    }
    else {
        bool lastReturn = isSorted(arr, arrSize - 1);
        if (lastReturn) {
            if (arr[arrSize - 1] >= arr[arrSize - 2]) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
}
