#include "Square.h"
#include "Position.h"
#include <iostream>

Square::Square() {
    this->len = 0;
    std::cout << "Construct Square\n";
}

Square::Square(int x, int y, int len) : Position(x, y) {
    this->len = len;
    std::cout << "Construct Square\n";
}

void Square::setlen(int len) {
    this->len = len;
}

double Square::perimeter() {
    return this->len * 4;
}

double Square::area() {
    return this->len * this->len;
}

void Square::print() {
    std::cout << "x = " << this->x << " y = " << this->y << " len = " << this->len << "\n";
}
