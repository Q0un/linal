#pragma once
#include "matrix.h"
#include "gauss.h"
#include "poly.h"
#include "permutation_utils.h"

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

Poly GetCharPoly(const Matrix& a) {
    if (a.IsEmpty() || a.GetHeight() != a.GetWidth()) {
        throw std::runtime_error("wrong sizes");
    }
    std::vector<std::vector<Poly>> b(a.GetHeight(), std::vector<Poly>(a.GetWidth()));
    for (size_t i = 0; i < a.GetHeight(); ++i) {
        for (size_t j = 0; j < a.GetWidth(); ++j) {
            if (i == j) {
                b[i][j] = {a[i][j], -1};
            } else {
                b[i][j] = {a[i][j]};
            }
        }
    }
    std::vector<size_t> perm(b.size());
    for (size_t i = 0; i < perm.size(); ++i) {
        perm[i] = i;
    }
    Poly det;
    do {
        Poly k = {1};
        for (size_t i = 0; i < b.size(); ++i) {
            k *= b[i][perm[i]];
        }
        size_t x = 0;
        for (size_t i = 0; i < b.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (perm[j] > perm[i]) {
                    ++x;
                }
            }
        }
        if (x & 1) {
            k *= Fraction(-1);
        }
        det += k;
    } while (NextPermutation(perm.begin(), perm.end()));
    return det;
}
