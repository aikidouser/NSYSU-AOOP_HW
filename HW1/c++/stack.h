#ifndef __STACK_H__
#define __STACK_H__

class Stack {
    enum { STACK_SIZE = 100 };

    int stk[STACK_SIZE];
    int sp;

   public:
    Stack();
    void push(int x);
    int pop();
    ~Stack();
};

#endif
