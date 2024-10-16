#include <iostream>
#include <algorithm>
using namespace std;

void inputArray(double* arr, int n, int index = 0) {
    if (index == n) return;
    cin >> arr[index];
    inputArray(arr, n, index + 1);
}

double sumNegativeElements(double* arr, int n, int index = 0) {
    if (index == n) return 0;
    return (arr[index] < 0 ? arr[index] : 0) + sumNegativeElements(arr, n, index + 1);
}

int findMaxIndex(double* arr, int n, int index = 0, int maxIndex = 0) {
    if (index == n) return maxIndex;
    return findMaxIndex(arr, n, index + 1, (arr[index] > arr[maxIndex] ? index : maxIndex));
}

int findMinIndex(double* arr, int n, int index = 0, int minIndex = 0) {
    if (index == n) return minIndex;
    return findMinIndex(arr, n, index + 1, (arr[index] < arr[minIndex] ? index : minIndex));
}

double productBetweenMinMax(double* arr, int minIndex, int maxIndex, int index) {
    if (index >= maxIndex) return 1;
    return arr[index] * productBetweenMinMax(arr, minIndex, maxIndex, index + 1);
}

void sortEvenElements(double* arr, int n, int i = 0) {
    if (i >= n - 1) return;
    if (int(arr[i]) % 2 == 0) {
        for (int j = i + 1; j < n; j++) {
            if (int(arr[j]) % 2 == 0 && arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    sortEvenElements(arr, n, i + 1);
}

void printArray(double* arr, int n, int index = 0) {
    if (index == n) {
        cout << endl;
        return;
    }
    cout << arr[index] << " ";
    printArray(arr, n, index + 1);
}

int main() {
    int n;
    cout << "Enter the number of array elements: ";
    cin >> n;

    double* arr = new double[n];

    inputArray(arr, n);

    cout << "Initial array:\n";
    printArray(arr, n);

    double sumNegatives = sumNegativeElements(arr, n);
    cout << "S = " << sumNegatives << endl;

    int minIndex = findMinIndex(arr, n);
    int maxIndex = findMaxIndex(arr, n);
    if (minIndex > maxIndex) swap(minIndex, maxIndex);

    double product = productBetweenMinMax(arr, minIndex, maxIndex, minIndex + 1);
    cout << "P =" << product << endl;

    sortEvenElements(arr, n);

    cout << "Array after sorting even elements:\n";
    printArray(arr, n);

    delete[] arr;
    return 0;
}