#include <iostream>
using namespace std;

int jump(int arr[], int arrSize);

int main() {
    int arr[7] = {0, 25, 30, 6, 55, 50, 7};
    cout << jump(arr, 7);
    return 0;
}

int jump(int arr[], int arrSize) {
    if (arrSize == 1) {
        return arr[0];
    }
    else {
        if (arrSize == 2 || arrSize == 3) {
            return arr[arrSize - 1];
        }
        else {
            int a = jump(arr, arrSize - 1);
            int b = jump(arr, arrSize - 2);
            if (a < b) {
                return arr[arrSize - 1] + a;
            }
            else {
                return arr[arrSize - 1] + b;
            }
        }
    }
}