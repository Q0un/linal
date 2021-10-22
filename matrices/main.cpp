#include <iostream>
#include <vector>

#include "gauss.h"
#include "matrix.h"
#include "matrix_row.h"

int main() {
    size_t n, m;
    std::cin >> n >> m;
    Matrix matrix(n, m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            int64_t x;
            std::cin >> x;
            matrix[i][j] = x;
        }
    }
    auto res = Gauss::SolveGauss(matrix);
    std::cout << res.first << std::endl << (int)(res.second);
}