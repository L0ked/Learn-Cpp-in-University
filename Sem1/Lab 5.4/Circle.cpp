#include "Circle.h"
#include <iostream>

Circle::Circle() {
    this->rad = 0;
    std::cout << "Construct Cir\n";
}

Circle::Circle(int x, int y, int rad) : Position(x, y) {
    this->rad = rad;
    std::cout << "Construct Cir\n";
}

void Circle::setrad(int rad) {
    this->rad = rad;
}

double Circle::perimeter() {
    return 2 * this->rad * 3.14;
}

double Circle::area() {
    return 3.14 * this->rad * this->rad;
}

void Circle::print() {
    std::cout << "x = " << this->x << " y = " << this->y << " rad = " << this->rad << "\n";
}

Circle::Circle(int rad) {

}

