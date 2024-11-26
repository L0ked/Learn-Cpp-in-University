#include <iostream>
#include "Matrix.h"

using std::cout, std::cin;

int main() {
    Matrix mat1(2, 2); // констуктор, i - количество строк, j - количество столбцов, элементы определяются 0;
    mat1.print();

    double * arr = new double[9]{};
    for (int i = 0; i < 9; i++) {
        arr[i] = rand() % 10;
    }

    cout << "Constructor arr:\n";
    Matrix mat(3, 3, arr);// констуктор, i - количество строк, j - количество столбцов, элементы определяются массивом arr;
    mat.print();

    cout << "Sum arr:\n";
    mat.sum(arr); //  сложения матриц, результат возвращается или записывается в текущую матрицу соответственно;
    mat.print();

    cout << "Mult arr:\n";
    mat.mult(arr); // умножения двух матриц, результат возвращается или записывается в текущую матрицу
    mat.print();

    cout << "Input size:\n";
    mat.input(2, 2); //  ввести матрицу с клавиатуры c заданными размерами, i - количество строк, j - количество столбцов
    mat.print();

    cout << "Input arr:\n";
    mat.input(3, 3, arr); // инициализировать матрицу заданным массивом arr, i - количество строк, j - количество столбцов.
    mat.print();
}