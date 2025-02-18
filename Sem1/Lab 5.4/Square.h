#ifndef SQUARE_H
#define SQUARE_H
#include "Position.h"

class Square : public virtual Position {
protected:
    int len;
public:
    Square();
    Square(int x, int y, int len);

    void setlen(int len);
    double perimeter();
    double area();
    void print() override;
};

#endif //SQUARE_H
