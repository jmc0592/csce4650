#ifndef STACK_H
#define STACK_H

#include "SymbolTableList.h"

extern Stack *stackCopy;

class Stack {
    public:
        void push();
        void pop();
        SymbolTableList *top; //pointer to top of the stack
        SymbolTableList *curr; //pointer to current STL (used for searching)
};
#endif