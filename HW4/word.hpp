#ifndef __WORD_H__
#define __WORD_H__

#include <string>

#include "tag.hpp"
#include "token.hpp"

using namespace std;

class Word : public Token {
   public:
    string lexeme;
    const static Word And;
    const static Word Or;
    const static Word eq;
    const static Word ne;
    const static Word le;
    const static Word ge;
    const static Word minus;
    const static Word True;
    const static Word False;
    const static Word temp;

    Word(string s, int tag) : Token(tag), lexeme(s) {}
    virtual string toString();
    Word operator=(const Word &w);
    friend bool operator!=(const Word &a, const Word &b);
};

#endif