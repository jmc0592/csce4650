#include "SymbolTableList.h"

void SymbolTableList::enter_new_scope()
{
    Record *temp = symbolRecord2.head;
    while(temp->after != NULL){
        cout<<temp->key<<endl;
        temp = temp->after;
    }
    cout<<temp->key<<endl;
}

void SymbolTableList::leave_current_scope()
{
    //pop current STL off the stack
}

void SymbolTableList::insert(string k)
{
    Record *temp = new Record(k);
    if(symbolRecord2.head == NULL){
        symbolRecord2.head = temp;
        symbolRecord2.current = temp;
    }
    else{
        symbolRecord2.current->after = temp;
        symbolRecord2.current = symbolRecord2.current->after;
    }
}

void SymbolTableList::recordSearch(string key)
{
    Record *temp = symbolRecord2.head;
    while(temp->after != NULL){
        if(temp->key == key){
            cout<<"it is found"<<endl;
            return;
        }
        temp = temp->after;
    }
    if(temp->key == key){ //this outer if prevents above loop from going too far and segfaulting
        cout<<"it is found"<<endl;
        return;
    }
    else{
        cout<<"it is not found"<<endl;
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