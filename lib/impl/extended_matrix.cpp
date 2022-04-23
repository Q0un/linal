#include "extended_matrix.h"

#include <iomanip>

ExtendedMatrix::ExtendedMatrix(const Matrix& a) : Matrix(a | Matrix(a.height(), 1)), leftWidth_(a.width()) {
}

ExtendedMatrix::ExtendedMatrix(const Matrix& a, const Matrix& b) : Matrix(a | b), leftWidth_(a.width()) {
}

size_t ExtendedMatrix::width() const {
    return leftWidth_;
}

size_t ExtendedMatrix::getWholeWidth() const {
    return Matrix::width();
}

Matrix ExtendedMatrix::getLeft() const {
    Matrix result(height(), width());
    for (size_t i = 0; i < height(); ++i) {
        for (size_t j = 0; j < width(); ++j) {
            result[i][j] = operator[](i)[j];
        }
    }
    return result;
}

Matrix ExtendedMatrix::getRight() const {
    Matrix result(height(), getWholeWidth() - width());
    for (size_t i = 0; i < height(); ++i) {
        for (size_t j = width(); j < getWholeWidth(); ++j) {
            result[i][j - width()] = operator[](i)[j];
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& stream, const ExtendedMatrix& matrix) {
    if (matrix.empty()) {
        return stream;
    }
    size_t width = matrix.maxLenOfElement();
    for (size_t i = 0; i < matrix.height(); ++i) {
        for (size_t j = 0; j < matrix.width(); ++j) {
            stream << matrix[i][j];
            if (j + 1 < matrix.width()) {
                stream << "  " << std::setw(width);
            }
        }
        stream << ' ' << std::setw(width) << '|' << ' ';
        for (size_t j = matrix.width(); j < matrix.getWholeWidth(); ++j) {
            stream << std::setw(width) << matrix[i][matrix.width()];
            if (j + 1 < matrix.getWholeWidth()) {
                stream << "  ";
            }
        }
        if (i + 1 < matrix.height()) {
            stream << std::endl;
        }
    }
    return stream;
}
