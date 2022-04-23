#include <iostream>

#include "matrix.h"
#include "gauss.h"

int main() {
    Matrix a(9, 9);

    a[0][1] = -5;
    a[0][6] = -8;

    a[1][7] = -8;

    a[2][0] = 8;
    a[2][1] = -2;
    a[2][2] = 4;
    a[2][8] = -8;

    a[3][0] = 5;
    a[3][4] = -5;
    a[3][6] = 2;

    a[4][1] = 5;
    a[4][7] = 2;

    a[5][2] = 5;
    a[5][3] = 8;
    a[5][4] = -2;
    a[5][5] = 4;
    a[5][8] = 2;

    a[6][6] = -4;
    a[6][7] = -5;

    a[7][7] = -4;

    a[8][6] = 8;
    a[8][7] = -2;

    ExtendedMatrix ext_a(a);

    makeTriangle(ext_a);

    std::cout << ext_a << std::endl;
    return 0;
}