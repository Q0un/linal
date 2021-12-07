#include "permutation.h"

Permutation::Permutation(const std::vector<uint32_t>& data) : matrix_(data.size(), data.size()) {
    for (size_t i = 0; i < data.size(); ++i) {
        matrix_[i][static_cast<size_t>(data[i]) - 1] = 1;
    }
}

Permutation::Permutation(std::vector<uint32_t>&& data) : matrix_(data.size(), data.size()) {
    for (size_t i = 0; i < data.size(); ++i) {
        matrix_[i][static_cast<size_t>(data[i]) - 1] = 1;
    }
}

Permutation::Permutation(std::initializer_list<uint32_t> data) : matrix_(data.size(), data.size()) {
    size_t i = 0;
    for (const auto& el : data) {
        matrix_[i++][static_cast<size_t>(el) - 1] = 1;
    }
}

Permutation::Permutation(Matrix matrix) : matrix_(matrix) {
}

size_t Permutation::Size() const {
    return matrix_.GetWidth();
}

Fraction Permutation::operator[](size_t i) const {
    for (size_t j = 0; j < Size(); ++j) {
        if (matrix_[i][j] == 1) {
            return j + 1;
        }
    }
}

Permutation Permutation::operator*(const Permutation &other) const {
    return Permutation(matrix_ * other.matrix_);
}

std::ostream& operator<<(std::ostream& stream, const Permutation& perm) {
    for (size_t i = 0; i < perm.Size(); ++i) {
        stream << i;
        if (i + 1 < perm.Size()) {
            stream << ' ';
        }
    }
    return stream;
}

const Matrix &Permutation::GetMatrix() const {
    return matrix_;
}
