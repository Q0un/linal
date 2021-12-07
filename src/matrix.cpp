#include "matrix.h"

#include <algorithm>
#include <iomanip>

Matrix::Matrix(size_t h, size_t w, Fraction val) : data_(h, MatrixRow(w)) {
    if (h == w) {
        for (size_t i = 0; i < h; ++i) {
            data_[i][i] = val;
        }
    }
}

Matrix::Matrix(const std::vector<MatrixRow>& data) : data_(data) {
}

Matrix::Matrix(std::vector<MatrixRow>&& data) : data_(std::move(data)) {
}

Matrix::Matrix(std::initializer_list<MatrixRow> data) : data_(data) {
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

Matrix Matrix::operator-() const {
    Matrix result(GetHeight());
    for (size_t i = 0; i < GetHeight(); ++i) {
        result[i] = -data_[i];
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (GetHeight() != other.GetHeight() || GetWidth() != other.GetWidth()) {
        throw std::runtime_error("Wrong sizes");
    }
    Matrix result(GetHeight(), GetWidth());
    for (size_t i = 0; i < GetHeight(); ++i) {
        for (size_t j = 0; j < GetWidth(); ++j) {
            result[i][j] = operator[](i)[j] + other[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+(const Fraction& other) const {
    if (GetHeight() != GetWidth()) {
        throw std::runtime_error("Not square");
    }
    Matrix matrix(GetHeight(), GetWidth(), other);
    return operator+(matrix);
}

Matrix Matrix::operator-(const Matrix& other) const {
    return operator+(-other);
}

Matrix Matrix::operator-(const Fraction& other) const {
    return operator+(-other);
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (GetWidth() != other.GetHeight()) {
        throw std::runtime_error("Wrong sizes");
    }
    size_t height = GetHeight();
    size_t width = other.GetWidth();
    Matrix result(height, width);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            for (size_t k = 0; k < GetWidth(); ++k) {
                result[i][j] += operator[](i)[k] * other[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(const Fraction& other) const {
    Matrix result(GetHeight(), GetWidth());
    for (size_t i = 0; i < GetHeight(); ++i) {
        for (size_t j = 0; j < GetWidth(); ++j) {
            result[i][j] = operator[](i)[j] * other;
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    return (*this) = operator+(other);
}

Matrix& Matrix::operator+=(const Fraction& other) {
    return (*this) = operator+(other);
}

Matrix& Matrix::operator-=(const Matrix& other) {
    return (*this) = operator-(other);
}

Matrix& Matrix::operator-=(const Fraction& other) {
    return (*this) = operator-(other);
}

Matrix& Matrix::operator*=(const Matrix& other) {
    return (*this) = operator*(other);
}

Matrix& Matrix::operator*=(const Fraction& other) {
    return (*this) = operator*(other);
}

Matrix operator+(const Fraction& val, const Matrix& a) {
    return a + val;
}

Matrix operator-(const Fraction& val, const Matrix& a) {
    return -(a - val);
}

Matrix operator*(const Fraction& val, const Matrix& a) {
    return a * val;
}

Matrix Matrix::operator~() const {

}

bool Matrix::operator==(const Matrix& other) const {
    return data_ == other.data_;
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
    size_t width = matrix.GetMaxLenOfElement();
    for (size_t i = 0; i < matrix.GetHeight(); ++i) {
        for (size_t j = 0; j < matrix.GetWidth(); ++j) {
            stream << matrix[i][j];
            if (j + 1 < matrix.GetWidth()) {
                stream << "  " << std::setw(width);
            }
        }
        if (i + 1 < matrix.GetHeight()) {
            stream << std::endl;
        }
    }
    return stream;
}

std::vector<MatrixRow>::iterator Matrix::begin() {
    return data_.begin();
}

std::vector<MatrixRow>::const_iterator Matrix::begin() const {
    return data_.begin();
}

std::vector<MatrixRow>::iterator Matrix::end() {
    return data_.end();
}

std::vector<MatrixRow>::const_iterator Matrix::end() const {
    return data_.end();
}

size_t Matrix::GetMaxLenOfElement() const {
    size_t result = 0;
    for (const auto& i : data_) {
        for (const auto& el : i) {
            result = std::max(result, el.GetLen());
        }
    }
    return result;
}

Matrix Pow(const Matrix& a, size_t p) {
    if (p == 1) {
        return a;
    }
    if (p & 1) {
        return a * Pow(a, p - 1);
    }
    return Pow(a * a, p >> 1);
}

Matrix Det(const Matrix& a) {

}
