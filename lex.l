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
extern "C" int yylex();
%}

%%
[ \t\n]+							{ /* delete */		}
"output"							{	printf("[Lexor]:Found 'ouput()'\n");}
"begin"								{	printf("[Lexor]:Found 'begin'\n");
									return BEG;	
								}
"end"								{	printf("[Lexor]:Found 'end'\n");
									return END;	
								}
{Letter}({Letter}|{Digit}|_)*		{ 
										process_id();
					  					return (ID);		
					  				}
{IntLit}							{ 
										yylval.intstuff = atoi(yytext);
				          				return (INTLITERAL);
				          			}
"="									{ return ('=');		}
";"									{ 	
										printf("[Lexor]:Semicolon, end of statement\n");
										return (';');		
									}
"**"								{ return (EXPONENT);}
"*"									{ return ('*');		}
"/"									{ return ('/');		}
"+"									{ return ('+');		}
"-"                                 { return ('-');     } 
%%

void process_id()
{
	cout<<"things are happening"<<endl;
    //todo
	Stack *symbolTableStack = new Stack;

	symbolTableStack->push();

	//no record already there
	string tempYytext(yytext);
	if(symbolTableStack->top->recordSearch(tempYytext) == 0) {
		symbolTableStack->top->insert(tempYytext);
	}

}
