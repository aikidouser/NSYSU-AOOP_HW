#include "stack.h"

Stack::Stack() {
    sp = -1;
}

void Stack::push(int x) {
    stk[++sp] = x;
}

int Stack::pop() {
    return stk[sp--];
}

Stack::~Stack() {}