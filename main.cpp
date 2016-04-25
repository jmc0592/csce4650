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
    for(i = 0; i <= 100; i++) {
        if(i == 0)
            printf("int r0,");
        else if( i != 100) 
            printf("r%d,",i);
        else
            printf("r%d;\n",i);
    }
    printf("\n");

	//pointer declarations
	printf("int *iptr1;\nchar *cptr1;\nchar *fp, *sp;\n");
    printf("\nchar globalData[8192];\n");
        
	printf("r100 = 0;\n");//reserve r100 for 0

    // Initialize key function 
    int yyparse();
    
    return(yyparse());
}
