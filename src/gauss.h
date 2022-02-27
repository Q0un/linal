#pragma once
#include <stdexcept>
#include <cmath>
#include <vector>

#include "matrix.h"
#include "extended_matrix.h"

static void MakeTriangle(Matrix& a);
static void MakeSuperTriangle(Matrix& a);
static std::pair<Matrix, int16_t> SolveSOLE(const Matrix &a, const Matrix& b);
static std::pair<Matrix, int16_t> SolveSOLE(const ExtendedMatrix& a);
