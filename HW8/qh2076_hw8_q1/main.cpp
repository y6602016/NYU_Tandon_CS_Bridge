#include <iostream>
using namespace std;

const int ARRAY_SIZE = 20;

// section 1
int minInArray(const int arr[], int arrSize);

void printMinIndex(const int arr[],int arrSize, int min);


// section 2
int main() {
    int arr[ARRAY_SIZE], min;
    cout << "Please enter 20 integers separated by a space:" << endl;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cin >> arr[i];
    }
    min = minInArray(arr, ARRAY_SIZE);
    cout << "The minimum value is " << min << ", and it is located in the following indices:";
    printMinIndex(arr,ARRAY_SIZE,min);
    return 0;
}

// section 1
int minInArray(const int arr[], int arrSize) {
    int min = INT_MAX;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void printMinIndex(const int arr[],int arrSize, int min) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min) {
            cout << i << " ";
        }
    }
}