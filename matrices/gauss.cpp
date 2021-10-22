#include "gauss.h"

std::pair<Matrix, char> Gauss::SolveGauss(const Matrix& a, const Matrix& b) {
    return SolveGauss(a | b);
}

std::pair<Matrix, char> Gauss::SolveGauss(Matrix a) {
    if (a.IsEmpty()) {
        throw std::runtime_error("Wrong sizes");
    }
    size_t height = a.GetHeight();
    size_t width = a.GetWidth();
    std::vector<size_t> not_zero(height, -1);
    size_t col = 0;
    size_t row = 0;
    while (row < height && col < width - 1) {
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
        not_zero[row] = col;
        Fraction to_del = a[row][col];
        a[row] /= to_del;
        for (size_t i = row + 1; i < height; ++i) {
            a[i] -= a[row] * a[i][col];
        }
        ++row;
        ++col;
    }
    while (row < height) {
        not_zero[row++] = width - 1;
    }
    Matrix result(width - 1, 1);
    bool is_inf = height < (width - 1);
    for (size_t i = height; i-- > 0;) {
        if (not_zero[i] == width - 1) {
            if (a[i][width - 1] != 0) {
                return {Matrix(), 0};
            }
        } else {
            Fraction sum;
            for (size_t j = not_zero[i] + 1; j < width - 1; ++j) {
                sum += a[i][j] * result[j][0];
            }
            result[not_zero[i]][0] = a[i][width - 1] - sum;
        }
    }
    if (is_inf) {
        return {result, -1};
    }
    return {result, 1};
}