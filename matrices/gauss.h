#pragma once
#include <stdexcept>
#include <cmath>
#include <vector>

#include "matrix.h"

class Gauss {
public:
    static std::pair<Matrix, char> SolveGauss(const Matrix& a, const Matrix& b);
    static std::pair<Matrix, char> SolveGauss(Matrix a);
};
