#include <iostream>

#include "matrix.h"
#include "gauss.h"

int main() {
    std::cout << Gauss::MakeTriangle({{9, -7, 7},
                                      {4, -6, 9}}) << std::endl << "=========" << std::endl;
    return 0;
}