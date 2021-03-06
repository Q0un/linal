#pragma once

#include <vector>
#include <iostream>

#include "matrix_row.h"

class Matrix {
public:
    Matrix() = default;
    explicit Matrix(size_t h, size_t w = 0, Fraction val = Fraction(0));
    explicit Matrix(std::vector<MatrixRow> data);
    explicit Matrix(std::vector<MatrixRow>&& data);
    Matrix(std::initializer_list<MatrixRow> data);

    MatrixRow& operator[](size_t ind);
    const MatrixRow& operator[](size_t ind) const;

    Matrix operator|(const Matrix& other) const;
    Matrix& operator|=(const Matrix& other);

    Matrix operator-() const;
    Matrix operator+(const Matrix& other) const;
    Matrix operator+(const Fraction& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator-(const Fraction& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(const Fraction& other) const;

    Matrix& operator+=(const Matrix& other);
    Matrix& operator+=(const Fraction& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator-=(const Fraction& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(const Fraction& other);

    friend Matrix operator+(const Fraction& val, const Matrix& a);
    friend Matrix operator-(const Fraction& val, const Matrix& a);
    friend Matrix operator*(const Fraction& val, const Matrix& a);

    bool operator==(const Matrix& other) const;

    size_t height() const;
    virtual size_t width() const;
    bool empty() const;

    Matrix T() const;

    Matrix operator()(const Matrix& v) const;

    friend std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);

    std::vector<MatrixRow>::iterator begin();
    std::vector<MatrixRow>::const_iterator begin() const;
    std::vector<MatrixRow>::iterator end();
    std::vector<MatrixRow>::const_iterator end() const;

    static Matrix E(size_t n);

protected:
    std::vector<MatrixRow> data_;

    size_t maxLenOfElement() const;
};
