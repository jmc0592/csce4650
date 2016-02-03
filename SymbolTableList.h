#ifndef SYMBOLTABLELIST_H
#define SYMBOLTABLELIST_H

#include <set>
#include <string>
#include <iostream>
#include "List.h"

using namespace std;

class Stack;

class SymbolTableList {
    //friend class Stack;
    public:
        void enter_new_scope();
        void leave_current_scope();
        void insert(string);
        void recordSearch(string);
        void searchKeyExists();
        List symbolRecord;
        SymbolTableList *prev;
        Stack *addressToStackTop;//used to access the current stack within a STL
};
#endif