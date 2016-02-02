#include "SymbolTableList.h"
#include "Stack.h"

int main()
{
	SymbolTableList stl;
    Stack *stack = new Stack;
    cout << stack << endl;
    stack->push();
    cout << stack->top->addressToStackTop << endl;//address to stack
    stack->top->insert("test");
    stack->top->insert("jacobsayspoop");
    //stack->top->recordSearch("test");//should exist
    stack->push();
    cout << stack->top->addressToStackTop << endl;//address to stack. same as earlier one.
    //stack->top->recordSearch("test");//should not exist
    //stack->top->enter_new_scope();
    stack->top->insert("thinky");
    //stack->top->insert("lastone");
    stack->top->searchKeyExists();
    //stack->top->recordSearch("thinky");
    //stack->top->recordSearch("else");
    //stack->top->recordSearch("test");
    //stl.enter_new_scope();
    //stl.insert("thingy");

	return 0;
}