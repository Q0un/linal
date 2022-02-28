#include <iostream>

#include "matrix.h"
#include "gauss.h"

int main() {
    Matrix A = {{9,   -6,  -1, 1},
                {18,  -12, -2, 2},
                {5,   -4,  -1, 3},
                {-16, 11,  2,  -3}};
    Matrix B = A.T();
    MakeSuperTriangle(B);
    std::cout << B << std::endl << "=======================\n";
    Matrix C(6);
    C[0] = A[0];
    C[1] = A[1];
    C[2] = A[2];
    C[3] = A[3];
    C[4] = {-2, 1, 0, 0};
    C[5] = {3, 0, 1, 2};
    MakeSuperTriangle(C);
    std::cout << C << std::endl << "=======================\n";

    B = A;
    MakeSuperTriangle(B);
    std::cout << B << std::endl << "=======================\n";
    Matrix D(6);
    A = A.T();
    D[0] = A[0];
    D[1] = A[1];
    D[2] = A[2];
    D[3] = A[3];
    D[4] = {7, 11, 0, 3};
    D[5] = {-1, -2, 3, 0};
    D = D.T();
    MakeSuperTriangle(D);
    std::cout << D << std::endl;
    return 0;
}