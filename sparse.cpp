#include <iostream>
using namespace std;
#define MAX_ROWS 100
#define MAX_COLS 100

void sp(int sparce[MAX_ROWS][MAX_COLS], int row, int col) {

    int arry[MAX_ROWS][MAX_COLS];

    int k = 1;


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arry[i][j] != 0) {

                arry[k][0] = i;
                arry[k][1] = j;
                arry[k][2] = arry[i][j];
                k++;
            }
        }
    }
    arry[0][0] = row;
    arry[0][1] = col;
    arry[0][2] = k - 1;

};



