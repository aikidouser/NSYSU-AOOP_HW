#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void push(struct stack* this, int x) {
    // this->stk[++this->sp] = x;

    struct stack* newNode = malloc(sizeof(struct stack));
    newNode->prev = this->top;
    newNode->val = x;
    this->top = newNode;
}

int pop(struct stack* this) {
    // return this->stk[this->sp--];
    int re_val = -1;

    if (this->top != this) {
        struct stack* popNode = this->top;
        re_val = popNode->val;
        this->top = popNode->prev;
        free(popNode);

    } else {
        printf("The stack is empty\n");
    }
    return re_val;
}

struct stack* new_stack() {
    struct stack* stk = malloc(sizeof(struct stack));
    stk->val = -1;
    stk->top = stk;
    stk->prev = NULL;

    return stk;
}

void delete_stack(struct stack* stk) {
    if (stk->top == stk) {
        free(stk);
        return;
    }
    while (stk->top != NULL) {
        struct stack* delNode = stk->top;
        stk->top = delNode->prev;
        printf("Del node\n");
        free(delNode);
    }
}
