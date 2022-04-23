#include <iostream>

#include "matrix.h"
#include "matrix_utils.h"

int main() {
    Matrix a = {{1,  -2},
                {-3, 6},
                {4,  -8},
                {-2, 4},
                {2,  -4}};
    Matrix b = {{1, 3, 2, -3, -1},
                {3, 1, 2, -1, -3}};
    std::cout << getCharPoly(a * b) << std::endl;
    return 0;
}
