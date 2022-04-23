#pragma once
#include "matrix.h"
#include "poly.h"

Matrix pow(const Matrix& a, size_t p);

Fraction det(const Matrix& a);

Matrix inverse(const Matrix& a);

Poly getCharPoly(const Matrix& a);

size_t rank(const Matrix& a);

Matrix getJNF(const Matrix& a, const std::vector<std::pair<Fraction,
              size_t>>& roots);
