#include "Matrix.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

//Виділення та звільнення пам'яті
void Matrix::allocateMemory(int r, int c) {
    R = r;
    C = c;
    m = new int* [R];
    for (int i = 0; i < R; i++) {
        m[i] = new int[C] {0}; // нулі
    }
}

void Matrix::freeMemory() {
    if (m != nullptr) {
        for (int i = 0; i < R; i++) {
            delete[] m[i];
        }
        delete[] m;
        m = nullptr;
    }
}

Matrix::Matrix() {
    allocateMemory(2, 2); // Розмір за замовчуванням 2x2
}

Matrix::Matrix(int r, int c) {
    // Контроль значень
    if (r <= 0 || c <= 0) throw std::invalid_argument("Invalid dimensions!");
    allocateMemory(r, c);
}

Matrix::Matrix(const Matrix& other) : Object(other) {
    allocateMemory(other.R, other.C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            m[i][j] = other.m[i][j];
        }
    }
}

Matrix::~Matrix() {
    freeMemory();
}

int Matrix::getRows() const { return R; }
int Matrix::getCols() const { return C; }

int Matrix::getElement(int r, int c) const {
    if (r < 0 || r >= R || c < 0 || c >= C)
        throw std::out_of_range("Index out of bounds!");
    return m[r][c];
}

void Matrix::setElement(int r, int c, int value) {
    // Перевірка на коректність
    if (r < 0 || r >= R || c < 0 || c >= C) {
        std::cerr << "Error: Index out of bounds. Cannot set value.\n";
        return;
    }
    m[r][c] = value;
}

void Matrix::Init(int r, int c) {
    freeMemory();
    allocateMemory(r, c);
}

void Matrix::Read() {
    std::cout << "Enter " << R * C << " elements for the " << R << "x" << C << " matrix:\n";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            std::cin >> m[i][j];
        }
    }
}

void Matrix::Display() const {
    std::cout << toString();
}

std::string Matrix::toString() const {
    std::stringstream ss;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            ss << std::setw(5) << m[i][j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}

Matrix::operator std::string() const {
    return toString();
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    freeMemory();
    allocateMemory(other.R, other.C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            m[i][j] = other.m[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator++() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            m[i][j]++;
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp(*this);
    ++(*this);
    return temp;
}

Matrix& Matrix::operator--() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            m[i][j]--;
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix temp(*this);
    --(*this);
    return temp;
}

Matrix operator+(const Matrix& a, const Matrix& b) {
    if (a.R != b.R || a.C != b.C) throw std::invalid_argument("Dimension mismatch for addition!");
    Matrix result(a.R, a.C);
    for (int i = 0; i < a.R; i++)
        for (int j = 0; j < a.C; j++)
            result.m[i][j] = a.m[i][j] + b.m[i][j];
    return result;
}

Matrix operator-(const Matrix& a, const Matrix& b) {
    if (a.R != b.R || a.C != b.C) throw std::invalid_argument("Dimension mismatch for subtraction!");
    Matrix result(a.R, a.C);
    for (int i = 0; i < a.R; i++)
        for (int j = 0; j < a.C; j++)
            result.m[i][j] = a.m[i][j] - b.m[i][j];
    return result;
}

Matrix operator*(const Matrix& a, const Matrix& b) {
    if (a.C != b.R) throw std::invalid_argument("Dimension mismatch for multiplication!");
    Matrix result(a.R, b.C);
    for (int i = 0; i < a.R; i++) {
        for (int j = 0; j < b.C; j++) {
            for (int k = 0; k < a.C; k++) {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return result;
}

Matrix operator*(const Matrix& a, int scalar) {
    Matrix result(a.R, a.C);
    for (int i = 0; i < a.R; i++)
        for (int j = 0; j < a.C; j++)
            result.m[i][j] = a.m[i][j] * scalar;
    return result;
}

Matrix operator*(int scalar, const Matrix& a) {
    return a * scalar; // Комутативність множення на скаляр
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << matrix.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& matrix) {
    std::cout << "Enter elements for " << matrix.R << "x" << matrix.C << " matrix:\n";
    for (int i = 0; i < matrix.R; i++) {
        for (int j = 0; j < matrix.C; j++) {
            is >> matrix.m[i][j];
        }
    }
    return is;
}