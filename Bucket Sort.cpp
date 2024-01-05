#include <iostream>
using namespace std;

class BucketSort {
public:
    int* bucketsort(int* arr, int n) {
        int max = arr[0];
        int min = arr[0];
        int index = 0;

        if (n <= 1)
            return arr;

        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        int numBuckets = max - min + 1;
        int* buckets = new int[numBuckets];

        for (int i = 0; i < numBuckets; i++) {
            buckets[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            buckets[arr[i] - min]++;
        }

        for (int i = 0; i < numBuckets; i++) {
            while (buckets[i] > 0) {
                arr[index] = i + min;
                index++;
                buckets[i]--;
            }
        }

        delete[] buckets;

        return arr;
    }

    void printArray(int* arr, int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

