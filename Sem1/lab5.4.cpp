#include <iostream>
#include "Position.h"
#include "Square.h"
#include "Circle.h"
#include "CircleInSquare.h"


using std::cout, std::cin;

int main() {
    Position p1;
    p1.print();
    p1.move(2,3);
    p1.print();

    cout << "\n";
    Position p2(5, 6);
    p2.print();

    cout << "\n";
    Circle c1;
    c1.print();
    c1.move(1, 2);
    c1.setrad(5);
    c1.print();

    cout << "\n";
    Circle c2(3, 2, 10);
    c2.print();
    cout <<"Area = " << c2.area();
    cout <<"\nPerim = " << c2.perimeter();

    cout << "\n\n";
    Square s1;
    s1.print();
    s1.move(4, 1);
    s1.setlen(3);
    s1.print();

    cout << "\n";
    Square s2(9, 8, 4);
    s2.print();
    cout <<"Area = " << s2.area();
    cout <<"\nPerim = " << s2.perimeter();

    cout << "\n\n";
    CircleInSquare b;
    b.print();
    b.move(1, 1);
    b.setlen(4);
    b.setrad(2);
    b.print();

    cout << "\n";
    CircleInSquare a(-1, -1, 6, 3);
    a.print();
    cout <<"Area Circle = " << a.Circle::area();
    cout <<"\nPerim Circle = " << a.Circle::perimeter();
    cout <<"\nArea Square = " << a.Square::area();
    cout <<"\nPerim Square = " << a.Square::perimeter();
}