#include <iostream>
#include <cmath>

class Matrix {
private:
    static const int MAX_SIZE = 10;
    int size;
    int count;
    int data[MAX_SIZE][MAX_SIZE];

public:
    Matrix();
    Matrix(int size);
    Matrix(const Matrix& other);

    void setSize(int size);
    int getSize() const;
    int getCount() const;

    void setElement(int row, int col, int value);
    int getElement(int row, int col) const;

    Matrix operator-(const Matrix& other) const;
    bool operator==(const Matrix& other) const;

    double norm() const;

    void Read();
    void Display() const;
    std::string ToString() const;
    void Init();

    int* operator[](int index);
};