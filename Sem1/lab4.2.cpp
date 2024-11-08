#include <fstream>
#include <iostream>
#include <string>
using std::cout, std::cin, std::string;

// переворот строк
string revers(string a) {
    string r;
    for (int i = a.length()-1; i >= 0; i--) {
        r += a[i];
    }
    return r;
}

// по введенному полному расположению файла получить расширение
string file_format(const string file_path_full) {
    string res;
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] != '.') {
            res += file_path_full[i];
        } else {
            break;
        }
    }
    return revers(res);
}


// по введенному полному расположению файла получить название,
string file_name(const string file_path_full) {
    string res;
    bool flag = false;
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (flag) {
            if (file_path_full[i] != '\\') {
                res += file_path_full[i];
            }else break;
        }else {
            if (file_path_full[i] == '.') flag = true;
        }
    }
    return revers(res);
}

// по введенному полному расположению файла получить расположение,
string file_path(const string file_path_full) {
    for(int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] == '\\') {
            return file_path_full.substr(0, i); // получает подстроку. Первый параметр представляет индекс,
            // с которого начинается подстрока. Второй параметр - количество символов извлекаемой подстроки.
        }
    }
    return "0";
}

// по введенному полному расположению файла получить название диска,
char file_disk (const string file_path_full) {
    return file_path_full[0];
}

// по введенному полному расположению файла и новому имени  переименовать файл,
bool file_rename(string *file_path_full) {
    cout << "Enter new name:\n";
    string name, format = file_format(*file_path_full);
    cin >> name;
    for (int i = (*file_path_full).length() - 1; i >= 0; i--) {
        if ((*file_path_full)[i] == '\\') {
            (*file_path_full) = (*file_path_full).substr(0,i + 1) + name + '.' + format;
            return true;
        }
    }
    return false;
}

// по введенному полному расположению файла создать копию файла
bool file_copy(const string file_path_full) {
    std::ifstream fs(file_path_full);
    std::ofstream fs_copy;
    if (! fs) return false;
    string name, line;
    for (int i = file_path_full.length() - 1; i >= 0; i--) {
        if (file_path_full[i] == '.') {
            name = file_path_full.substr(0, i) + "_copy" + file_path_full.substr(i);
        }
    }
    fs_copy.open(name, std::fstream::out | std::fstream::trunc);
    while (std::getline(fs, line)) {
        fs_copy << line << std::endl;
    }
    fs.close();
    fs_copy.close();
    return true;
}


int main() {
    int m = 0;
    while (m != 7) {
        cout << "Menu:\n1. File Format\n2. Find Substring\n3. File Path\n4. File Disk\n5. File Rename\n6. File Copy\n7. Quit\n";
        cin >> m;
        switch (m) {
            case 1: {
                cout << "1. File Format\n";
                string a;
                cin >> a;
                cout << file_format(a) << '\n';
                break;
            }
            case 2: {
                cout << "2. File Line\n";
                string a;
                cin >> a;
                cout << file_name(a) << '\n';
                break;
            }
            case 3: {
                cout << "3. File Path\n";
                string a;
                cin >> a;
                cout << file_path(a) << '\n';
                break;
            }
            case 4: {
                cout << "4. File Disk\n";
                string a;
                cin >> a;
                cout << file_disk(a) << '\n';
                break;
            }
            case 5: {
                cout << "5. File Rename. Input path\n";
                string a;
                cin >> a;
                if (file_rename(&a)) cout << a << '\n';
                else cout << "Error";
                break;
            }
            case 6: {
                cout << "6. File Copy\n";
                string a;
                cin >> a;
                if (file_copy(a)) cout << "Complete\n";
                else cout << "Error\n";
                break;
            }
            default:
                break;
        }
    }
}