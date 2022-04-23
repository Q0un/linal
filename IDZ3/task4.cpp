#include <iostream>

#include "gauss.h"
#include "matrix.h"
#include "matrix_utils.h"
#include "poly.h"

int main() {
    Matrix A = {{-2, 3,  -1, 3},
                {3,  -5, 2,  -5},
                {-1, -1, -1, 0},
                {-5, 5,  -3, 6}};
    Poly ch = GetCharPoly(A);
    std::cout << ch << std::endl << "======================\n";

    Matrix V1 = Pow(A + Matrix::E(4), 2), V2 = Pow(A, 2);
    std::cout << V2 << std::endl << "======================\n";
    std::cout << V1 << std::endl << "======================\n";
    MakeSuperTriangle(V1);
    std::cout << V1 << std::endl;
    return 0;
}