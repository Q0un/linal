#pragma once
#include "matrix.h"
#include "gauss.h"

Matrix Pow(const Matrix& a, size_t p) {
    if (p == 1) {
        return a;
    }
    if (p & 1) {
        return a * Pow(a, p - 1);
    }
    return Pow(a * a, p >> 1);
}

Fraction Det(const Matrix& a) {
    if (a.IsEmpty() || a.GetWidth() != a.GetHeight()) {
        throw std::runtime_error("Wrong sizes");
    }
    Gauss::MakeTriangle(a);
    Fraction res = 1;
    for (size_t i = 0; i < a.GetHeight(); ++i) {
        res *= a[i][i];
    }
    return res;
}

Matrix Inverse(const Matrix& a) {
    if (a.IsEmpty() || a.GetWidth() != a.GetHeight()) {
        throw std::runtime_error("Wrong sizes");
    }
    if (Det(a) == 0) {
        throw std::runtime_error("Determinant is zero");
    }
    Matrix e(a.GetHeight(), a.GetHeight());
    for (size_t i = 0; i < e.GetHeight(); ++i) {
        e[i][i] = 1;
    }
    ExtendedMatrix b(a, e);
    Gauss::MakeTriangle(b);
    for (size_t i = b.GetWidth() - 1; i >= 0; --i) {
        for (size_t j = 0; j < i; ++j) {
            b[j] -= a[i] * b[j][i];
        }
    }
    return b.GetRight();
}
