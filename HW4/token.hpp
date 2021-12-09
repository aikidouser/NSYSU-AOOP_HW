#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

using namespace std;

class Token {
   public:
    int tag;

    Token(int t) : tag(t) {}
    virtual string toString();
};

#endif