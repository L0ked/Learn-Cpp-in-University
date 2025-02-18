#ifndef CIRCLEINSQUARE_H
#define CIRCLEINSQUARE_H
#include "Circle.h"
#include "Square.h"

class CircleInSquare : public Square,  public Circle {
public:
    CircleInSquare();
    CircleInSquare(int x, int y, int len, int rad);

    void print() override;
};

#endif //CIRCLEINSQUARE_H
