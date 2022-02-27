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
    Matrix X1 = Inverse(X);
    Matrix Y1 = Inverse(Y);
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
    A[0] = SolveSOLE(Aleft, Aright1).first.Transpose()[0];
    A[1] = SolveSOLE(Aleft, Aright2).first.Transpose()[0];
    A[2] = SolveSOLE(Aleft, Aright3).first.Transpose()[0];
    std::cout << A << std::endl;
    return 0;
}