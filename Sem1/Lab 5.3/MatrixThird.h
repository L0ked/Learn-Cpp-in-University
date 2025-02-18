#ifndef MATRIXTHIRD_H
#define MATRIXTHIRD_H

#include <string>

class MatrixThird {
    float* mass = nullptr;
    int size;
    int len;
    std::string * strmass = nullptr;
public:
    MatrixThird(int);
    MatrixThird(const MatrixThird&);
    ~MatrixThird();
    void input();
    void input(int);
    void print();
    int columns();
    float tr();
    float det();
    MatrixThird operator+(MatrixThird&);
    MatrixThird operator-();
    MatrixThird operator-(MatrixThird&);
    MatrixThird operator*(float);
    MatrixThird operator*(MatrixThird&); // поэлементное умножение двух матриц (только соответствующих элементов)
    friend std::ostream& operator<<(std::ostream&, const MatrixThird &);
    friend std::istream& operator>>(std::istream&, const MatrixThird &);
    void operator+=(MatrixThird&);
    void operator-=(MatrixThird&);
};

#endif //MATRIXTHIRD_H
