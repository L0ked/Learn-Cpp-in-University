#include <iostream>
#include "Matrix.h"

using std::cout, std::cin;

int main() {
    Matrix mat1(3,3);
    mat1.input(); // ввести матрицу с клавиатуры
    mat1.print(); // печать матрицы в консоль
    cout << mat1.get_columns() << "\n\n"; // количество столбцов
    cout << mat1.get_rows() << "\n\n"; // количество строк
    cout << mat1.get_elem(2,2) << "\n\n"; // вернуть (i,j) элемент

    cout << "Mult matrix by num 5:\n";
    mat1.mult_by_num(5); // умножение матрицы на число
    mat1.print();
    cout << mat1.trace() << '\n'; // след матрицы (сумма диагональных элементов квадратной матрицы)

    cout << "Second matrix:\n";
    Matrix mat2(3, 3);
    mat2.input();
    mat2.print();

    cout << "Sum matrix:\n";
    mat1.sum(&mat2); // сложения матриц
    mat1.print();

    cout << "Mult matrix:\n";
    mat1.mult(&mat2); // умножения двух матриц
    mat1.print();

    cout << "Det matrix 5x5:\n";
    Matrix mat3(5,5);
    mat3.input();
    mat3.print();
    cout << mat3.det(); // определитель матрицы (для квадратных)
}