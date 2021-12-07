#pragma once

#include "matrix.h"

#include <initializer_list>
#include <iostream>
#include <vector>

class Permutation {
public:
    Permutation(const std::vector<uint32_t>& data);
    Permutation(std::vector<uint32_t>&& data);
    Permutation(std::initializer_list<uint32_t> data);
    Permutation(Matrix matrix);

    size_t Size() const;

    Fraction operator[](size_t i) const;

    Permutation operator*(const Permutation& other) const;

    friend std::ostream& operator<<(std::ostream& stream, const Permutation& perm);

    const Matrix& GetMatrix() const;

private:
    Matrix matrix_;
};
