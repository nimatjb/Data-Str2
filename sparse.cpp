#include <iostream>
using namespace std;


void sparse(int a[][3], int row, int col, int spars[][3], int i, int j, int& k) {
    if (i == row) {
        spars[0][0] = row;
        spars[0][1] = col;
        spars[0][2] = k - 1;
        return;
    }

    if (j == col) {
        sparse(a, row, col, spars, i + 1, 0, k);
        return;
    }

    if (a[i][j] != 0) {
        spars[k][0] = i;
        spars[k][1] = j;
        spars[k][2] = a[i][j];
        k++;
    }

    sparse(a, row, col, spars, i, j + 1, k);
}


