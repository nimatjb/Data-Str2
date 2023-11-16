#include <iostream>
using namespace std;
class Array {

    int* array;
    int size;

public:
    Array(int n) {
        array = new int[n];
        size = n;
    }

    int Insert(int object, int index) {
        if (index < size) {
            array[index] = object;
            return index;
        }
        else {
            return -1;
        }
    }
    int Delete(int index) {
        if (index < size) {
            int obj = array[index];
            array[index] = 0;
            return obj;
        }
        else {
            return -1;
        }
    }

    int find(int object) {
        for (int i = 0; i < size; i++) {
            if (array[i] == object) {
                return i;
            }
        }
        return -1;
    }
};

