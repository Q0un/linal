#include <iostream>

#include "matrix.h"
#include "matrix_utils.h"

int main() {
    Matrix a = {{-3, -1, 1,  -2},
                {1,  -2, -1, 3},
                {-1, -2, 1,  3},
                {-2, 1,  2,  2}};
    Matrix b = {{-1, -8, -7, 1},
                {8,  1,  -3, 9},
                {-3, 2,  6,  5},
                {-1, -5, -3, 3}};
    Matrix c = {{2,  1,  -2, 2},
                {-1, 1,  1,  -3},
                {3,  -3, 3,  -1},
                {3,  3,  -2, -2}};
    Matrix d = {{-1, -1, 1,  1},
                {1,  2,  -2, -2},
                {1,  2,  -1, -3},
                {-1, -2, 1,  2}};
    Matrix right = inverse(a) * d * inverse(c);
    right = inverse(right);
    std::cout << right - b << std::endl;
    return 0;
}
