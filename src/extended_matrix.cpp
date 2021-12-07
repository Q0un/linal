#include "extended_matrix.h"

#include <iomanip>

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
    size_t width = matrix.GetMaxLenOfElement();
    for (size_t i = 0; i < matrix.GetHeight(); ++i) {
        for (size_t j = 0; j < matrix.GetWidth(); ++j) {
            stream << matrix[i][j];
            if (j + 1 < matrix.GetWidth()) {
                stream << "  " << std::setw(width);
            }
        }
        stream << ' ' << std::setw(width) << '|' << ' ';
        stream << std::setw(width) << matrix[i][matrix.GetWidth()];
        if (i + 1 < matrix.GetHeight()) {
            stream << std::endl;
        }
    }
    return stream;
}
