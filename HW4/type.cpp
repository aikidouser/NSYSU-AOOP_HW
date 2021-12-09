#include "type.hpp"

const Type Type::Int = Type("int", static_cast<int>(Tag::BASIC), 4);
const Type Type::Float = Type("float", static_cast<int>(Tag::BASIC), 8);
const Type Type::Char = Type("char", static_cast<int>(Tag::BASIC), 1);
const Type Type::Bool = Type("bool", static_cast<int>(Tag::BASIC), 1);

bool Type::numeric(const Type &p) {
    if (p == Char || p == Int || p == Float)
        return true;
    else
        return false;
}

Type Type::max(const Type &p1, const Type &p2) {
    if (!numeric(p1) || !numeric(p2))
        return Type(" ", 0, 0);  // return Null
    else if (p1 == Type::Float || p2 == Type::Float)
        return Type::Float;
    else if (p1 == Type::Int || p2 == Type::Int)
        return Type::Int;
    else
        return Type::Char;
}

bool operator==(const Type &a, const Type &b) {
    return ((a.tag == b.tag) && (a.lexeme == b.lexeme) && (a.width == b.width));
}
