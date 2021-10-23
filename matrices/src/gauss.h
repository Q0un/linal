#pragma once
#include <stdexcept>
#include <cmath>
#include <vector>

#include "matrix.h"

class Gauss {
public:
    static Matrix MakeTriangle(const Matrix &a);
    static std::pair<Matrix, int16_t> SolveSOLE(const Matrix &a, const Matrix& b);
};
