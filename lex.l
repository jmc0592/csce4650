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
"="									{ printf("[Lexor]:equal found\n");
										return ('=');		}
";"									{ 	
										printf("[Lexor]:Semicolon, end of statement\n");
										return (';');		
									}
"**"								{ printf("[Lexor]:exponent found\n");
										return (EXPONENT);}
"*"									{ printf("[Lexor]:multiplication found\n");
										return ('*');		}
"/"									{ printf("[Lexor]:division found \n");
										return ('/');		}
"+"									{ printf("[Lexor]:addition found \n");
										return ('+');		}
"-"                                 { printf("[Lexor]:subtraction found \n");
										return ('-');     } 
%%

void process_id()
{
	cout<<"[Lexor]:things are happening"<<endl;
    //todo
	Stack *symbolTableStack = new Stack;

	symbolTableStack->push();

	//no record already there
	string tempYytext(yytext);
	if(symbolTableStack->top->recordSearch(tempYytext) == 0) {
		symbolTableStack->top->insert(tempYytext);
	}

}
