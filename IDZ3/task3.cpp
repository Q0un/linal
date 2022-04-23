#include <iostream>

#include "gauss.h"
#include "matrix.h"
#include "matrix_utils.h"

int main() {
    Matrix A = {{4, -4, -9, 7},
                {2, -2, -9, 6},
                {0, 0,  4,  -2},
                {0, 0,  4,  -2}};
    Matrix X = Pow(A, 4);
    std::cout << X << std::endl << "================\n";
    MakeSuperTriangle(X);
    std::cout << X << std::endl << "================\n";
    Matrix B = {{2, 2,  -1, 1},
                {1, -1, 0,  1},
                {0, 2,  1,  0},
                {0, 2,  2,  0}};
    Matrix V = {{2},
                {9},
                {6},
                {6}};
    Matrix res = SolveSOLE(B, V).first;
    MakeSuperTriangle(B);
    std::cout << B << std::endl << "================\n";
    std::cout << res << std::endl;
    return 0;
}