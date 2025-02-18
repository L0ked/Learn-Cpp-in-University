#include "Matrix.h"
#include <iostream>

#define DEBUG

using std::cout, std::cin;


Matrix::Matrix(int str, int col) { // констуктор, str - количество строк, col - количество столбцов, элементы определяются 0;
    this->str = str;
    this->col = col;
    this->mass = new double[str * col] {};
}

Matrix::~Matrix() {
    delete[] this->mass;
}

int Matrix::get_columns() { // количество столбцов
    return this->col;
}

int Matrix::get_rows() { // количество строк
    return this->str;
}

void Matrix::input() { // ввести матрицу с клавиатуры
#ifdef DEBUG
    for (int i = 0; i < this->str * this->col; i++) {
        this->mass[i] = double(rand() % 10);
    }
#else
    for (int i = 0; i < str * col; i++) {
        cin >> mass[i];
    }
#endif
}

void Matrix::print() { // печать матрицы в консоль
    if (this->mass != nullptr) {
        for(int i = 0; i < this->str; i++) {
            for(int j = 0; j < this->col; j++) {
                cout << this->mass[i * this->col + j] << ' ';
            }
            cout << '\n';
        }
    } else {
        cout << "Massiv not input\n";
    }
}

void Matrix::mult_by_num(double num) { // умножение матрицы на число
    for(int i = 0; i < str * col; i++) {
        mass[i] *= num;
    }
}

double Matrix::trace() { // след матрицы (сумма диагональных элементов квадратной матрицы)
    double res = 0;
    for(int i = 0, j = 0; i * col + j < str * col; i++, j++) {
        res += mass[i * col + j];
    }
    return res;
}

void Matrix::mult(const Matrix * mat2) { // умножения двух матриц
    int resmas[str * col]{};
    for(int i = 0; i < str; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < str; k++) {
                resmas[i * col + j] += mass[i * col + k] * mat2->mass[k * str + j];
            }
        }
    }
    for (int i = 0; i < str * col; i++) {
        mass[i] = resmas[i];
    }
}

void Matrix::sum(const Matrix * mat2) { // сложения матриц
    for (int i = 0; i < str * col; i++) {
        mass[i] += mat2->mass[i];
    }
}

double Matrix::det() { // определитель матрицы (для квадратных)
    if (str != col) {
        cout << "Determinant can only be calculated for a square matrix.\n";
        return 0;
    }
    return determinant(*this);
}

double Matrix::get_elem(int i, int j) { // вернуть (i,j) элемент
    return mass[(i - 1) * col + j - 1];
}


// Lab 5.2
Matrix::Matrix(int i, int j, const double *arr) { // констуктор, i - количество строк, j - количество столбцов, элементы определяются массивом arr;
    this->str = i;
    this->col = j;
    this->mass = new double[str * col];
    for (int k = 0; k < str * col; k++) {
        mass[k] = arr[k];
    }
}

void Matrix::sum(const double *arr) { //  сложения матриц, результат записывается в текущую матрицу
    for (int i = 0; i < str * col; i++) {
        mass[i] += arr[i];
    }
}

void Matrix::mult(const double *arr) { // умножения двух матриц, результат возвращается или записывается в текущую матрицу
    int resmas[str * col]{};
    for(int i = 0; i < str; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < str; k++) {
                resmas[i * col + j] += (mass[i * col + k] * arr[k * str + j]);
            }
        }
    }
    for (int i = 0; i < str * col; i++) {
        mass[i] = resmas[i];
    }
}

void Matrix::input(int i, int j) { //  ввести матрицу с клавиатуры c заданными размерами, i - количество строк, j - количество столбцов
    this->str = i;
    this->col = j;
    input();
}

void Matrix::input(int i, int j, double *arr) { // инициализировать матрицу заданным массивом arr, i - количество строк, j - количество столбцов.
    this->str = i;
    this->col = j;
    delete[] this->mass;
    this->mass = new double[str * col];
    for (int k = 0; k < str * col; k++) {
        mass[k] = arr[k];
    }
}


//private
double Matrix::determinant(Matrix& matrix){ // рекурсивно бежим до матрицы 2 на 2, а потом считаем
    if (matrix.str == 1) return matrix.mass[0];
    if (matrix.str == 2) {
        return matrix.mass[0] * matrix.mass[3] - matrix.mass[1] * matrix.mass[2];
    }
    double det = 0;
    for (int colon = 0; colon < matrix.col; colon++) {
        Matrix minor = matrix.getMinor(colon, matrix);
        det += (colon % 2 == 0 ? 1 : -1) * matrix.mass[colon] * determinant(minor);
    }
    return det;
}

Matrix Matrix::getMinor(int colon, Matrix& matr) {
    Matrix minor(str - 1, col - 1);
    int minor_index = 0;
    for (int i = 1; i < str; i++) {
        for (int j = 0; j < col; j++) {
            if (j == colon) continue;
            minor.mass[minor_index++] = matr.mass[i * col + j];
        }
    }
    return minor;
}