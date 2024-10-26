#include <iostream>

using std::cin, std::cout;

void printArr(auto *arr, int l) {
    for(int i = 0; i < l; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void inputArr(int *&arr, int &size) {
    cout << "Enter len arr:\n";
    cin >> size;
    if (arr != nullptr) delete[] arr;
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int len_int(int n) {
    int r = 0;
    while (n) {
        r++;
        n /= 10;
    }
    return r;
}

void sortSum(int*arr, int l){
    int sarr[l] = {};
    for (int i = 0; i < l; i++) {
        int a = arr[i], s = 0;
        if (len_int(a) % 2 == 1) {
             a /= 10;
        }
        while (a) {
            s += a % 10;
            a /= 100;
        }
        sarr[i] = s;
    } // Нахождение суммы чисел стоящих на чётных местах

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l - i - 1; j++) {
            if (sarr[j] > sarr[j + 1]) {
                int a = arr[j], b = sarr[j];
                arr[j] = arr[j + 1];
                sarr[j] = sarr[j + 1];
                arr[j + 1] = a;
                sarr[j + 1] = b;
            }
        }
    } // Пузырьковая сортировка по найденной сумме
    printArr(arr,l);
}

void sortLast(int *arr, int l) {
    int max[10] = {};
    for (int i = 0; i < l; i++) {
        int a = arr[i];
        max[a % 10] += 1;
    }// находим сколько чисел имеют одинаковые последние цифры

    int res[l] = {}; //массив для результата

    for (int n = 0; n < 10; n++) { // последние цифры чисел
        int sor[max[n]] = {}, k = 0;
        for (int j = 0; j < l; j++) {
            int a = arr[j];
            if (a % 10 == n) {
                sor[k++] = a;
            }
        } // массив sor содержит только числа с одинаковой последней цифрой

        for (int i = 0; i < max[n]; i++) {
            for (int j = 0; j < max[n] - i - 1; j++) {
                if (sor[j] < sor[j + 1]) {
                    int a = sor[j];
                    sor[j] = sor[j + 1];
                    sor[j + 1] = a;
                }
            }
        } // пузырьково сортируем эти числа в обратном порядке

        int s = 0; // индекс с учётом уже добавленных чисел
        for (int i = 0; i < n; i++) {
            s += max[i];
        } // собираем этот индекс

        for (int i = 0; i < max[n]; i++) {
            res[i+s] = sor[i];
        } // в res добавляем уже отсортированные числа
    }
    printArr(res,l);
}


int main() {
    int m = 0;
    while (m != 5) {
        cout << "Menu:\n1. Enter arr\n2. Print arr\n3. Sort sum\n4. Sort last\n5. Quit\n";
        cin >> m;
        switch (m) {
            case 1:
                cout << "1. Enter arr\n";
            case 2: {
                if (m == 2) {
                    cout << "2. Print arr\n";
                }
                int l;
                int* arr = nullptr;
                inputArr(arr,l);
                printArr(arr, l);
                delete[] arr;
                break;
            }
            case 3: {
                cout << "3. Sort sum\n";
                int l;
                int* arr = nullptr;
                inputArr(arr,l);
                sortSum(arr, l);
                delete[] arr;
                break;
            }
            case 4: {
                cout << "4. Sort last\n";
                int l;
                int* arr = nullptr;
                inputArr(arr,l);
                sortLast(arr, l);
                delete[] arr;
            }
            default:
                break;
        }
    }
}