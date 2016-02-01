#include "SymbolTableList.h"
#include "Stack.h"

int main()
{
	SymbolTableList stl;
    Stack *stack = new Stack;
    stack->push();
    stack->top->insert("test");
    //stack->top->recordSearch("test");//should exist
    //stack->push();
    //stack->top->recordSearch("test");//should not exist
    //stack->top->enter_new_scope();
    stack->top->insert("thinky");
    stack->top->insert("lastone");
    stack->top->enter_new_scope();
    stack->top->recordSearch("thinky");
    stack->top->recordSearch("else");
    //stl.enter_new_scope();
    //stl.insert("thingy");

	return 0;
}