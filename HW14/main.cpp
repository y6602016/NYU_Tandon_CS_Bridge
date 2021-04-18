#include <iostream>
#include <vector>
using namespace std;

template <class T>
vector<T> findMinMax(vector<T> & arr, vector<T> & minMax, int left, int right) {
    vector<T> leftMinMax;
    vector<T> rightMinMax;
    // only on items
    if (left == right) {
        minMax[0] = minMax[1] = arr[left];
        return minMax;
    }
    // only two items
    else if (left + 1 == right) {
        minMax[0] = arr[left] < arr[right] ? arr[left] : arr[right];
        minMax[1] = arr[left] < arr[right] ? arr[right] : arr[left];
        return minMax;
    }

    // when there are two more items
    int mid = (left + right) / 2;
    leftMinMax = findMinMax(arr, minMax, left, mid);
    rightMinMax = findMinMax(arr, minMax, mid + 1, right);
    minMax[0] = leftMinMax[0] < rightMinMax[0] ? leftMinMax[0] : rightMinMax[0];
    minMax[1] = leftMinMax[1] < rightMinMax[1] ? rightMinMax[1] : leftMinMax[1];
    return minMax;
}

template <class T>
vector<T> driver(vector<T> & arr) {
    vector<T> minMax = {0, 0};
    return findMinMax(arr, minMax, 0, arr.size() - 1);
}


int main() {
    vector<int> arr;
    arr = {500, 10, 120, 6, 3, 120, 1, 88, -3, -900, 4, 2229};
    vector<int> min_max;
    min_max = driver(arr);
    cout << "min: " << min_max[0] << endl;
    cout << "max: " << min_max[1] << endl;

    return 0;
}
