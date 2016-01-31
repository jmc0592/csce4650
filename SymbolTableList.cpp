#include "SymbolTableList.h"

void SymbolTableList::enter_new_scope()
{
//logic
}

void SymbolTableList::leave_current_scope()
{
//logic
}

void SymbolTableList::insert(string key)
{
    if(SymbolTableList::searchKeyExists(key) == true)
        return;
    else
        SymbolTableList::symbolRecord.insert(key);
}

void SymbolTableList::record(string key)
{
    if(SymbolTableList::searchKeyExists(key) == true) {
        cout << key << " exists." << endl;
    } else {
        cout << key << " does not exist." << endl;
        //enter new scope
    }
}

bool SymbolTableList::searchKeyExists(string key)
{
    if(SymbolTableList::symbolRecord.find(key) == SymbolTableList::symbolRecord.end()) {
        return false;
    } else {
        return true;
    }
}