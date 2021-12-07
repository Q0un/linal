#include "permutation.h"

Permutation::Permutation(const std::vector<uint32_t>& data) : Matrix(data.size(), data.size()) {
    for (size_t i = 0; i < data.size(); ++i) {
        operator[](i)[data[i] - 1] = 1;
    }
}

Permutation::Permutation(std::vector<uint32_t>&& data) : Matrix(data.size(), data.size()) {
    for (size_t i = 0; i < data.size(); ++i) {
        operator[](i)[data[i] - 1] = 1;
    }
}

Permutation::Permutation(std::initializer_list<uint32_t> data) : Matrix(data.size(), data.size()) {
    size_t i = 0;
    for (const auto& el : data) {
        operator[](i++)[el - 1] = 1;
    }
}