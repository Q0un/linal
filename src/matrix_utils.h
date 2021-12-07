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
    Matrix b = a;
    Gauss::MakeTriangle(b);
    Fraction res = 1;
    for (size_t i = 0; i < b.GetHeight(); ++i) {
        res *= b[i][i];
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
    for (int32_t i = b.GetHeight() - 1; i != -1; --i) {
        for (size_t j = 0; j < i; ++j) {
            b[j] -= b[i] * b[j][i];
        }
    }
    return b.GetRight();
}
