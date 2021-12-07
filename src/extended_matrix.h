#pragma once

#include <iostream>

#include "matrix.h"

class ExtendedMatrix : public Matrix {
public:
    ExtendedMatrix(const Matrix& a);
    ExtendedMatrix(const Matrix& a, const Matrix& b);
    ExtendedMatrix(const ExtendedMatrix& a) = default;
    ExtendedMatrix(ExtendedMatrix&& a) = default;

    size_t GetWidth() const override;
    size_t GetWholeWidth() const;

    Matrix GetLeft() const;
    Matrix GetRight() const;

    friend std::ostream& operator<<(std::ostream& stream, const ExtendedMatrix& matrix);

private:
    size_t leftWidth_;
};
