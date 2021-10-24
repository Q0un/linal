#include "extended_matrix.h"

ExtendedMatrix::ExtendedMatrix(const Matrix& a) : Matrix(a | Matrix(a.GetHeight(), 1)) {
}

ExtendedMatrix::ExtendedMatrix(const Matrix& a, const Matrix& b) : Matrix(a | b) {
}

size_t ExtendedMatrix::GetWidth() const {
    return Matrix::GetWidth() - 1;
}

std::ostream& operator<<(std::ostream& stream, const ExtendedMatrix& matrix) {
    if (matrix.IsEmpty()) {
        return stream;
    }
    for (size_t i = 0; i < matrix.GetHeight(); ++i) {
        for (size_t j = 0; j < matrix[i].GetSize() - 1; ++j) {
            stream << matrix[i][j] << '\t';
        }
        stream << '|' << '\t';
        stream << matrix[i][matrix[i].GetSize() - 1];
        if (i + 1 != matrix.GetHeight()) {
            stream << std::endl;
        }
    }
    return stream;
}
