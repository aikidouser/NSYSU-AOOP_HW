#include "lexer.hpp"

#include <iostream>

using namespace std;

int Lexer::line = 1;

Lexer::Lexer() {
    reserve(Word("if", static_cast<int>(Tag::IF)));
    reserve(Word("else", static_cast<int>(Tag::ELSE)));
    reserve(Word("while", static_cast<int>(Tag::WHILE)));
    reserve(Word("do", static_cast<int>(Tag::DO)));
    reserve(Word("break", static_cast<int>(Tag::BREAK)));
    reserve(Word::True);
    reserve(Word::False);
    reserve(Type::Int);
    reserve(Type::Char);
    reserve(Type::Bool);
    reserve(Type::Float);
}

void Lexer::reserve(Word w) {
    // words[w.lexeme] = w;
    words.insert(pair<string, Word>(w.lexeme, w));
}

void Lexer::readch() {
    char i;

    if (is.get(i))
        peek = i;
    else
        throw IOException("End of file reached");
}

bool Lexer::readch(const char& c) {
    readch();
    if (peek != c)
        return false;
    peek = ' ';
    return true;
}

unique_ptr<Token> Lexer::scan() {
    for (;; readch()) {
        if (peek == ' ' || peek == '\t')
            continue;
        else if (peek == '\n')
            line++;
        else
            break;
    }

    switch (peek) {
        case '&':
            if (readch('&'))
                // return new Word(Word::And);
                return make_unique<Word>(Word::And);
            else
                // return new Token('&');
                return make_unique<Token>('&');
            break;
        case '|':
            if (readch('|'))
                // return new Word(Word::Or);
                return make_unique<Word>(Word::Or);
            else
                // return new Token('|');
                return make_unique<Token>('|');
            break;
        case '=':
            if (readch('='))
                // return new Word(Word::eq);
                return make_unique<Word>(Word::eq);
            else
                // return new Token('=');
                return make_unique<Token>('=');
            break;
        case '!':
            if (readch('='))
                // return new Word(Word::ne);
                return make_unique<Word>(Word::ne);
            else
                // return new Token('!');
                return make_unique<Token>('|');
            break;
        case '<':
            if (readch('='))
                // return new Word(Word::le);
                return make_unique<Word>(Word::le);
            else
                // return new Token('<');
                return make_unique<Token>('<');
            break;
        case '>':
            if (readch('='))
                // return new Word(Word::ge);
                return make_unique<Word>(Word::ge);
            else
                // return new Token('>');
                return make_unique<Token>('>');
            break;
    }

    if (isdigit(peek)) {
        int v = 0;
        do {
            v = 10 * v + atoi(string(1, static_cast<char>(peek)).c_str());
            readch();
        } while (isdigit(peek));
        if (peek != '.') {
            // return new Num(v);
            return make_unique<Num>(v);
        }

        float x = v;
        float d = 10;
        for (;;) {
            readch();
            if (!isdigit(peek))
                break;
            x += atoi(string(1, static_cast<char>(peek)).c_str()) / d;
            d *= 10;
        }
        // return new Real(x);
        return make_unique<Real>(x);
    }

    if (isalpha(peek)) {
        string str_b;
        do {
            str_b.push_back(peek);
            readch();
        } while (isalnum(peek));

        string s = str_b;

        if (words.find(s) != words.end()) {
            Word w = words.find(s)->second;
            // return new Word(w);
            return make_unique<Word>(words.find(s)->second);
        }
        Word y = Word(s, static_cast<int>(Tag::ID));
        // return new Word(y);
        return make_unique<Word>(y);
    }

    Token tok = Token(static_cast<int>(peek));
    peek = ' ';
    // return new Token(tok);
    return make_unique<Token>(tok);
};
