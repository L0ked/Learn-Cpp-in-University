#include <iostream>

using std::cin, std::cout;

void func1(int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << j;
        }
        cout << '\n';
    }
}

void func2(double n) {
    double c = 1;
    for (double k = 0; k <= n; k++) {
        cout << c << " ";
        c *= (n - k)/(k + 1);
    }
    cout << "\n";
}

void func3() {
    int sum = 0, n;
    float k = 0;
    cin >> n;
    while (n != 0) {
        k++;
        sum += n;
        cin >> n;
    }
    cout << sum / k << std::endl;
}

int main() {
    int m = 0;
    while (m != 4) {
        cout << "Menu:\n1. Triangle\n2. Binom\n3. Sum\n4. Quit\n";
        cin >> m;
        switch (m) {
            case 1:
                cout << "1. Triangle\n";
                int n1;
                cin >> n1;
                func1(n1);
                break;
            case 2:
                cout << "2. Binom\n";
                double n2;
                cin >> n2;
                func2(n2);
                break;
            case 3:
                cout << "3.\nEnter number: (0 - end)\n";
                func3();
                break;
            default:
                break;
        }
    }
}
