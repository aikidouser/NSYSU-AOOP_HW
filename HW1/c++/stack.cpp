#include "stack.h"

#include <iostream>

Stack::Stack() {
    // sp = -1;

    this->sp = -1;
    this->prev = NULL;
    this->top = this;
}

void Stack::push(int x) {
    // stk[++sp] = x;

    Stack *newNode = new Stack();
    newNode->sp = x;
    newNode->prev = top;
    this->top = newNode;
}

int Stack::pop() {
    // return stk[sp--];
    int reValue = -1;

    Stack *popNode = this->top;
    if (popNode->prev == NULL) {
        std::cout << "The stack had been empty." << std::endl;
    } else {
        reValue = popNode->sp;
        this->top = this->top->prev;
        delete popNode;
    }

    return reValue;
}

Stack::~Stack() {}