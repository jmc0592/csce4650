#include <set>
#include <string>
#include <iostream>
#include "Record.h"

using namespace std;

class SymbolTableList {
    public:
        void enter_new_scope();
        void leave_current_scope();
        void insert(string);
        void recordSearch(string);
        bool searchKeyExists(string);
        set <string> symbolRecord;
        SymbolTableList *prev;
};
