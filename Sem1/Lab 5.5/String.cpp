#include "String.h"
#include <iostream>

using std::cout;

String::String() {
    this->str = new char[] {""};
    this->bitlen = 0;
}

String::String(char * chars) {
    this->bitlen = 0;
    while (chars[this->bitlen] != '\0') {
        this->bitlen++;
    }
    this->str = new char[this->bitlen + 1]{};
    for (int i = 0; i < this->bitlen; i++) {
        this->str[i] = chars[i];
    }
}

String::String(char chars) {
    this->str = new char[2]{};
    this->str[0] = chars;
    this->bitlen = 1;
}

String::String(const String & str2) {
    kol += 1;
    this->bitlen = str2.bitlen;
    this->str = new char[str2.bitlen + 1]{};
    for (int i = 0; i < str2.bitlen; i++) {
        this->str[i] = str2.str[i];
    }
}

String::~String() {
    delete[] this->str;
}

int String::getlen() {
    return this->bitlen;
}

void String::clear() {
    delete[] this->str;
    this->str = new char[]{""};
}

void String::print() {
    cout << this->str << '\n';
}

int String::getkol() {
    return kol;
}