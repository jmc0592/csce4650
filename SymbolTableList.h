#include <set>
#include <string>
#include <iostream>

using namespace std;

class SymbolTableList {
    public:
        void enter_new_scope();
        void leave_current_scope();
        void insert(set <SymbolTableList>, string);
        void record(string);
};
