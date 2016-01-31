#include "SymbolTableList.h"

void SymbolTableList::enter_new_scope()
{
    //push new STL onto Stack when open curly seen
}

void SymbolTableList::leave_current_scope()
{
    //pop current STL off the stack
}

void SymbolTableList::insert(string key)
{
    if(SymbolTableList::searchKeyExists(key) == true)
        return;
    else
        SymbolTableList::symbolRecord.insert(key);
}

void SymbolTableList::recordSearch(string key)
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