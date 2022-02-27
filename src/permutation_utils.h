#pragma once

#include <algorithm>

#include "permutation.h"
#include "matrix_utils.h"

Permutation Pow(const Permutation& a, size_t p) {
    return Permutation(Pow(a.GetMatrix(), p));
}

Permutation Inverse(const Permutation& a) {
    return Permutation(Inverse(a.GetMatrix()));
}

template<typename It>
bool NextPermutation(It begin, It end) {
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
            while (!(*i < *--k)) {}
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
