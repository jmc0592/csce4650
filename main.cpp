/*
 * main.cpp
 *
 * The driver for compiler
 */ 
#include "Stack.h"
#include <stdio.h>
 
//Globals for compiler
extern "C" int yyparse();
Stack *stackCopy;

int main()
{
        // Initialize stack of symbol tables
        Stack *stack = new Stack;
        stack->push();

        stackCopy = stack;//make copy to access in compiler

        //register declarations
        int i;
        for(i = 0; i <= 500; i++) {
            if(i == 0)
                printf("int r0,");
            else if( i != 500) 
                printf("r%d,",i);
            else
                printf("r%d;\n",i);
        }
        printf("\n");

        // Initialize key function 
        int yyparse();
        
        return(yyparse());

}