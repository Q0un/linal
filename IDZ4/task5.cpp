#include "matrix.h"
#include "matrix_utils.h"

#include <iostream>
#include <string>

int main() {
    std::string SEP = "=======================================\n";
    const Matrix B = {{0, 0, 5,  3},
                      {0, 0, 3,  2},
                      {5, 3, -7, -8},
                      {3, 2, -8, -6}};
    const Matrix C = {{-3, 0, 0, 0},
                      {3,  1, 0, 0},
                      {1,  0, 1, 0},
                      {-2, 0, 0, 1}};
    const Matrix B1 = C.T() * B * C;
    std::cout << B1 << std::endl;
    std::cout << SEP;
    const Matrix B2 = {{1,  -1, 3},
                       {-1, 0,  3},
                       {3,  3,  -7}};
    std::cout << det(B1) << ' ' << det(B2) << std::endl;
    return 0;
}