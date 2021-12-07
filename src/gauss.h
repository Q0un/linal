#pragma once
#include <stdexcept>
#include <cmath>
#include <vector>

#include "matrix.h"
#include "extended_matrix.h"

class Gauss {
public:
    static void MakeTriangle(Matrix& a);
    static std::pair<Matrix, int16_t> SolveSOLE(const Matrix &a, const Matrix& b);
    static std::pair<Matrix, int16_t> SolveSOLE(const ExtendedMatrix& a);
};