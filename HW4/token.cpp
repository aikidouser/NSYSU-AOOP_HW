#include "token.hpp"

#include <iostream>

string Token::toString() {
    // cout << "token.tostring: " << static_cast<char>(tag);
    return string(1, static_cast<char>(tag));
}