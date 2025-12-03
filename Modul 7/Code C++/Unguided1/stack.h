#ifndef STACK_H
#define STACK_H

const int MAXSTACK = 20;

typedef int infotype;

struct Stack {
    infotype info[MAXSTACK];
    int top;
};

// PROTOTYPE
void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
