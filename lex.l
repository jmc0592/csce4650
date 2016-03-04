Digit		[0-9]
Letter		[a-zA-Z]
IntLit		{Digit}+


%{
#include "SymbolTableList.h"
#include "gram.tab.h"
#include <string>
#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Record.h"
void process_id();
using namespace std;
extern "C" int yylex();
%}

%%
[ \t\n]+							{ /* delete */		}
"output"							{	printf("[Lexor]:Found 'output'\n");
										return(OUTPUT);
									}
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
"("									{
										printf("[Lexor]:Found '('\n");
										return('(');
									}
")"									{
										printf("[Lexor]:Found ')'\n");
										return(')');
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
	List *symbolRecord = new List;

	//cout << "address of stackCopy " << stackCopy << endl;
	//no record already there
	string tempYytext(yytext);
	stackCopy->top->searchKeyExists();//debug
	cout<<"[Lexor]:";//for recordSearch print statement
	if(stackCopy->top->recordSearch(tempYytext) == 0) {
		stackCopy->top->insert(tempYytext);
		Record *temp = new Record(tempYytext);
		symbolRecord->current = temp;
		yylval.symbolstuff = symbolRecord;
	}

}
