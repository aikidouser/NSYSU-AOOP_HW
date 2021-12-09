#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include <ctype.h>

#include <exception>
#include <fstream>
#include <map>
#include <memory>
#include <string>

#include "num.hpp"
#include "real.hpp"
#include "tag.hpp"
#include "token.hpp"
#include "type.hpp"
#include "word.hpp"

using namespace std;

extern ifstream is;

class Lexer {
   public:
    static int line;

    Lexer();
    Token* scan();

   private:
    char peek = ' ';

    // TODO:
    map<string, Word> words;
    void reserve(Word w);
    void readch();
    bool readch(const char& c);
};

class IOException : public exception {
   public:
    IOException(const string& e) : message(e) {}
    const char* get_msg() const noexcept { return message.c_str(); }

   private:
    string message;
};

#endif