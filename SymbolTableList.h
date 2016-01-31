#include <set>
#include <string>
#include <iostream>

using namespace std;

class SymbolTableList {
    public:
        void enter_new_scope();
        void leave_current_scope();
        void insert(string);
        void record(string);
        bool searchKeyExists(string);
        set <string> symbolRecord;
};
