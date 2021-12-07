#include "poly.h"

int main() {
    Poly x = {0, 1};
    std::vector<std::vector<Poly>> m = {{{-2}, {3},  {7},  {-2}, {7},  x,    {-5}},
                                        {{4},  x,    {7},  {4},  x,    {-3}, {-3}},
                                        {x,    {-5}, {-2}, {-1}, {9},  {6},  {-2}},
                                        {{-4}, {-8}, {-4}, x,    {-6}, {-7}, {-9}},
                                        {{-7}, {-2}, {8},  {7},  {-2}, {-4}, x},
                                        {x,    {-7}, {-8}, {3},  {-4}, {3},  {1}},
                                        {{-9}, {8},  x,    {-4}, {-4}, {-2}, {-7}}};
    size_t n = 7;
    std::vector<size_t> perm = {0, 1, 2, 3, 4, 5, 6};
    Poly det;
    do {
        Poly k = {1};
        for (size_t i = 0; i < n; ++i) {
            k *= m[i][perm[i]];
        }
        size_t x = 0;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (perm[j] > perm[i]) {
                    ++x;
                }
            }
        }
        if (x & 1) {
            k *= Fraction(-1);
        }
        det += k;
    } while (std::next_permutation(perm.begin(), perm.end()));
    std::cout << det << std::endl;
    return 0;
}