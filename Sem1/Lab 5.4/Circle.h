#ifndef CIRCLE_H
#define CIRCLE_H
#include "Position.h"

class Circle : public virtual Position {
protected:
    int rad;
public:
    Circle();
    Circle(int x, int y, int rad);

    void setrad(int rad);
    double perimeter();
    double area();
    void print() override;

protected:
    Circle(int rad);
};

#endif //CIRCLE_H
