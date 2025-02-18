#include "Position.h"
#include <iostream>

Position::Position() {
    this->x = 0;
    this->y = 0;
    std::cout << "Construct Pos\n";
}

Position::Position(int x, int y) {
    this->x = x;
    this->y = y;
    std::cout << "Construct Pos\n";
}

void Position::move(int x, int y) {
    this->x = x;
    this->y = y;
}

void Position::print() {
    std::cout << "x = " << this->x << " y = " << this->y << "\n";
}
