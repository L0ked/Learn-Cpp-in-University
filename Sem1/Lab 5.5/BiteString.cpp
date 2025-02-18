#include "BiteString.h"
#include <iostream>

using std::cout;

BiteString::BiteString(){}

BiteString::BiteString(char * chars): String(chars) {
    if (this->bitlen > 8) {
        delete[] this->str;
        this->str = new char[]{"0"};
        this->bitlen = 1;
    }
    for(int l = 0; chars[l] != '\0'; l++) {
        if (!(chars[l] == '0' or chars[l] == '1')){
            delete[] this->str;
            this->str = new char[]{"0"};
            this->bitlen = 1;
            break;
        }
    }
    // cout << this->str;
}

BiteString::BiteString(const BiteString &str2): String(str2) {
    kol += 1;
}

void BiteString::change_sign() {
    if (this->bitlen < 8) { // слева дописываем нули
        char s[9]{};
        for(int i = 0; i < 8; i++) {
            if (i < 8 - this->bitlen) {
                s[i] = '0';
            } else {
                s[i] = this->str[i - 8 + this->bitlen];
            }
        }

        delete[] this->str;
        this->str = new char[9]{};
        this->bitlen = 8;
        for (int i = 0; i < 8; i++) {
            this->str[i] = s[i];
        }
    }

    for (int i = 0; i < 8; i++) {
        if (this->str[i] == '0') this->str[i] = '1';
        else this->str[i] = '0';
    }
}

BiteString& BiteString::operator=(const BiteString & b2) {
    this->bitlen = b2.bitlen;
    delete[] this->str;
    this->str = new char[b2.bitlen + 1]{};
    for (int i = 0; i < b2.bitlen; i++) {
        this->str[i] = b2.str[i];
    }
    return *this;
}

BiteString BiteString::operator+(const BiteString & b2) {
    BiteString b(*this), b1(b2);
    int len = b.bitlen;
    if (b.bitlen != b1.bitlen) {
        if (b.bitlen > b1.bitlen) {
            delete[] b1.str;
            b1.str = new char[len + 1]{};
            for(int i = 0; i < len; i++) {
                if (i < len - b1.bitlen) b1.str[i] = '0';
                else b1.str[i] = b2.str[i - len + b2.bitlen];
            }
        }
        else {
            len = b1.bitlen;
            char s[len + 1]{};
            for(int i = 0; i < len; i++) {
                if (i < len - b.bitlen) {
                    s[i] = '0';
                } else {
                    s[i] = b.str[i - len + b.bitlen];
                }
            }
            delete[] b.str;
            b.str = new char[len + 1]{};
            for (int i = 0; i < len; i++) {
                b.str[i] = s[i];
            }
        }
    }

    char res[len + 1]{};
    int carry = 0;
    for(int i = len - 1; i >= 0; i--) {
        int bit1 = b.str[i] - '0'; // Преобразуем символ в число
        int bit2 = b1.str[i] - '0';
        int sum = bit1 + bit2 + carry;
        res[i] = char(sum % 2 + '0');
        carry = sum / 2;
    }

    if (carry) len += 1;

    delete[] b.str;
    b.str = new char[len + 1]{};

    int i = 0;
    if (carry) {
        b.str[i++] = '1';
    }

    for (; i < len; i++) {
        b.str[i] = res[i - carry];
    }
    return b;
}

bool BiteString::operator==(const BiteString & b2) {
    if (this->bitlen != b2.bitlen) return false;
    for (int i = 0; i < this->bitlen; i++) {
        if (this->str[i] != b2.str[i]) return false;
    }
    return true;
}

int BiteString::getkol() {
    return kol;
}