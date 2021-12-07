#include "gauss.h"

void Gauss::MakeTriangle(Matrix& a) {
    size_t height = a.GetHeight();
    size_t width = a.GetWidth();
    size_t col = 0;
    size_t row = 0;
    while (row < height && col < width) {
        size_t new_row = row;
        for (size_t i = row; i < height; ++i) {
            if (a[i][col].GetAbs() > a[new_row][col].GetAbs()) {
                new_row = i;
            }
        }
        if (a[new_row][col].GetAbs() == 0) {
            ++col;
            continue;
        }
        std::swap(a[row], a[new_row]);
        Fraction to_del = a[row][col];
        a[row] /= to_del;
        for (size_t i = row + 1; i < height; ++i) {
            a[i] -= a[row] * a[i][col];
        }
        ++row;
        ++col;
    }
}

std::pair<Matrix, int16_t> Gauss::SolveSOLE(const Matrix &a, const Matrix &b) {
    return Gauss::SolveSOLE(ExtendedMatrix(a, b));
}

std::pair<Matrix, int16_t> Gauss::SolveSOLE(const ExtendedMatrix& a) {
    if (a.IsEmpty()) {
        throw std::runtime_error("Wrong sizes");
    }
    ExtendedMatrix triangle = a;
    MakeTriangle(triangle);
    size_t height = triangle.GetHeight();
    size_t width = triangle.GetWidth();
    std::vector<size_t> not_zero(height);
    for (size_t i = 0; i < height; ++i) {
        size_t j = 0;
        while (j < width - 1 && triangle[i][j] == 0) {
            ++j;
        }
        not_zero[i] = j;
    }
    Matrix result(width - 1, 1);
    size_t cnt_mains = 0;
    for (size_t i = 0; i < height; ++i) {
        if (not_zero[i] < width - 1) {
            ++cnt_mains;
        }
    }
    bool is_inf = cnt_mains < width - 1;
    for (size_t i = height; i-- > 0;) {
        if (not_zero[i] == width - 1) {
            if (triangle[i][width - 1] != 0) {
                return {Matrix(), 0};
            }
        } else {
            Fraction sum;
            for (size_t j = not_zero[i] + 1; j < width - 1; ++j) {
                sum += triangle[i][j] * result[j][0];
            }
            result[not_zero[i]][0] = triangle[i][width - 1] - sum;
        }
    }
    if (is_inf) {
        return {result, -1};
    }
    return {result, 1};
}
