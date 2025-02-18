#include <iostream>

#include "BiteString.h"
#include "String.h"

using std::cout, std::cin;

int main() {
    String* mass[5] = { nullptr };
    int m = 0;
    while (m != 4) {
        cout << "Menu:\n1. Enter String\n2. Print String\n3. Metods\n4. Quit\n";
        cin >> m;
        switch (m) {
            case 1: {
                cout << "Enter Number String:\n";
                int i;
                cin >> i;
                cout << "Enter BiteString:\n";
                char str[255]{};
                cin.ignore(); // обнуляет учёт энтеров
                cin.getline(str, 255);
                if (mass[i] != nullptr) delete mass[i];
                mass[i] = new BiteString(str);
                break;
            }
            case 2: {
                cout << "Enter Number String:\n";
                int i;
                cin >> i;
                mass[i]->print();
                break;
            }
            case 3: {
                cout << "Enter Number String 1:\n";
                int i1;
                cin >> i1;
                cout << "Enter Number String 2:\n";
                int i2;
                cin >> i2;

                auto* obj1 = dynamic_cast<BiteString*>(mass[i1]);
                auto* obj2 = dynamic_cast<BiteString*>(mass[i2]);

                BiteString sum = *obj1 + *obj2;
                std::cout << "Sum: \n";
                sum.print();

                bool isEqual = ((*obj1) == (*obj2));
                std::cout << "Equal: " << (isEqual ? "Yes" : "No") << "\n";

                obj1->change_sign();
                std::cout << "Change sign: \n";
                obj1->print();

                std::cout << "Kol Copy: \n" << obj1->getkol() << '\n';
                break;
            }
        }
    }
}
