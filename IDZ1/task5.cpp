#include <iostream>

#include "matrix.h"

bool FindDecomposition(const Matrix& a, Matrix& b, Matrix& c) {
    const int64_t MIN_VAL = -5;
    const int64_t MAX_VAL = 5;
    for (int64_t a1 = MIN_VAL; a1 <= MAX_VAL; ++a1) {
        for (int64_t a2 = MIN_VAL; a2 <= MAX_VAL; ++a2) {
            for (int64_t a3 = MIN_VAL; a3 <= MAX_VAL; ++a3) {
                for (int64_t b1 = MIN_VAL; b1 <= MAX_VAL; ++b1) {
                    for (int64_t b2 = MIN_VAL; b2 <= MAX_VAL; ++b2) {
                        for (int64_t b3 = MIN_VAL; b3 <= MAX_VAL; ++b3) {
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
    std::cout << c * b << std::endl;
    return 0;
}