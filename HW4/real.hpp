#ifndef __REAL_H__
#define __REAL_H__

#include "tag.hpp"
#include "token.hpp"

class Real : public Token {
   public:
    float value;

    Real(float v) : Token(static_cast<int>(Tag::REAL)), value(v) {}
    string toString();
};

#endif