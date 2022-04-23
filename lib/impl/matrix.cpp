#include "matrix.h"

#include <iomanip>

Matrix::Matrix(size_t h, size_t w, Fraction val) : data_(h, MatrixRow(w)) {
    if (h == w) {
        for (size_t i = 0; i < h; ++i) {
            data_[i][i] = val;
        }
    }
}

Matrix::Matrix(std::vector<MatrixRow> data) : data_(std::move(data)) {
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
    if (height() != other.height()) {
        throw std::runtime_error("Wrong sizes");
    }
    Matrix result(height());
    for (size_t i = 0; i < height(); ++i) {
        result[i] = operator[](i) | other[i];
    }
    return result;
}

Matrix& Matrix::operator|=(const Matrix& other) {
    if (height() != other.height()) {
        throw std::runtime_error("Wrong sizes");
    }
    for (size_t i = 0; i < height(); ++i) {
        operator[](i) |= other[i];
    }
    return *this;
}

Matrix Matrix::operator-() const {
    Matrix result(height());
    for (size_t i = 0; i < height(); ++i) {
        result[i] = -data_[i];
    }
    return result;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (height() != other.height() || getWidth() != other.getWidth()) {
        throw std::runtime_error("Wrong sizes");
    }
    Matrix result(height(), getWidth());
    for (size_t i = 0; i < height(); ++i) {
        for (size_t j = 0; j < getWidth(); ++j) {
            result[i][j] = operator[](i)[j] + other[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator+(const Fraction& other) const {
    if (height() != getWidth()) {
        throw std::runtime_error("Not square");
    }
    Matrix matrix(height(), getWidth(), other);
    return operator+(matrix);
}

Matrix Matrix::operator-(const Matrix& other) const {
    return operator+(-other);
}

Matrix Matrix::operator-(const Fraction& other) const {
    return operator+(-other);
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (getWidth() != other.height()) {
        throw std::runtime_error("Wrong sizes");
    }
    size_t height = height();
    size_t width = other.getWidth();
    Matrix result(height, width);
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            for (size_t k = 0; k < getWidth(); ++k) {
                result[i][j] += operator[](i)[k] * other[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(const Fraction& other) const {
    Matrix result(height(), getWidth());
    for (size_t i = 0; i < height(); ++i) {
        for (size_t j = 0; j < getWidth(); ++j) {
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

bool Matrix::operator==(const Matrix& other) const {
    return data_ == other.data_;
}

size_t Matrix::height() const {
    return data_.size();
}

size_t Matrix::getWidth() const {
    return data_.empty() ? 0 : data_[0].size();
}

bool Matrix::empty() const {
    return data_.empty();
}

Matrix Matrix::T() const {
    Matrix res(getWidth(), height());
    for (int i = 0; i < height(); ++i) {
        for (int j = 0; j < getWidth(); ++j) {
            res[j][i] = data_[i][j];
        }
    }
    return res;
}

Matrix Matrix::operator()(const Matrix& v) const {
    auto vt = v.T();
    return operator*(vt);
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix) {
    if (matrix.empty()) {
        return stream;
    }
    size_t width = matrix.maxLenOfElement();
    for (size_t i = 0; i < matrix.height(); ++i) {
        for (size_t j = 0; j < matrix.getWidth(); ++j) {
            stream << matrix[i][j];
            if (j + 1 < matrix.getWidth()) {
                stream << "  " << std::setw(width);
            }
        }
        if (i + 1 < matrix.height()) {
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

Matrix Matrix::E(size_t n) {
    Matrix e(n, n);
    for (size_t i = 0; i < n; ++i) {
        e[i][i] = Fraction(1);
    }
    return e;
}

size_t Matrix::maxLenOfElement() const {
    size_t result = 0;
    for (const auto& i : data_) {
        for (const auto& el : i) {
            result = std::max(result, el.length());
        }
    }
    return result;
}
