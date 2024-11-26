#include <iostream>
#include "MatrixThird.h"

using std::cout, std::cin;

int main() {
    // храним а1 b1 c1 a2 b2 c2 и до an
    // где а это основная диагональ, b выше диагональ, с ниже

    MatrixThird mat1(6);
    mat1.input();
    mat1.print();

    cout << "COL: " << mat1.columns() << "\n";
    cout << "TR: " << mat1.tr() << "\n";
    cout << "DET: " << mat1.det() << "\n\n";
    // Определитель трёхдиагональной матрицы задается
    // рекуррентной формулой fₙ = aₙ * fₙ₋₁ - cₙ₋₁ * bₙ₋₁ * fₙ₋₂

    mat1.input(3);
    mat1.print();

    cin >> mat1;
    cout <<"Mat1:\n" << mat1;

    cout << "Mat2:\n";
    MatrixThird mat2(3);
    mat2.input();
    mat2.print();

    cout << "\nSum:\n";
    (mat1 + mat2).print();

    cout << "\nDiff bin:\n";
    (mat1 - mat2).print();

    cout << "\nDiff unar\n";
    (-mat2).print();

    cout << "\nMult num\n";
    (mat2 * 3).print();

    cout << "\nMult mat\n";
    (mat1 * mat2).print();


    MatrixThird mat(mat1);
    cout << "\n+=\n";
    mat1 += mat2;
    mat1.print();

    cout << "\n-=\n";
    mat -= mat2;
    mat.print();

}