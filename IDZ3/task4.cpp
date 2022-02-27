#include <iostream>

#include "matrix.h"
#include "matrix_utils.h"
#include "poly.h"

int main() {
    Matrix A = {{-2, 3,  -1, 3},
                {3,  -5, 2,  -5},
                {-1, -1, -1, 0},
                {-5, 5,  -3, 6}};
    Poly ch = GetCharPoly(A);
    std::cout << ch << std::endl;
    return 0;
}