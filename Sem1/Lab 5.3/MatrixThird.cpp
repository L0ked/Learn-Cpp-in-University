#include "MatrixThird.h"
#include <iostream>

#define DEBUG

using std::cout, std::cin, std::string;

MatrixThird::MatrixThird(int size) {
    this->size = size;
    this->len = size * 3 - 2;
    this->mass = new float[this->len];
}

MatrixThird::MatrixThird(const MatrixThird & mat) { // Конструктор копирования
    this->size = mat.size;
    this->len = mat.len;
    this->mass = new float[this->len];
    for (int i = 0; i < mat.len; i++) {
        this->mass[i] = mat.mass[i];
    }
}

MatrixThird::~MatrixThird() {
    delete[] this->mass;
}

void MatrixThird::input() {
#ifdef DEBUG
    for(int i = 0; i < this->len; i++) {
        this->mass[i] = rand() % 9 + 1;
    }
#else
    for(int i = 0; i < this->len; i++) {
        cin >> this->mass[i];
    }
#endif
}

void MatrixThird::input(int size) {
    delete[] this->mass;
    this->size = size;
    this->len = size * 3 - 2;
    this->mass = new float[this->len];
    input();
}

void MatrixThird::print() {
    if (this->mass != nullptr) {
        int count = 0;
        for (int i = 0; i < this->size; i++) {
            for(int j = 0; j < i - 1; j++) cout << "* ";
            cout << this->mass[count++] << " " << this->mass[count++] << " ";
            if (i != 0 && i != this->size - 1) cout << this->mass[count++] << " ";
            for(int j = 0; j < this->size - i - 2; j++) cout << "* ";
            cout << "\n";
        }
    } else {
        int count = 0;
        for (int i = 0; i < this->size; i++) {
            for(int j = 0; j < i - 1; j++) cout << "* ";
            cout << this->strmass[count++] << " " << this->strmass[count++] << " ";
            if (i != 0 && i != this->size - 1) cout << this->strmass[count++] << " ";
            for(int j = 0; j < this->size - i - 2; j++) cout << "* ";
            cout << "\n";
        }
    }
}

int MatrixThird::columns() {
    return this->size;
}

float MatrixThird::tr() {
    float s = 0;
    for(int i = 0; i < this->len; i += 3) {
        s += this->mass[i];
    }
    return s;
}

float MatrixThird::det() {
    // Определитель трёхдиагональной матрицы задается рекуррентной формулой fₙ = aₙ * fₙ₋₁ - cₙ₋₁ * bₙ₋₁ * fₙ₋₂
    float res = this->mass[0], res1 = 1, res2;
    for (int i = 1; i < this->len; i += 3) {
        res2 = res1;
        res1 = res;
        res = this->mass[i + 2] * res1 - this->mass[i] * this->mass[i + 1] * res2;
    }
    return res;
}

MatrixThird MatrixThird::operator+(MatrixThird & mat2) {
    MatrixThird mat(*this);
    for(int i = 0; i < mat.len; i++) {
        mat.mass[i] += mat2.mass[i];
    }
    return mat;
}

MatrixThird MatrixThird::operator-() {
    MatrixThird mat(*this);
    for (int i = 0; i < mat.len; i++) {
        mat.mass[i] *= -1;
    }
    return mat;
}

MatrixThird MatrixThird::operator-(MatrixThird & mat2) {
    MatrixThird mat(*this);
    for(int i = 0; i < mat.len; i++) {
        mat.mass[i] -= mat2.mass[i];
    }
    return mat;
}

MatrixThird MatrixThird::operator*(float value) {
    MatrixThird mat(*this);
    for(int i = 0; i < mat.len; i++) {
        mat.mass[i] *= value;
    }
    return mat;
}

MatrixThird MatrixThird::operator*(MatrixThird &mat2) { // поэлементное умножение двух матриц (только соответствующих элементов)
    MatrixThird mat(*this);
    for (int i = 0; i < this->len; i++) {
        mat.mass[i] *= mat2.mass[i];
    }
    return mat;
}

std::ostream & operator<<(std::ostream &os, const MatrixThird &mat) {
    string res;
    if (mat.mass != nullptr) {
        int count = 0;
        for (int i = 0; i < mat.size; i++) {
            for(int j = 0; j < i - 1; j++) res += "* ";
            res += std::to_string(mat.mass[count++]).substr(0,1) + " ";
            res += std::to_string(mat.mass[count++]).substr(0,1) + " ";
            if (i != 0 && i != mat.size - 1) res += std::to_string(mat.mass[count++]).substr(0,1) + " ";
            for(int j = 0; j < mat.size - i - 2; j++) res += "* ";
            res += "\n";
        }
    } else {
        int count = 0;
        for (int i = 0; i < mat.size; i++) {
            for(int j = 0; j < i - 1; j++) res += "* ";
            res += mat.strmass[count++] + " ";
            res += mat.strmass[count++] + " ";
            if (i != 0 && i != mat.size - 1) res += mat.strmass[count++] + " ";
            for(int j = 0; j < mat.size - i - 2; j++) res += "* ";
            res += "\n";
        }
    }
    return os << res;
}

std::istream & operator>>(std::istream &is, const MatrixThird &mat) {
    for(int i = 0; i < mat.len; i++) {
        is >> mat.mass[i];
    }
    return is;
}

void MatrixThird::operator+=(MatrixThird &mat2) {
    this->strmass = new string[this->len];
    for (int i = 0; i < this->len; i++) {
        this->strmass[i] = std::to_string(mass[i]).substr(0,1) + "+" + std::to_string(mat2.mass[i]).substr(0,1);
    }
    delete[] this->mass;
    this->mass = nullptr;
}

void MatrixThird::operator-=(MatrixThird &mat2) {
    this->strmass = new string[this->len];
    for (int i = 0; i < this->len; i++) {
        this->strmass[i] = std::to_string(mass[i]).substr(0,1) + "-" + std::to_string(mat2.mass[i]).substr(0,1);
    }
    delete[] this->mass;
    this->mass = nullptr;
}