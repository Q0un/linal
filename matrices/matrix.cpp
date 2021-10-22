#include "matrix.h"

Matrix::Matrix(size_t h, size_t w) : data_(h, MatrixRow(w)) {
}

Matrix::Matrix(const std::vector<MatrixRow>& data) : data_(data) {
}

Matrix::Matrix(std::vector<MatrixRow>&& data) : data_(std::move(data)) {
}

MatrixRow& Matrix::operator[](size_t ind) {
    return data_[ind];
}

const MatrixRow& Matrix::operator[](size_t ind) const {
    return data_[ind];
}

Matrix Matrix::operator|(const Matrix& other) const {
    if (GetHeight() != other.GetHeight()) {
        throw std::runtime_error("Wrong sizes");
    }
    Matrix result(GetHeight());
    for (size_t i = 0; i < GetHeight(); ++i) {
        result[i] = operator[](i) | other[i];
    }
    return result;
}

Matrix& Matrix::operator|=(const Matrix& other) {
    if (GetHeight() != other.GetHeight()) {
        throw std::runtime_error("Wrong sizes");
    }
    for (size_t i = 0; i < GetHeight(); ++i) {
        operator[](i) |= other[i];
    }
    return *this;
}

size_t Matrix::GetHeight() const {
    return data_.size();
}

size_t Matrix::GetWidth() const {
    return data_.empty() ? 0 : data_[0].GetSize();
}

bool Matrix::IsEmpty() const {
    return data_.empty();
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
    if (matrix.IsEmpty()) {
        return stream;
    }
    for (size_t i = 0; i < matrix.GetHeight() - 1; ++i) {
        stream << matrix[i] << std::endl;
    }
    stream << matrix[matrix.GetHeight() - 1];
    return stream;
}
