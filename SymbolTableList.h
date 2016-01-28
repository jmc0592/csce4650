#include <Set>

class SymbolTableList {
    public:
        void enter_new_scope();
        void leave_current_scope();
        void insert(Set , string);
        void record(string);
};
