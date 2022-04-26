#include "matrix.h"
#include "matrix_utils.h"
#include "gauss.h"

#include <iostream>
#include <string>

int main() {
    const std::string SEP = "===========================\n";
    const Matrix A = {{3,  -3, -1, 0,  0,  0},
                      {0,  5,  1,  0,  0,  0},
                      {0,  -2, 2,  0,  0,  0},
                      {4,  2,  -3, 5,  -1, 0},
                      {8,  -2, -7, 4,  1,  0},
                      {-9, 1,  9,  -4, 3,  4}};
    std::cout << getCharPoly(A) << std::endl;
    std::cout << SEP;
    std::cout << getJNF(A, {{3, 4},
                            {4, 2}}) << std::endl;
    std::cout << SEP << std::endl << SEP;
    const Matrix B = A - 4 * Matrix::E(A.width());
    Matrix C = pow(B, 2);
    makeSuperTriangle(C);
    std::cout << C << std::endl;
    std::cout << SEP;
    Matrix x = {{2},
                {-1},
                {1},
                {-2},
                {1},
                {0}};
    std::cout << B * x << std::endl;
    std::cout << SEP << std::endl << SEP;
    const Matrix D = A - 3 * Matrix::E(A.width());
    Matrix E = pow(D, 4);
    makeSuperTriangle(E);
    std::cout << E << std::endl;
    std::cout << SEP;
    x = {{4},
         {-1},
         {2},
         {0},
         {0},
         {0}};
    Matrix y = {{0},
                {0},
                {0},
                {1},
                {0},
                {0}};
    std::cout << D * x << std::endl;
    std::cout << SEP;
    std::cout << D * y << std::endl;
    return 0;
}