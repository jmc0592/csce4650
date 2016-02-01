#include "SymbolTableList.h"
#include "Stack.h"

int main()
{
    Stack *stack = new Stack;
    stack->push();
    stack->top->insert("test");
    stack->top->recordSearch("test");//should exist
    stack->push();
    stack->top->recordSearch("test");//should not exist

	return 0;
}