#pragma once

#include "matrix.h"

class Permutation : public Matrix {
    Permutation(const std::vector<uint32_t>& data);
    Permutation(std::vector<uint32_t>&& data);
    Permutation(std::initializer_list<uint32_t> data);
};
