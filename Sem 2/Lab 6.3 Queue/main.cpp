#include <iostream>
#include "MyQueue.h"

using namespace std;

int min(int a, int b , int c) {
    if (a <= b and a <= c)
        return a;
    if (b < a and b <= c)
        return b;
    return c;
}

Queue<int> * task(int n) {
    Queue<int> q2(2), q3(3), q5(5);
    Queue<int> * res = new Queue<int>;
    for(int i = 0; i < n; i++) {
        int m = min(q2.front(), q3.front(), q5.front());
        res->push_back(m);
        q2.push_back(2*m);
        q3.push_back(3*m);
        q5.push_back(5*m);
        if (m == q2.front())
            q2.pop_front();
        if (m == q3.front())
            q3.pop_front();
        if (m == q5.front())
            q5.pop_front();
    }
    return res;
}

int main() {
    cout << "Enter n:\n";
    int n;
    cin >> n;
    Queue<int> * res = task(n);
    for (int i = 0; i < n; i++) {
        cout << res->pop_front() << " ";
    }
}
