#pragma once
#include "matrix.h"
#include "poly.h"

Matrix Pow(const Matrix& a, size_t p);

Fraction Det(const Matrix& a);

Matrix Inverse(const Matrix& a);

Poly GetCharPoly(const Matrix& a);
