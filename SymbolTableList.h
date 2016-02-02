#ifndef SYMBOLTABLELIST_H
#define SYMBOLTABLELIST_H

#include <set>
#include <string>
#include <iostream>
#include "List.h"

using namespace std;

class SymbolTableList {
    public:
        void enter_new_scope();
        void leave_current_scope();
        void insert(string);
        void recordSearch(string);
        void searchKeyExists();
        List symbolRecord2;
        set <string> symbolRecord;
        SymbolTableList *prev;
};
#endif