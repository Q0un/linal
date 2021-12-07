#include "extended_matrix.h"

#include <iomanip>

ExtendedMatrix::ExtendedMatrix(const Matrix& a) : Matrix(a | Matrix(a.GetHeight(), 1)), leftWidth_(a.GetWidth()) {
}

ExtendedMatrix::ExtendedMatrix(const Matrix& a, const Matrix& b) : Matrix(a | b), leftWidth_(a.GetWidth()) {
}

size_t ExtendedMatrix::GetWidth() const {
    return leftWidth_;
}

size_t ExtendedMatrix::GetWholeWidth() const {
    return Matrix::GetWidth();
}

Matrix ExtendedMatrix::GetLeft() const {
    Matrix result(GetHeight(), GetWidth());
    for (size_t i = 0; i < GetHeight(); ++i) {
        for (size_t j = 0; j < GetWidth(); ++j) {
            result[i][j] = operator[](i)[j];
        }
    }
    return result;
}

Matrix ExtendedMatrix::GetRight() const {
    Matrix result(GetHeight(), GetWholeWidth() - GetWidth());
    for (size_t i = 0; i < GetHeight(); ++i) {
        for (size_t j = GetWidth(); j < GetWholeWidth(); ++j) {
            result[i][j - GetWidth()] = operator[](i)[j];
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& stream, const ExtendedMatrix& matrix) {
    if (matrix.IsEmpty()) {
        return stream;
    }
    size_t width = matrix.GetMaxLenOfElement();
    for (size_t i = 0; i < matrix.GetHeight(); ++i) {
        for (size_t j = 0; j < matrix.GetWidth(); ++j) {
            stream << matrix[i][j];
            if (j + 1 < matrix.GetWidth()) {
                stream << "  " << std::setw(width);
            }
        }
        stream << ' ' << std::setw(width) << '|' << ' ';
        for (size_t j = matrix.GetWidth(); j < matrix.GetWholeWidth(); ++j) {
            stream << std::setw(width) << matrix[i][matrix.GetWidth()];
            if (j + 1 < matrix.GetWholeWidth()) {
                stream << "  ";
            }
        }
        if (i + 1 < matrix.GetHeight()) {
            stream << std::endl;
        }
    }
    return stream;
}
