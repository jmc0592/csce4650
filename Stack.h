#ifndef STACK_H
#define STACK_H

#include "SymbolTableList.h"

class Stack {
    //friend class SymbolTableList;
    public:
        void push();
        void pop();
        SymbolTableList *top; //pointer to top of the stack
        SymbolTableList *curr; //pointer to current STL (used for searching)
};
#endif