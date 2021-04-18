#include <iostream>
using namespace std;

const int ARR_SIZE = 6;

int * getPosNums1(int * arr, int arrSize, int & outPosArrSize);
int * getPosNums2(int * arr, int arrSize, int * outPosArrSizePtr);
void getPosNums3(int * arr, int arrSize, int *& outPosArr, int & outPosArrSize);
void getPosNums4(int * arr, int arrSize, int ** outPosArrPtr, int * outPosArrSizePtr);
void printArr(int * arr, int arrSize);

int main() {
    int arr[ARR_SIZE] = {3, -1, -3, 0, 6, 4};

    cout << "The original array is: ";
    printArr(arr, ARR_SIZE);
    cout << "\nThe size is: " << ARR_SIZE;
    cout << "\nThe original base address is: " << arr << endl;

    // getPosNums1 test
    int logicalSize1 = ARR_SIZE;
    int * posNums1 = getPosNums1(arr, ARR_SIZE, logicalSize1);
    cout << "\ngetPosNums1 array: ";
    printArr(posNums1, logicalSize1);
    cout << "\nThe logical size is: " << logicalSize1;
    cout << "\ngetPosNums1 new base address: " << posNums1 << endl;

    // getPosNums2 test
    int logicalSize2 = ARR_SIZE;
    int * posNums2 = getPosNums2(arr, ARR_SIZE, &logicalSize2);
    cout << "\ngetPosNums2 array: ";
    printArr(posNums2, logicalSize2);
    cout << "\nThe logical size is: " << logicalSize2;
    cout << "\ngetPosNums2 new base address: " << posNums2 << endl;

    // getPosNums3 test
    int * outPosArr1 = nullptr, logicalSize3 = ARR_SIZE;
    getPosNums3(arr, ARR_SIZE, outPosArr1, logicalSize3);
    cout << "\ngetPosNums3 array: ";
    printArr(outPosArr1, logicalSize3);
    cout << "\nThe logical size is: " << logicalSize3;
    cout << "\ngetPosNums3 new base address: " << outPosArr1 << endl;

    // getPosNums4 test
    int * outPosArr2 = nullptr, logicalSize4 = ARR_SIZE;
    getPosNums4(arr, ARR_SIZE, &outPosArr2, &logicalSize4);
    cout << "\ngetPosNums4 array: ";
    printArr(outPosArr2, logicalSize4);
    cout << "\nThe logical size is: " << logicalSize4;
    cout << "\ngetPosNums4 new base address: " << outPosArr2 << endl;


    delete [] posNums1;
    delete [] posNums2;
    delete [] outPosArr1;
    delete [] outPosArr2;

    posNums1 = nullptr;
    posNums2 = nullptr;
    outPosArr1 = nullptr;
    outPosArr2 = nullptr;
    return 0;
}

int * getPosNums1(int * arr, int arrSize, int & outPosArrSize){
    // count the number of the positive numbers
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }

    // update the logical size
    outPosArrSize = count;

    // use the updated logical size as the size to create a new array
    int * newArr = new int[outPosArrSize], newArrIndex = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            newArr[newArrIndex++] = arr[i];
        }
    }

    // return the base address of the new array
    return newArr;
}

int * getPosNums2(int * arr, int arrSize, int * outPosArrSizePtr) {
    // count the number of the positive numbers
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }

    // dereference the pointer and change it's value to update the logical size
    *outPosArrSizePtr = count;

    // use the dereference pointer as the size to create a new array
    int * newArr = new int[*outPosArrSizePtr], newArrIndex = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            newArr[newArrIndex++] = arr[i];
        }
    }

    // return the base address of the new array
    return newArr;
}

void getPosNums3(int * arr, int arrSize, int *& outPosArr, int & outPosArrSize) {
    // by calling getPosNums1, we can get the base address and update outPosArr
    // meanwhile, outPosArrSize is updated as well
    outPosArr = getPosNums1(arr, arrSize, outPosArrSize);
}

void getPosNums4(int * arr, int arrSize, int ** outPosArrPtr, int * outPosArrSizePtr){
    // dereference outPosArrPtr and change it's value, which is the base address of the
    // new array returned from getPosNums2, to update the base address of the new array
    // meanwhile, the pointer outPosArrSizePtr is updated as well in getPosNums2
    *outPosArrPtr = getPosNums2(arr, arrSize, outPosArrSizePtr);
}

void printArr(int * arr, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
}
