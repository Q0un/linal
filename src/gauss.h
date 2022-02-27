#pragma once
#include <stdexcept>
#include <cmath>
#include <vector>

#include "matrix.h"
#include "extended_matrix.h"

void MakeTriangle(Matrix& a);
void MakeSuperTriangle(Matrix& a);
std::pair<Matrix, int16_t> SolveSOLE(const Matrix &a, const Matrix& b);
std::pair<Matrix, int16_t> SolveSOLE(const ExtendedMatrix& a);
