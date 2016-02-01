#include "Stack.h"
#include "SymbolTableList.h"
using namespace std;

void Stack::push()
{

    if(top == NULL) {//if stack is empty
        SymbolTableList *s = new SymbolTableList();
        s->prev = NULL;
        top = s;
        curr = s;
    } else {//if at least one element is in the stack
        SymbolTableList *s = new SymbolTableList();
        s->prev = top;
        top = s;
        curr = s;
    }
}

void Stack::pop()
{
    if(top == NULL) {//empty stack. nothing to pop
        return;
    } else if(top->prev == NULL) {
        top = NULL;
        curr = NULL;
    } else {
        top = top->prev;
        curr = top;
    }
}