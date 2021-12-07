#include <iostream>

#include "matrix.h"
#include "gauss.h"

int main() {
    Matrix a = {{9, -7, 7},
                {4, -6, 9}};
    Gauss::MakeTriangle(a);
    std::cout << a << std::endl << "=========" << std::endl;
    return 0;
}