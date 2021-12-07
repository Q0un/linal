#include <iostream>

#include "permutation.h"
#include "permutation_utils.h"

int main() {
    Permutation a = {2, 5, 6, 8, 1, 3, 4, 7};
    Permutation b = {8, 6, 4, 3, 1, 7, 5, 2};
    std::cout << Inverse(a) * Pow(b, 11);
    return 0;
}
