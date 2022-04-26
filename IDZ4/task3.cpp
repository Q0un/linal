#include "matrix.h"
#include "matrix_utils.h"
#include "gauss.h"

#include <iostream>

int main() {
    const std::string SEP = "==================================\n";
    const Matrix A = {{2, -1, -1}, {-2, -5, -8}, {2, 5, 8}};
    const Matrix B = {{2, -3, 3}, {6, -6, 5}, {6, -6, 5}};
    const Matrix ABase = {{-1, -1, -2}, {-1, -2, -3}, {1, -1, -1}};
    const Matrix BBase = {{-1, -1, 2}, {-1, -2, 3}, {-1, 1, -1}};
    const Matrix ATo = inverse(ABase);
    const Matrix BTo = inverse(BBase);
    const Matrix A2 = ABase * A * ATo;
    const Matrix B2 = BBase * B * BTo;
    std::cout << A2 * B2 << std::endl;
    std::cout << SEP << std::endl << SEP;

    Matrix A2Triangle = A2;
    Matrix B2Triangle = B2;
    makeSuperTriangle(A2Triangle);
    makeSuperTriangle(B2Triangle);
    std::cout << A2Triangle << std::endl;
    std::cout << SEP;
    std::cout << B2Triangle << std::endl;
    std::cout << SEP << std::endl << SEP;

    std::cout << A2 << std::endl;
    std::cout << SEP;
    std::cout << B2 << std::endl;
    return 0;
}