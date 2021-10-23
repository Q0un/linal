#include <iostream>

#include "matrix.h"

bool FindDecomposition(const Matrix& a, Matrix& b, Matrix& c) {
    for (int64_t a1 = -5; a1 <= 5; ++a1) {
        for (int64_t a2 = -5; a2 <= 5; ++a2) {
            for (int64_t a3 = -5; a3 <= 5; ++a3) {
                for (int64_t b1 = -5; b1 <= 5; ++b1) {
                    for (int64_t b2 = -5; b2 <= 5; ++b2) {
                        for (int64_t b3 = -5; b3 <= 5; ++b3) {
                            b[0][1] = a1;
                            b[1][1] = a2;
                            b[2][1] = a3;
                            c[0][0] = b1;
                            c[0][1] = b2;
                            c[0][2] = b3;
                            if (a == b * c) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    Matrix a = {{1,  8,  8},
                {-5, 9,  -5},
                {1,  -6, -2}};
    Matrix b = {{4,  0},
                {1,  0},
                {-2, 0}};
    Matrix c = {{0,  0, 0},
                {-3, 4, -4}};
    if (!FindDecomposition(a, b, c)) {
        std::cout << "Not Found" << std::endl;
        return 0;
    }
    std::cout << b << std::endl << "================" << std::endl << c << std::endl << "================" << std::endl;
    std::cout << Pow(c * b, 1) << std::endl << "================" << std::endl << Pow(c * b, 2) << std::endl;
    return 0;
}