#include "SymbolTableList.h"

class Stack {
    public:
        void push(SymbolTableList );
        SymbolTableList pop(SymbolTableList );
        SymbolTableList *top; //pointer to top of the stack
        SymbolTableList *curr; //pointer to current STL (used for searching)
};