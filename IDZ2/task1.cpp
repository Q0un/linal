#include <iostream>

#include "permutation.h"
#include "permutation_utils.h"

int main() {
    Permutation a = {2, 5, 6, 8, 1, 3, 4, 7};
    Permutation b = {8, 6, 4, 3, 1, 7, 5, 2};
    Permutation d = pow(inverse(a) * pow(b, 11), 167);
    std::vector<uint32_t> perm = {1, 2, 3, 4, 5, 6, 7, 8};
    Permutation c = {4, 7, 2, 8, 1, 6, 3, 5};
    do {
        Permutation x(perm);
        if (x * c * x == d) {
            std::cout << x << std::endl;
        }
    } while (nextPermutation(perm.begin(), perm.end()));
    return 0;
}
