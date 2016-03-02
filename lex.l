Digit		[0-9]
Letter		[a-zA-Z]
IntLit		{Digit}+


%{
#include "SymbolTableList.h"
#include "gram.tab.h"
#include <string>
#include "Stack.h"
void process_id();
using namespace std;
//#define YY_DECL extern "C" int yylex();
%}

%%
[ \t\n]+							{ /* delete */		}
"/begin/"							{	return BEGIN;	}
"/end/"								{	return END;	}
{Letter}({Letter}|{Digit}|_)*		{ 
										process_id();
					  					return (ID);		
					  				}
{IntLit}							{ 
										yylval.intstuff = atoi(yytext);
				          				return (INTLITERAL);
				          			}
"="									{ return ('=');		}
";"									{ return (';');		}
"*"									{ return ('*');		}
"/"									{ return ('/');		}
"+"									{ return ('+');		}
"-"                                 { return ('-');     } 
%%

void process_id()
{
    //todo
	Stack *symbolTableStack = new Stack;

	stack->push();

	//no record already there
	string tempYytext(yytext);
	if(stack->top->recordSearch(tempYytext) == 0) {
		stack->top->insert(tempYytext);
	}

}

int column = 0;

/*
void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}
*/