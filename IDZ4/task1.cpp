#include "matrix.h"
#include "matrix_utils.h"

#include <iostream>
#include <string>

int main() {
    const std::string SEP = "===============================\n";

    Matrix A = {{5,  -1, 1,  -1},
                {-1, 6,  -1, 2},
                {-1, 2,  3,  2},
                {1,  -2, 1,  2}};

    Matrix B = {{5,  -5, -3, -1},
                {1,  -4, -5, -2},
                {-1, 8,  9,  2},
                {-1, 8,  5,  6}};

    Matrix C = {{7,  2,  2,  3},
                {5,  6,  3,  4},
                {1,  -2, 4,  -1},
                {-7, -2, -4, -1}};

    std::cout << getCharPoly(A) << std::endl << getCharPoly(B) << std::endl
              << getCharPoly(C) <<
              std::endl;

    std::cout << SEP;

    std::cout << getJNF(A, {{4, 4}}) << std::endl;
    std::cout << SEP;
    std::cout << getJNF(B, {{4, 4}}) << std::endl;
    std::cout << SEP;
    std::cout << getJNF(C, {{4, 4}}) << std::endl;

    return 0;
}