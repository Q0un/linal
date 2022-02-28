#include <iostream>

#include "extended_matrix.h"
#include "gauss.h"

int main() {
    Matrix A = {{1, -7, -4, -7, -7, -7},
                {1, -7, 2,  5,  5,  5},
                {1, -7, -3, -5, -5, -5}};
    Matrix v1 = {{-8, -1, -2, 1, 3, -3}};
    Matrix v2 = {{3, 1, -8, -1, 3, 2}};
    std::cout << A(v1) << std::endl << "=============\n";
    std::cout << A(v2) << std::endl << "=============\n";
    MakeSuperTriangle(A);
    std::cout << A << std::endl << "=============\n";
    Matrix V(6);
    V[0] = v1[0];
    V[1] = v2[0];
    V[2] = {-1, 0, -2, 0, 0, 1};
    V[3] = {-1, 0, -2, 0, 1, 0};
    V[4] = {-1, 0, -2, 1, 0, 0};
    V[5] = {7, 1, 0, 0, 0, 0};
    V = V.T();
    MakeSuperTriangle(V);
    std::cout << V << std::endl;
    return 0;
}
