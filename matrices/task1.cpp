#include <iostream>

#include "gauss.h"
#include "matrix.h"

int main() {
    Matrix a = {{3, 3, 6},
                {4, -2, 2},
                {-3, 1, -2},
                {2, 2, 4},
                {-2, -3, -5}};
    Matrix b = {{-1, 0, 0, 1},
                {2, 0, 1, 0},
                {1, 1, 0, 0}};
    Matrix c = {{0},
                {0},
                {0},
                {0},
                {0}};
    std::cout << Gauss::MakeTriangle((a * b) | c) << std::endl;
}