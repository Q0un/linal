#include "extended_matrix.h"

#include <iomanip>

ExtendedMatrix::ExtendedMatrix(const Matrix& a) : Matrix(a | Matrix(a.GetHeight(), 1)), leftWidth_(a.getWidth()) {
}

ExtendedMatrix::ExtendedMatrix(const Matrix& a, const Matrix& b) : Matrix(a | b), leftWidth_(a.getWidth()) {
}

size_t ExtendedMatrix::getWidth() const {
    return leftWidth_;
}

size_t ExtendedMatrix::getWholeWidth() const {
    return Matrix::getWidth();
}

Matrix ExtendedMatrix::getLeft() const {
    Matrix result(GetHeight(), getWidth());
    for (size_t i = 0; i < GetHeight(); ++i) {
        for (size_t j = 0; j < getWidth(); ++j) {
            result[i][j] = operator[](i)[j];
        }
    }
    return result;
}

Matrix ExtendedMatrix::getRight() const {
    Matrix result(GetHeight(), getWholeWidth() - getWidth());
    for (size_t i = 0; i < GetHeight(); ++i) {
        for (size_t j = getWidth(); j < getWholeWidth(); ++j) {
            result[i][j - getWidth()] = operator[](i)[j];
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
        for (size_t j = 0; j < matrix.getWidth(); ++j) {
            stream << matrix[i][j];
            if (j + 1 < matrix.getWidth()) {
                stream << "  " << std::setw(width);
            }
        }
        stream << ' ' << std::setw(width) << '|' << ' ';
        for (size_t j = matrix.getWidth(); j < matrix.getWholeWidth(); ++j) {
            stream << std::setw(width) << matrix[i][matrix.getWidth()];
            if (j + 1 < matrix.getWholeWidth()) {
                stream << "  ";
            }
        }
        if (i + 1 < matrix.GetHeight()) {
            stream << std::endl;
        }
    }
    return stream;
}