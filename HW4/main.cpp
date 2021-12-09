#include <iostream>

#include "lexer.hpp"

using namespace std;

ifstream is;

const std::string TRANSLATE[] = {
    "AND", "BASIC", "BREAK", "DO", "ELSE",
    "EQ", "FALSE", "GE", "ID", "IF",
    "INDEX", "LE", "MINUS", "NE", "NUM",
    "OR", "REAL", "TEMP", "TRUE", "WHILE"};

int main(int argc, const char* argv[]) {
    is.open(argv[1], ios::in);
    Lexer lexer = Lexer();
    try {
        while (1) {
            // Token* t = lexer.scan();
            unique_ptr<Token> t = lexer.scan();
            if (t->tag == 276)
                continue;
            if (t->tag < 256)
                cout << "Token: " << t->toString() << "\t(" << t->toString() << ")" << endl;
            else {
                cout << "Token: " << t->toString() << "\t(" << TRANSLATE[t->tag - 256] << ")" << endl;
            }
            // delete (t);
        }
    } catch (IOException& e) {
        cout << e.get_msg() << endl;
        is.close();
    }

    return 0;
    return 0;
}