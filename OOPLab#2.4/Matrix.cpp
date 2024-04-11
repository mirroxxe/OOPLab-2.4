#include "Matrix.h"
#include "string"

Matrix::Matrix() : size(0), count(0) {}

Matrix::Matrix(int size) : size(size), count(size) {
    Init();
}

void Matrix::setSize(int size) {
    this->size = size;
}

int Matrix::getSize() const {
    return size;
}

int Matrix::getCount() const {
    return count;
}

void Matrix::setElement(int row, int col, int value) {
    if (row < size && col < size) {
        data[row][col] = value;
    }
}

int Matrix::getElement(int row, int col) const {
    return data[row][col];
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

double Matrix::norm() const {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            sum += data[i][j] * data[i][j];
        }
    }
    return std::sqrt(sum);
}

void Matrix::Read() {
    std::cout << "Enter matrix elements:" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cin >> data[i][j];
        }
    }
}

void Matrix::Display() const {
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

std::string Matrix::ToString() const {
    std::string result = "Matrix:\n";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result += std::to_string(data[i][j]) + "\t";
        }
        result += "\n";
    }
    return result;
}

void Matrix::Init() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& other) : size(other.size), count(other.count) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

int* Matrix::operator[](int index) {
    if (index >= 0 && index < size) {
        return data[index];
    }
    else {
        return nullptr;
    }
}