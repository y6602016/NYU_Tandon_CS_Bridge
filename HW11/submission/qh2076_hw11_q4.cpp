#include <iostream>
using namespace std;

const int ARR_SIZE = 7;
int jump(int *arr, int arrSize);

int main() {
    int arr[ARR_SIZE] = {0, 25, 30, 4, 28, 30, 7};
    cout << "The lowest cost of jumping the array is:" << endl;

    cout << jump(arr, ARR_SIZE);
    return 0;
}


int jump(int *arr, int arrSize) {
    if (arrSize == 1) {
        return arr[0];
    }
    else {
        // arr[0] is always 0, so arr[1] and arr[2] always return itself
        // to return the lowest cost
        if (arrSize == 2 || arrSize == 3) {
            return arr[arrSize - 1];
        }
        else {
            // we calculate the previous two columns and choose the one with
            // less cost, then return the sum of it and the current value
            int smallest1 = jump(arr, arrSize - 1);
            int smallest2 = jump(arr, arrSize - 2);
            if (smallest1 < smallest2) {
                return smallest1 + arr[arrSize - 1];
            }
            else {
                return smallest2 + arr[arrSize - 1];
            }
        }
    }
}