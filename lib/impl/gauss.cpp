#include "gauss.h"

Fraction makeTriangle(Matrix& a) {
    size_t height = a.height();
    size_t width = a.width();
    size_t col = 0;
    size_t row = 0;
    Fraction div = 1;
    while (row < height && col < width) {
        size_t new_row = row;
        for (size_t i = row; i < height; ++i) {
            if (a[i][col].abs() > a[new_row][col].abs()) {
                new_row = i;
            }
        }
        if (a[new_row][col].abs() == 0) {
            ++col;
            continue;
        }
        std::swap(a[row], a[new_row]);
        Fraction to_del = a[row][col];
        a[row] /= to_del;
        div *= to_del;
        for (size_t i = row + 1; i < height; ++i) {
            a[i] -= a[row] * a[i][col];
        }
        ++row;
        ++col;
    }
    return div;
}

void makeSuperTriangle(Matrix& a) {
    makeTriangle(a);
    for (size_t i = 0; i < a.height(); ++i) {
        int j = 0;
        while (j < a.width() && a[i][j] == 0) {
            ++j;
        }
        if (j == a.width()) {
            break;
        }
        for (int k = i - 1; k >= 0; --k) {
            a[k] -= a[i] * a[k][j];
        }
    }
}

std::pair<Matrix, int16_t> solveSOLE(const Matrix &a, const Matrix &b) {
    return solveSOLE(ExtendedMatrix(a, b));
}

std::pair<Matrix, int16_t> solveSOLE(const ExtendedMatrix& a) {
    if (a.empty()) {
        throw std::runtime_error("Wrong sizes");
    }
    ExtendedMatrix triangle = a;
    makeTriangle(triangle);
    size_t height = triangle.height();
    size_t width = triangle.width();
    std::vector<size_t> not_zero(height);
    for (size_t i = 0; i < height; ++i) {
        size_t j = 0;
        while (j < width && triangle[i][j] == 0) {
            ++j;
        }
        not_zero[i] = j;
    }
    Matrix result(width, 1);
    size_t cnt_mains = 0;
    for (size_t i = 0; i < height; ++i) {
        if (not_zero[i] < width) {
            ++cnt_mains;
        }
    }
    bool is_inf = cnt_mains < width;
    for (size_t i = height; i-- > 0;) {
        if (not_zero[i] == width) {
            if (triangle[i][width] != 0) {
                return {Matrix(), 0};
            }
        } else {
            Fraction sum;
            for (size_t j = not_zero[i] + 1; j < width; ++j) {
                sum += triangle[i][j] * result[j][0];
            }
            result[not_zero[i]][0] = triangle[i][width] - sum;
        }
    }
    if (is_inf) {
        return {result, -1};
    }
    return {result, 1};
}
