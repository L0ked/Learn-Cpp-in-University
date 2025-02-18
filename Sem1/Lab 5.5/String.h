#ifndef STRING_H
#define STRING_H


class String {
    static inline int kol = 0;
protected:
    char * str;
    int bitlen;
public:
    String();
    String(char*);
    String(char);
    String(const String &);
    ~String();

    int getlen();
    void clear();
    void print();
    virtual int getkol();

};

#endif //STRING_H