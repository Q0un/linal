#pragma once

#include <iostream>

#include "matrix.h"

class ExtendedMatrix : public Matrix {
public:
    explicit ExtendedMatrix(const Matrix& a);
    ExtendedMatrix(const Matrix& a, const Matrix& b);
    ExtendedMatrix(const ExtendedMatrix& a) = default;
    ExtendedMatrix(ExtendedMatrix&& a) = default;

    size_t width() const override;
    size_t getWholeWidth() const;

    Matrix getLeft() const;
    Matrix getRight() const;

    friend std::ostream& operator<<(std::ostream& stream, const ExtendedMatrix& matrix);

private:
    size_t leftWidth_;
};
