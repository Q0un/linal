#pragma once
#include <stdexcept>
#include <cmath>
#include <vector>

#include "matrix.h"
#include "extended_matrix.h"

Fraction makeTriangle(Matrix& a);
void makeSuperTriangle(Matrix& a);
std::pair<Matrix, int16_t> solveSOLE(const Matrix &a, const Matrix& b);
std::pair<Matrix, int16_t> solveSOLE(const ExtendedMatrix& a);
