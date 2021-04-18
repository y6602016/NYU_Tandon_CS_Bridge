#include <iostream>
using namespace std;
const int ARR_SIZE = 6;
void oddsKeepEvensFlip(int arr[], int arrSize);
void printArr(int arr[], int arrSize);

int main() {
    int arr[ARR_SIZE] = {5, 2, 11, 7, 6, 4};
    cout << "The original array is: ";
    printArr(arr, ARR_SIZE);
    oddsKeepEvensFlip(arr, ARR_SIZE);
    cout << "\nThe modified array is: ";
    printArr(arr, ARR_SIZE);
    return 0;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int oddArr[arrSize], evenArr[arrSize], oddCount = 0, evenCount = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[evenCount++] = arr[i];
        }
        else {
            oddArr[oddCount++] = arr[i];
        }
    }
    for (int i = 0; i < oddCount; i++) {
        arr[i] = oddArr[i];
    }
    for (int i = oddCount; i < arrSize; i++) {
        arr[i] = evenArr[--evenCount];
    }
}

void printArr(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
}
