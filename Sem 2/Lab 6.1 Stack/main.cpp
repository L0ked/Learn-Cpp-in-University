#include <iostream>
#include "MyStack.h"
#include "MyStack.cpp"

using namespace std;

bool res(string str) {
    MyStack<char> stack;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stack.push(str[i]);
        }

        if (str[i] == ')') {
            if (stack.top() == '(')
                stack.pop();
            else
                return false;
        }
        if (str[i] == ']') {
            if (stack.top() == '[')
                stack.pop();
            else
                return false;
        }
        if (str[i] == '}') {
            if (stack.top() == '{')
                stack.pop();
            else
                return false;
        }
    }
    return stack.empty();
}

int main() {
    while (true) {
        string str;
        cin >> str;
        if (res(str))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
