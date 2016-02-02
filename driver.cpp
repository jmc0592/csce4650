#include "SymbolTableList.h"
#include "Stack.h"
//comment thing
int main()
{
    Stack *stack = new Stack;
    stack->push();
    stack->top->insert("test");
    stack->top->insert("test1");
    stack->push();
    stack->top->insert("Sweany");
    stack->top->enter_new_scope();
    stack->top->recordSearch("Sweany");

	return 0;
}