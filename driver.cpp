/*
 * driver.cpp
 * Generates test output of how the SymbolTableList will work
 */
#include "SymbolTableList.h"
#include "Stack.h"

int main()
{
    cout << endl << "Comments surrounded by --- --- are what is expected / done." << endl;
    cout << "Hex values represent the address of the SymbolTableList." << endl << endl;
    Stack *stack = new Stack;

    stack->push();
    cout << "---First SymbolTableList pushed---" << endl;
    stack->top->insert("test");
    cout << "---Inserted 'test'---" << endl;
    stack->top->insert("test1");
    cout << "---Inserted 'test1'---" << endl;
    stack->top->enter_new_scope();
    cout << "---Second SymbolTableList pushed onto stack---" << endl;
    stack->top->insert("Sweany");
    cout << "---Inserted 'Sweany'---" << endl;
    stack->top->recordSearch("Sweany");
    cout << "---'Sweany' should be found---" << endl;
    stack->top->recordSearch("Garlick");
    cout << "---'Garlick' should NOT be found---" << endl;
    stack->top->recordSearch("test");
    cout << "---'test' should be found---" << endl;
    stack->top->leave_current_scope();
    cout << "---Pop off current stack---" << endl;
    stack->top->recordSearch("test1");
    cout << "---'test1' should be found in same address as 'test'---" << endl;


	return 0;
}
