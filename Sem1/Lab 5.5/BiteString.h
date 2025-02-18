#ifndef BITESTRING_H
#define BITESTRING_H
#include "String.h"

class BiteString : public String {
    static inline int kol = 0;
public:
    BiteString();
    BiteString(char *);
    BiteString(const BiteString&);
    // ~BiteString(); деструктора String хватает
    void change_sign();
    BiteString& operator=(const BiteString &);
    BiteString operator+(const BiteString &);
    bool operator==(const BiteString &);
    int getkol() override;
};

#endif //BITESTRING_H