#ifndef POSITION_H
#define POSITION_H

class Position {
protected:
    int x, y;
public:
    Position();
    Position(int x, int y);

    void move(int x, int y);
    virtual void print();
};

#endif //POSITION_H
