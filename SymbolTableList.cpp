#include "SymbolTableList.h"
#include "Stack.h"

void SymbolTableList::enter_new_scope()
{

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
    //this code block tests and confirms the access to current and prev STL
    //JUST FOR TESTING
    Stack *stackCpy = this->addressToStackTop;
    cout << this << " this(current STL) address in recordSearch()" << endl;
    cout << stackCpy->top << " STL address in recordSearch()" << endl;//same as above address
    cout << stackCpy->top->prev << " prevSTL address in recordSearch()" << endl;

    if(symbolRecord2.head != NULL){
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
    else{
        cout<<"there are no records in current stack"<<endl;
    }

    //delete stackCpy;//free memory
}

void SymbolTableList::searchKeyExists() //Temporary function, may not be need
{
    Stack *stackCpy = this->addressToStackTop;
    SymbolTableList *templist = stackCpy->curr;
    
    while(templist !=NULL){
        cout<<"gone into stack"<<endl;
        if(templist->symbolRecord2.head != NULL){
            Record *temp = templist->symbolRecord2.head;
            while(temp->after != NULL){
                cout<<temp->key<<endl;
                temp = temp->after;
            }
            cout<<temp->key<<endl;
        }
        else{
            cout<<"there are no records in current stack"<<endl;
        }
        if(templist->prev != NULL){
            templist = templist->prev;
        }
	else{
		return;
	}
    }

    
    
}
