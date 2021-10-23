#include "gauss.h"

Matrix Gauss::MakeTriangle(const Matrix& a) {
    Matrix result = a;
    size_t height = result.GetHeight();
    size_t width = result.GetWidth();
    size_t col = 0;
    size_t row = 0;
    while (row < height && col < width - 1) {
        size_t new_row = row;
        for (size_t i = row; i < height; ++i) {
            if (result[i][col].GetAbs() > result[new_row][col].GetAbs()) {
                new_row = i;
            }
        }
        if (result[new_row][col].GetAbs() == 0) {
            ++col;
            continue;
        }
        std::swap(result[row], result[new_row]);
        Fraction to_del = result[row][col];
        result[row] /= to_del;
        for (size_t i = row + 1; i < height; ++i) {
            result[i] -= result[row] * result[i][col];
        }
        ++row;
        ++col;
    }
    return result;
}

std::pair<Matrix, int16_t> Gauss::SolveSOLE(const Matrix &a, const Matrix &b) {
    if (a.IsEmpty()) {
        throw std::runtime_error("Wrong sizes");
    }
    Matrix matrix = MakeTriangle(a | b);
    size_t height = matrix.GetHeight();
    size_t width = matrix.GetWidth();
    std::vector<size_t> not_zero(height);
    for (size_t i = 0; i < height; ++i) {
        size_t j = 0;
        while (j < width - 1 && matrix[i][j] == 0) {
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
            if (matrix[i][width - 1] != 0) {
                return {Matrix(), 0};
            }
        } else {
            Fraction sum;
            for (size_t j = not_zero[i] + 1; j < width - 1; ++j) {
                sum += matrix[i][j] * result[j][0];
            }
            result[not_zero[i]][0] = matrix[i][width - 1] - sum;
        }
    }
    if (is_inf) {
        return {result, -1};
    }
    return {result, 1};
}
