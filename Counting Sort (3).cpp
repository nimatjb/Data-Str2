#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxElement = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    int* count = new int[maxElement + 1]{ 0 };

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    int* output = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << std::endl;
}
