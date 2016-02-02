#include "Stack.h"
#include "SymbolTableList.h"
using namespace std;

void Stack::push()
{

    if(top == NULL) {//if stack is empty
        SymbolTableList *s = new SymbolTableList();
        s->prev = NULL;
        s->addressToStackTop = this;//assigns Stack address to STL
        top = s;
        curr = s;
    } else {//if at least one element is in the stack
        SymbolTableList *s = new SymbolTableList();
        s->prev = top;
        s->addressToStackTop = this;//assigns Stack address to STL
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