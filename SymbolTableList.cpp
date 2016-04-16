/*
 * SymbolTableList.cpp
 */
#include "SymbolTableList.h"
#include "Stack.h"

//push new STL on to stack
void SymbolTableList::enter_new_scope()
{
    Stack *copy = this->addressToStackTop;
    copy->push(); 
}

//pop current STL off the stack
void SymbolTableList::leave_current_scope()
{
    Stack *copy = this->addressToStackTop;
    copy->pop();
}

void SymbolTableList::insert(string k)
{
    Record *temp = new Record(k);
    if(symbolRecord.head == NULL){ //first insert
        symbolRecord.head = temp; //linking head
        symbolRecord.current = temp; //continuing current
    }
    else{
        symbolRecord.current->after = temp; //single linking
        symbolRecord.current = symbolRecord.current->after; //moving forward
    }
}

Record * SymbolTableList::recordSearch(string key)
{
    Stack *stackCpy = this->addressToStackTop;
    SymbolTableList *templist = stackCpy->curr;
    
    while(templist !=NULL){
        if(templist->symbolRecord.head != NULL){ //looping starting at the head
            Record *temp = templist->symbolRecord.head;
            while(temp->after != NULL){
                if(temp->key == key){
                    //cout << key << " is found in symbol table stored at " << templist << endl;
                    return temp;
                }
                temp = temp->after;
            }
            if(temp->key == key){ //this outer if prevents above loop from going too far and segfaulting
                //cout << key << " is found in symbol table stored at " << templist << endl;
                return temp;
            }
            else{
                //cout<<"This table does not contain "<<key<<endl;
            }
        }
        else{
            //cout<<"There are no records in current stack"<<endl;
            return NULL;
        }
        if(templist->prev != NULL){ //moving to new stack
            templist = templist->prev;
        }
        else{
            return NULL;
        }
    }
    return NULL;
}

int SymbolTableList::offsetSearch(string key)
{
    Stack *stackCpy = this->addressToStackTop;
    SymbolTableList *templist = stackCpy->curr;
    
    while(templist !=NULL){
        if(templist->symbolRecord.head != NULL){ //looping starting at the head
            Record *temp = templist->symbolRecord.head;
            while(temp->after != NULL){
                if(temp->key == key){
                    //cout << key << " is found in symbol table with offset " << temp->offset << endl;
                    return temp->offset;
                }
                temp = temp->after;
            }
            if(temp->key == key){ //this outer if prevents above loop from going too far and segfaulting
                //cout << key << " is found in symbol table with offset: " << temp->offset << endl;
                return temp->offset;
            }
            else{
                //cout<<"This table does not contain "<<key<<endl;
            }
        }
        else{
            //cout<<"There are no records in current stack"<<endl;
            return -1;
        }
        if(templist->prev != NULL){ //moving to new stack
            templist = templist->prev;
        }
        else{
            return -1;
        }
    }
    return 0;
}

void SymbolTableList::searchKeyExists() //Temporary function, used for testing and seeing all entries in all symbol tables
{
    Stack *stackCpy = this->addressToStackTop;
    SymbolTableList *templist = stackCpy->curr;
    
    while(templist !=NULL){
        if(templist->symbolRecord.head != NULL){
            Record *temp = templist->symbolRecord.head;
            while(temp->after != NULL){
                cout<<temp->key<<endl;
                temp = temp->after;
            }
            //cout<<temp->key<<endl;
        }
        else{
            //cout<<"there are no records in current stack"<<endl;
        }

        if(templist->prev != NULL){
            templist = templist->prev;
        }
    	else{
    		return;
    	}
	}
}
