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
{Letter}({Letter}|{Digit}|_)*		{ 
										process_id();
					  					return (ID);		
					  				}
{IntLit}							{ 
										yylval.intstuff = atoi(yytext);
				          				return (INTLITERAL);
				          			}
begin								{	
										return (BEGIN);	
                                    }
end									{
										return (END);	
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
