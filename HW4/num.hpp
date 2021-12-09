#ifndef __NUM_H__
#define __NUM_H__

#include "tag.hpp"
#include "token.hpp"

class Num : public Token {
   public:
    int value;
    Num(int v) : Token(static_cast<int>(Tag::NUM)), value(v) {}
    string toString();
};

#endif  // __NUM_H__