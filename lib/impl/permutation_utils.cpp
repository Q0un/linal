#include "permutation_utils.h"

#include "matrix_utils.h"

Permutation pow(const Permutation& a, size_t p) {
    return Permutation(pow(a.matrix(), p));
}

Permutation inverse(const Permutation& a) {
    return Permutation(inverse(a.matrix()));
}
