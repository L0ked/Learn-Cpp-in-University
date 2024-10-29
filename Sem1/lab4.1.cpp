#include <iostream>
#include <string.h>

using std::cin, std::cout;

char down(char a) {
    if (a >= 'A' && a <= 'Z') {
        a += 'a' - 'A';
    }
    return a;
}

bool Palindrom(char* str) {
    bool res = true;
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i] == ' ') i++;
        if (str[j] == ' ') j--;
        if (down(str[i]) != down(str[j])) {
            res = false;
            break;
        }
    }
    return res;
}
// поиск подстроки в строке
// возвращает индекс первого слева вхождения подстроки substring в строку str_for_search_in
// поиск ведется с позиции start_position
int find_substring1(const char * str_for_search_in, const char * substring, int start_position) {
    for (int i = start_position; i < strlen(str_for_search_in); i++) {
        bool flag = true;
        for (int j = 0; j < strlen(substring); j++) {
            if (substring[j] != str_for_search_in[j + i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}
// поиск подстроки в строке
// возвращает массив всех позиций вхождения подстроки в строку
int* find_substring2(const char * str_for_search_in, const char * substring) {
    int l = 0;
    int flag = find_substring1(str_for_search_in, substring, 0);
    static int res[100];
    while (flag != -1) {
        res[l] = flag;
        l++;
        flag = find_substring1(str_for_search_in, substring, flag + 1);
    }
    res[l] = -1;
    return res;
}
// шифрование сдвигами (шифр Цезаря)
void encrypt(char* str_for_encrypt, int key) {
    for (int i = 0; i < strlen(str_for_encrypt); i++) {
        if (str_for_encrypt[i] != ' ') {
            str_for_encrypt[i] += key;
        }
    }
}
// Вывести все названия (то, что внутри кавычек) из текста. Названия могут содержать пробелы.
void nameprint(char* str) {
    bool flag = false;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '<' || str[i] == '\"' || str[i] == '>') {
            flag = !flag;
            if (!flag) cout << " | ";
        } else {
            if (flag) cout << str[i];
        }
    }
    cout << "\n";
}

int main() {
    int m = 0;
    while (m != 5) {
        cout << "Menu:\n1. Polindrom\n2. Find Substring\n3. Encrypt\n4. Name\n5. Quit\n";
        cin >> m;
        switch (m) {
            case 1: {
                cout << "1. Polindrom\n";
                char str[255];
                cin.ignore(); // обнуляет учёт энтеров
                cin.getline(str, 255);
                if (Palindrom(str)) {
                    cout << "Polindrom\n";
                } else {
                    cout << "No polindrom\n";
                };
                break;
            }
            case 2: {
                cout << "2. Find Substring\nstr_for_search_in =\n";
                char str_search[255];
                cin.ignore();
                cin.getline(str_search, 255);
                cout << "substring =\n";
                char str_sub[255];
                cin.getline(str_sub, 255);
                int* res = find_substring2(str_search, str_sub);
                for (int i = 0; i < 100; i++) {
                    if (res[i] == -1) {
                        break;
                    }
                    cout << res[i]<< " ";
                }
                cout << "\n";
                break;
            }
            case 3: {
                cout << "3. Encrypt\n";
                char str[255];
                cin.ignore();
                cin.getline(str, 255);
                int key;
                cin >> key;
                encrypt(str, key);
                printf(str);
                cout << "\n";
                break;
            }
            case 4: {
                cout << "4. Name\n";
                char str[255];
                cin.ignore();
                cin.getline(str, 255);
                nameprint(str);
                break;
            }
            default:
                break;
        }
    }
}