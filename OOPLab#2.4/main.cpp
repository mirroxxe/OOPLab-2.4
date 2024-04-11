#include <iostream>
#include "Matrix.h"

int main() {
    Matrix matrix1(3);
    Matrix matrix2(3);

    matrix1.Read();
    matrix2.Read();

    std::cout << "Matrix 1:" << std::endl;
    matrix1.Display();
    std::cout << "Matrix 2:" << std::endl;
    matrix2.Display();

    Matrix result = matrix1 - matrix2;
    std::cout << "Result of subtraction:" << std::endl;
    result.Display();

    std::cout << "Are matrices equal? " << (matrix1 == matrix2 ? "Yes" : "No") << std::endl;

    std::cout << "Norm of matrix 1: " << matrix1.norm() << std::endl;
    std::cout << "Norm of matrix 2: " << matrix2.norm() << std::endl;

    return 0;
}
