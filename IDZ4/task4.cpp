#include "matrix.h"
#include "matrix_utils.h"

#include <iostream>
#include <string>

int main() {
    const std::string SEP = "=================================\n";
    const Matrix A = {{4, 0, 0, 0, 0}, {0, -2, 0, 0, 1}, {0, 0, 4, 1, 0}, {1, 2, 0, 4, 0}, {0, 0, 0, 0, -2}};
    std::cout << getCharPoly(A) << std::endl;
    std::cout << SEP;
    return 0;
}