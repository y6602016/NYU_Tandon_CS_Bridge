#include <iostream>
using namespace std;

const int ARRAY_SIZE = 6;
int * findMissing(int arr[], int n, int& resArrSize);
void printArray(int * arr, int arrSize);

int main() {
    int arr[ARRAY_SIZE] = {3, 1, 3, 0, 6, 4}, logicalSize = ARRAY_SIZE;

    int * missArray = findMissing(arr, ARRAY_SIZE, logicalSize);
    printArray(missArray, logicalSize);

    delete [] missArray;
    missArray = nullptr;
    return 0;
}

int * findMissing(int arr[], int n, int& resArrSize) {
    // the range of element in arr is from 0 to n, so the size of checkArray is n + 1
    const int size = n + 1;
    int checkArray[size], missCount = 0;
    //initialize the checkArray's elements as 0
    for (int i = 0; i < size; i++) {
        checkArray[i] = 0;
    }

    // if the number i appear is in the arr, checkArray[i]++
    for (int i = 0; i < n; i++) {
        checkArray[arr[i]]++;
    }

    // if checkArray[i] == 0, which means it's the missing number
    // update the missCount
    for (int i = 0; i < size; i++) {
        if (checkArray[i] == 0) {
            missCount++;
        }
    }

    // update logical size
    resArrSize = missCount;

    // use the logical size to create an array
    int * missArray = new int[resArrSize], k = 0;

    // if checkArray[i] == 0, which means it's the missing number
    // put it into missArray
    for (int i = 0; i < size; i++) {
        if (checkArray[i] == 0) {
        missArray[k++] = i;
        }
    }

    return missArray;
}

void printArray(int * arr, int arrSize) {
    cout << "The logical size is: " << arrSize << endl;
    cout << "The array of the missing number is: [";
    for (int i = 0; i < arrSize; i++) {
        cout << "\"" << arr[i] << "\"";
        if (i < arrSize - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}
