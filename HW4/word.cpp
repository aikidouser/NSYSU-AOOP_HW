#include "word.hpp"

#include <string>

using namespace std;

const Word Word::And = Word("&&", static_cast<int>(Tag::AND));
const Word Word::Or = Word("||", static_cast<int>(Tag::OR));
const Word Word::eq = Word("==", static_cast<int>(Tag::EQ));
const Word Word::ne = Word("!=", static_cast<int>(Tag::NE));
const Word Word::le = Word("<=", static_cast<int>(Tag::LE));
const Word Word::ge = Word(">=", static_cast<int>(Tag::GE));
const Word Word::minus = Word("minus", static_cast<int>(Tag::MINUS));
const Word Word::True = Word("true", static_cast<int>(Tag::TRUE));
const Word Word::False = Word("false", static_cast<int>(Tag::FALSE));
const Word Word::temp = Word("t", static_cast<int>(Tag::TEMP));
// const Word Word::NULLWord = Word("NULL", Tag::NULLTAG);

string Word::toString() {
    return lexeme;
}

Word Word::operator=(const Word &w) {
    return Word(w.lexeme, w.tag);
}

bool operator!=(const Word &a, const Word &b) {
    return ((a.lexeme != b.lexeme) || (a.tag != b.tag));
}