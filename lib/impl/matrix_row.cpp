#include "matrix_row.h"

#include <stdexcept>

MatrixRow::MatrixRow(size_t size) : data_(size) {
}

MatrixRow::MatrixRow(std::vector<Fraction> data) : data_(std::move(data)) {
}

MatrixRow::MatrixRow(std::vector<Fraction>&& data) : data_(std::move(data)) {
}

MatrixRow::MatrixRow(std::initializer_list<Fraction> data) : data_(data) {
}

size_t MatrixRow::GetSize() const {
    return data_.size();
}

Fraction& MatrixRow::operator[](size_t ind) {
    return data_[ind];
}

const Fraction& MatrixRow::operator[](size_t ind) const {
    return data_[ind];
}

MatrixRow MatrixRow::operator-() const {
    MatrixRow row;
    std::transform(begin(), end(), std::back_inserter(row.data_), [](const Fraction& x) { return -x; });
    return row;
}

MatrixRow MatrixRow::operator+(const MatrixRow& other) const {
    if (GetSize() != other.GetSize()) {
        throw std::runtime_error("Wrong sizes");
    }
    MatrixRow row;
    std::transform(begin(), end(), other.begin(), std::back_inserter(row.data_), std::plus<>());
    return row;
}

MatrixRow MatrixRow::operator+(const Fraction& val) const {
    MatrixRow row;
    std::transform(begin(), end(), std::back_inserter(row.data_), [&val](const Fraction& x) { return x + val; });
    return row;
}

MatrixRow MatrixRow::operator-(const MatrixRow& other) const {
    return operator+(-other);
}

MatrixRow MatrixRow::operator-(const Fraction& val) const {
    return operator+(-val);
}

MatrixRow MatrixRow::operator*(const Fraction& val) const {
    MatrixRow row;
    std::transform(begin(), end(), std::back_inserter(row.data_), [&val](const Fraction& x) { return x * val; });
    return row;
}

MatrixRow MatrixRow::operator/(const Fraction& val) const {
    MatrixRow row;
    std::transform(begin(), end(), std::back_inserter(row.data_), [&val](const Fraction& x) { return x / val; });
    return row;
}

MatrixRow& MatrixRow::operator+=(const MatrixRow& other) {
    if (GetSize() != other.GetSize()) {
        throw std::runtime_error("Wrong sizes");
    }
    std::transform(begin(), end(), other.begin(), begin(), std::plus<>());
    return *this;
}

MatrixRow& MatrixRow::operator+=(const Fraction& val) {
    std::transform(begin(), end(), begin(),
                   [&val](const Fraction& x) { return x + val; });
    return *this;
}

MatrixRow& MatrixRow::operator-=(const MatrixRow& other) {
    return operator+=(-other);
}

MatrixRow& MatrixRow::operator-=(const Fraction& val) {
    return operator+=(-val);
}

MatrixRow& MatrixRow::operator*=(const Fraction& val) {
    std::transform(begin(), end(), begin(), [&val](const Fraction& x) { return x * val; });
    return *this;
}

MatrixRow& MatrixRow::operator/=(const Fraction& val) {
    std::transform(begin(), end(), begin(), [&val](const Fraction& x) { return x / val; });
    return *this;
}

MatrixRow operator+(const Fraction& val, const MatrixRow& row) {
    return row + val;
}

MatrixRow operator-(const Fraction& val, const MatrixRow& row) {
    return -(row - val);
}

MatrixRow operator*(const Fraction& val, const MatrixRow& row) {
    return row * val;
}

MatrixRow MatrixRow::operator|(const MatrixRow& other) const {
    MatrixRow result;
    std::copy(begin(), end(), std::back_inserter(result.data_));
    std::copy(other.begin(), other.end(), std::back_inserter(result.data_));
    return result;
}

MatrixRow& MatrixRow::operator|=(const MatrixRow& other) {
    std::copy(other.begin(), other.end(), std::back_inserter(data_));
    return *this;
}

bool MatrixRow::operator==(const MatrixRow& other) const {
    return data_ == other.data_;
}

std::vector<Fraction>::iterator MatrixRow::begin() {
    return data_.begin();
}

std::vector<Fraction>::const_iterator MatrixRow::begin() const {
    return data_.begin();
}

std::vector<Fraction>::iterator MatrixRow::end() {
    return data_.end();
}

std::vector<Fraction>::const_iterator MatrixRow::end() const {
    return data_.end();
}
