#include <iostream>
using namespace std;

// section a
void reverseArray(int arr[], int arrSize);
// section b
void removeOdd(int arr[], int& arrSize);
// section c
void splitParity(int arr[], int arrSize);

void printArray(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

// section a
void reverseArray(int arr[], int arrSize) {
    int temp, low = 0, high = arrSize - 1;
    while (low < high) {
        temp = arr[low];
        arr[low++] = arr[high];
        arr[high--] = temp;
    }

}

// section b
void removeOdd(int arr[], int& arrSize){
    int copySize = arrSize, tempPosition = -1;
    for (int i = 0; i < copySize; i++) {
        if (arr[i] % 2 == 1) {
            if (tempPosition < 0) {
                tempPosition = i;
            }
            arrSize--;
        }
        else {
            if (tempPosition >= 0) {
                arr[tempPosition++] = arr[i];
            }
        }
    }
}

// section c
void splitParity(int arr[], int arrSize){
    int low = 0, high = arrSize - 1, temp;
    while (low < high) {
        while (low < high && arr[low] % 2 == 1) {
            low++;
        }
        while (low < high && arr[high] % 2 == 0) {
            high--;
        }
        if (low < high) {
            temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
}
