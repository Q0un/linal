#include <iostream>

#include "gauss.h"
#include "matrix.h"
#include "matrix_utils.h"

int main() {
    Matrix X = {{-1, 1, 3},
                {1,  1, 1},
                {1,  1, -5}};
    Matrix Y = {{1, 1,  1},
                {1, -1, -2},
                {1, 0,  0}};
    Matrix X1 = inverse(X);
    Matrix Y1 = inverse(Y);
    Matrix B = {{1,  1, -2},
                {-2, 1, 1},
                {3,  1, 5}};
    Matrix C = {{5,  5,  1},
                {-2, 1,  1},
                {5,  -1, 2}};
    std::cout << X * B << std::endl << "================\n";
    std::cout << Y * C << std::endl << "================\n";

    Matrix Aleft = {{-1, 1,  1},
                    {1,  -1, 0},
                    {1,  -2, 0}};
    Matrix Aright1 = {{6},
                      {5},
                      {4}};
    Matrix Aright2 = {{2},
                      {6},
                      {-4}};
    Matrix Aright3 = {{-16},
                      {5},
                      {1}};
    Matrix A(3);
    A[0] = solveSOLE(Aleft, Aright1).first.T()[0];
    A[1] = solveSOLE(Aleft, Aright2).first.T()[0];
    A[2] = solveSOLE(Aleft, Aright3).first.T()[0];
    std::cout << A << std::endl;
    return 0;
}