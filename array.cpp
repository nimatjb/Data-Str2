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