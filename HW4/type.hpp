#ifndef __TYPE_H__
#define __TYPE_H__

#include <string>

#include "word.hpp"

class Type : public Word {
   public:
    // int width = 0;
    int width;
    const static Type Int;
    const static Type Float;
    const static Type Char;
    const static Type Bool;

    Type(string s, int tag, int w = 0)
        : Word(s, tag), width(w) {}
    static bool numeric(const Type &p);
    static Type max(const Type &p1, const Type &p2);
    friend bool operator==(const Type &a, const Type &b);
};

#endif