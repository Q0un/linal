#pragma once

#include <algorithm>

#include "permutation.h"

Permutation pow(const Permutation& a, size_t p);

Permutation inverse(const Permutation& a);

template<typename It>
bool nextPermutation(It begin, It end) {
    if (begin == end)
        return false;
    It i = end;
    --i;
    if (i == begin)
        return false;
    while (true) {
        It j = i;
        --i;
        if (*i < *j) {
            It k = end;
            while (*i >= *--k) {}
            std::iter_swap(i, k);
            std::reverse(j, end);
            return true;
        }
        if (i == begin) {
            std::reverse(begin, end);
            return false;
        }
    }
}
