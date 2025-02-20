#include <iostream>
#include "MyDeque.h"
#include <cmath>

using namespace std;


bool task1(string str) {
    if (str.empty())
        return false;
    MyDeque<char> deque;
    for (int i = 0; i < str.length(); i++) {
        deque.push_back(str[i]);
    }
    for (int i = 0; i < str.length() / 2; i++){
        if (deque.front() == deque.back()) {
            deque.pop_front();
            deque.pop_back();
        } else
            return false;
    }
    return true;
}

struct Point {
    int x, y;
};

void bubble(Point * mass, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (mass[j].x > mass[j + 1].x) {
                int x = mass[j].x, y = mass[j].y;
                mass[j].x = mass[j + 1].x;
                mass[j].y = mass[j + 1].y;
                mass[j + 1].x = x;
                mass[j + 1].y = y;
            }
            if (mass[j].x == mass[j + 1].x) {
                if (mass[j].y < mass[j + 1].y) {
                    int x = mass[j + 1].x, y = mass[j + 1].y;
                    mass[j + 1].x = mass[j].x;
                    mass[j + 1].y = mass[j].y;
                    mass[j].x = x;
                    mass[j].y = y;
                }
            }
        }
    }
}

double corner(Point p0, Point p1, Point p2) {
    double x1 = p1.x - p0.x, y1 = p1.y - p0.y;
    double x2 = p2.x - p1.x, y2 = p2.y - p1.y;
    return (x1 * x2 + y1 * y2)/(sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2));
}

double vectproizv(Point p0, Point p1, Point p2) {
    double x1 = p1.x - p0.x, y1 = p1.y - p0.y;
    double x2 = p2.x - p0.x, y2 = p2.y - p0.y;
    return x1 * y2 - x2 * y1;
}

MyDeque<Point> task2(Point * mass, int len) {
    MyDeque<Point> res;
    res.push_front(mass[0]);
    Point p0, p1, p2;
    p0 = mass[0];
    p1 = mass[1];
    int r = 1;
    for (int i = 2; i < len; i++) {
        p2 = mass[i];
        if (vectproizv(p0, p1, p2) < 0) {
            p1 = p2;
            r = i;
        }
    }
    res.push_back(p1);

    for (int k = 0; k < len; k++){
        double m = -2;
        for (int i = 0; i < len; i++) {
            p2 = mass[i];
            double a = corner(p0, p1, p2);
            if (a > m) {
                r = i;
                m = a;
            }
        }
        Point a = res.front();
        if (mass[r].x == a.x and mass[r].y == a.y)
            break;
        res.push_back(mass[r]);
        p0 = p1;
        p1 = mass[r];
    }
    return res;
}


int main() {
    // string a;
    // getline(cin, a);
    // cout << task1(a);

    cout << "Enter len:\n";
    int len;
    cin >> len;
    Point mass[len];
    cout << "Enter points:\n";
    for (int i = 0; i < len; i++) {
        cin >> mass[i].x >> mass[i].y;
    }
    bubble(mass, len);
    MyDeque<Point> deque = task2(mass, len);
    len = deque.get_size();
    for (int i = 0; i < len; i++) {
        Point a = deque.pop_front();
        cout << a.x << ' ' << a.y << '\n';
    }
}
