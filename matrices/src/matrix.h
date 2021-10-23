#pragma once

#include <vector>
#include <iostream>

#include "matrix_row.h"

class Matrix {
public:
    Matrix() = default;
    Matrix(size_t h, size_t w = 0, int64_t val = 0);
    Matrix(const std::vector<MatrixRow>& data);
    Matrix(std::vector<MatrixRow>&& data);
    Matrix(std::initializer_list<MatrixRow> data);

    MatrixRow& operator[](size_t ind);
    const MatrixRow& operator[](size_t ind) const;

    Matrix operator|(const Matrix& other) const;
    Matrix& operator|=(const Matrix& other);

    Matrix operator*(const Matrix& other) const;
    Matrix& operator*=(const Matrix& other);

    bool operator==(const Matrix& other) const;

    size_t GetHeight() const;
    size_t GetWidth() const;
    bool IsEmpty() const;

    friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

private:
    std::vector<MatrixRow> data_;
};

Matrix Pow(const Matrix& a, size_t p);
