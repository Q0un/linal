#include "matrix_utils.h"

#include "gauss.h"
#include "permutation_utils.h"

Matrix pow(const Matrix& a, size_t p) {
    if (a.height() != a.width()) {
        throw std::runtime_error("Not square matrix");
    }
    if (p == 0) {
        return Matrix::E(a.height());
    }
    if (p & 1) {
        return a * pow(a, p - 1);
    }
    return pow(a * a, p >> 1);
}

Fraction det(const Matrix& a) {
    if (a.empty() || a.width() != a.height()) {
        throw std::runtime_error("Wrong sizes");
    }
    Matrix b = a;
    makeTriangle(b);
    Fraction res = 1;
    for (size_t i = 0; i < b.height(); ++i) {
        res *= b[i][i];
    }
    return res;
}

Matrix inverse(const Matrix& a) {
    if (a.empty() || a.width() != a.height()) {
        throw std::runtime_error("Wrong sizes");
    }
    if (det(a) == 0) {
        throw std::runtime_error("determinant is zero");
    }
    Matrix e(a.height(), a.height());
    for (size_t i = 0; i < e.height(); ++i) {
        e[i][i] = 1;
    }
    ExtendedMatrix b(a, e);
    makeTriangle(b);
    for (int32_t i = b.height() - 1; i != -1; --i) {
        for (size_t j = 0; j < i; ++j) {
            b[j] -= b[i] * b[j][i];
        }
    }
    return b.getRight();
}

Poly getCharPoly(const Matrix& a) {
    if (a.empty() || a.height() != a.width()) {
        throw std::runtime_error("Wrong sizes");
    }
    std::vector<std::vector<Poly>> b(a.height(),
                                     std::vector<Poly>(a.width()));
    for (size_t i = 0; i < a.height(); ++i) {
        for (size_t j = 0; j < a.width(); ++j) {
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
    } while (nextPermutation(perm.begin(), perm.end()));
    return det;
}

size_t rank(const Matrix& a) {
    Matrix b = a;
    makeTriangle(b);
    for (size_t i = 0; i < b.height(); ++i) {
        bool zero = true;
        for (const auto& j: b[i]) {
            if (j != 0) {
                zero = false;
            }
        }
        if (zero) {
            return i;
        }
    }
    return b.height();
}

Matrix getJNF(const Matrix& a, const std::vector<std::pair<Fraction,
        size_t>>& roots) {
    if (a.height() != a.width()) {
        throw std::runtime_error("Not square matrix");
    }
    Matrix result(a.height(), a.width());
    size_t last = 0;
    for (const auto&[root, d]: roots) {
        for (size_t k = 1; k <= d; ++k) {
            Matrix b = a - root * Matrix::E(a.height());
            Matrix c = pow(b, k - 1);
            size_t cnt = rank(c * b * b) + rank(c) - 2 * rank(c * b);
            for (size_t i = 0; i < cnt; ++i) {
                for (size_t j = 0; j < k; ++j) {
                    result[last][last] = root;
                    if (j > 0) {
                        result[last - 1][last] = 1;
                    }
                    ++last;
                }
            }
        }
    }
    return result;
}
