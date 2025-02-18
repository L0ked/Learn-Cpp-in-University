#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
    int str;
    int col;
    double *mass = nullptr;
public:
    Matrix(int, int);
    ~Matrix();
    int get_columns();
    int get_rows();
    void input();
    void print();
    void mult_by_num(double);
    double trace();
    void mult(const Matrix *);
    void sum(const Matrix *);
    double det();
    double get_elem(int, int );

    // Lab 5.2
    Matrix(int, int, const double*);
    void sum(const double *);
    void mult(const double *);
    void input(int, int);
    void input(int, int, double *);

private:
    double determinant(Matrix&);
    Matrix getMinor(int, Matrix&);
};

#endif //MATRIX_H