#include <iostream>

#include "matrix.h"
#include "matrix_utils.h"

int main() {
    Matrix m = {{-2, -2, 2, 1},
                {-5, -3, 3, 1},
                {-5, -4, 3, 2},
                {0,  0,  1, -2}};
    std::cout << GetCharPoly(m) << std::endl;
    return 0;
}
