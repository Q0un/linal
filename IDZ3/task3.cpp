#include <iostream>
#include <cassert>

#include "matrix.h"
#include "matrix_utils.h"

int main() {
    Matrix A = {{4, -4, -9, 7},
                {2, -2, -9, 6},
                {0, 0,  4,  -2},
                {0, 0,  4,  -2}};
    std::cout << Pow(A, 2) << std::endl << "================\n";

    Matrix B = {{4, -4, 2016 * 4, -2015 * 2},
                {2, -2, 2014 * 2, -2013},
                {0, 0,  4,        -2},
                {0, 0,  4,        -2}};
    Matrix C = {{8, -8, 2017 * 8, -2016 * 4},
                {4, -4, 2015 * 4, -2014 * 2},
                {0, 0,  4,        -2},
                {0, 0,  4,        -2}};
    MakeSuperTriangle(B);
    std::cout << B << std::endl << "================\n";
    MakeSuperTriangle(C);
    std::cout << C << std::endl << "================\n";

    Matrix D = {{2, 2016, -1, 1},
         {1, 1007, 0,  1},
         {0, 1,    1,  0},
         {0, 1,    2,  0}};
    Matrix V = {{2},
                {9},
                {6},
                {6}};
    ExtendedMatrix E(D, V);
    MakeSuperTriangle(D);
    std::cout << D << std::endl << "================\n";
    std::cout << SolveSOLE(E).first << std::endl;
    return 0;
}