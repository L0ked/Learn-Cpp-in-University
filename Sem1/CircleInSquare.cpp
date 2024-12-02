#include "CircleInSquare.h"
#include "Circle.h"
#include "Square.h"
#include "Position.h"
#include <iostream>

CircleInSquare::CircleInSquare() {}

CircleInSquare::CircleInSquare(int x, int y, int len, int rad) : Square(x, y, len), Circle(x, y, rad), Position(x, y) {}

void CircleInSquare::print() {
    std::cout << "x = " << this->x << " y = " << this->y << " len = " << this->len << " rad = " << this->rad << "\n";
}


