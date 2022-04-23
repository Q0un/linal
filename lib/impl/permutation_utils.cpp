#include "permutation_utils.h"

#include "matrix_utils.h"

Permutation Pow(const Permutation& a, size_t p) {
    return Permutation(Pow(a.GetMatrix(), p));
}

Permutation Inverse(const Permutation& a) {
    return Permutation(Inverse(a.GetMatrix()));
}
