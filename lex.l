Digit		[0-9]
Letter		[a-zA-Z]
IntLit		{Digit}+
StrLit		{Letter}*


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
"continue"							{	printf("[Lexor]:Found 'continue'\n");
										return CONTINUE;	
									}
"else"								{	printf("[Lexor]:Found 'else'\n");
										return ELSE;	
									}
"do"								{	printf("[Lexor]:Found 'do'\n");
										return DO;	
									}
"not"								{	printf("[Lexor]:Found 'not'\n");
										return NOT;	
									}																																				
".lt."								{	printf("[Lexor]:Found '.lt.'\n");
										return LT;
									}
".le."								{	printf("[Lexor]:Found '.le.'\n");
										return LE;
									}									
".gt."								{	printf("[Lexor]:Found '.gt.'\n");
										return GT;
									}
".ge."								{	printf("[Lexor]:Found '.ge.'\n");
										return GE;
									}
".eq."								{	printf("[Lexor]:Found '.eq.'\n");
										return EQ;
									}
".neq."								{	printf("[Lexor]:Found '.neq.'\n");
										return NEQ;
									}
"int"								{	printf("[Lexor]:Found 'int'\n");
										yylval.stringstuff = yytext;
										return (INT);
									}
"char"								{	printf("[Lexor]:Found 'char'\n");
										yylval.stringstuff = yytext;
										return (CHAR);
									}
"bool"								{	printf("[Lexor]:Found 'bool'\n");
										return (BOOL);
									}
"void"								{	printf("[Lexor]:Found 'void'\n");
										return (VOID);
									}
"quit"								{
										printf("[Lexor]:Found 'quit'\n");
										return QUIT;
									}			
"return"							{
										printf("[Lexor]:Found 'return'\n");
										return RETURN;
									}																																																																														

{Letter}({Letter}|{Digit}|_)*		{ 
										printf("[Lexor]: found 'NAME'\n");
										process_id();
					  					return (NAME);		
					  				}
{IntLit}							{
										printf("[Lexor]: found 'INTLITERAL'\n");
										yylval.intstuff = atoi(yytext);
				          				return (INTLITERAL);
				          			}
\"([^\\\"]|\\.)*\"					{
										printf("[Lexor]: found 'STRINGLITERAL'\n");
										return STRINGLITERAL;
									}				          			
","									{	printf("[Lexor]: found ','\n");
										return (',');
									}				          			
"("									{
										printf("[Lexor]:Found '('\n");
										return('(');
									}
")"									{
										printf("[Lexor]:Found ')'\n");
										return(')');
									}
"["									{	printf("[Lexor]: '[' found\n");
										return ('[');
									}
"]"									{	printf("[Lexor]: ']' found\n");
										return (']');
									}										
"="									{ printf("[Lexor]:equal found\n");
										return ('=');		}
";"									{ 	
										printf("[Lexor]:found ';'\n");
										return (';');		
									}
":"									{	printf("[Lexor]: found ':'\n");
										return (':');
									}									
"**"								{ printf("[Lexor]:exponent found\n");
										return (EXPONENT);}
"*"									{ printf("[Lexor]:multiplication found\n");
										return ('*');		}
"/"									{ printf("[Lexor]:division found \n");
										return ('/');		}
"%"									{ printf("[Lexor]:modulo found\n");
										return ('%');		}										
"++"								{	printf("[Lexor]: '++' found\n");
										return ('++');
									}								
"+"									{ printf("[Lexor]:addition found \n");
										return ('+');		}
"--"								{	printf("[Lexor]: '--' found\n");
										return ('--');
									}										
"-"                                 { printf("[Lexor]:subtraction found \n");
										return ('-');     
									}
"&"									{	printf("[Lexor]: '&' found\n");
										return ('&');
									}
"|"									{	printf("[Lexor]: '|' found\n");
										return ('|');
									}																	
"^"									{	printf("[Lexor]: '^' found\n");
										return ('^');
									}									
"~"									{	printf("[Lexor]: '~' found\n");
										return ('~');
									}	
">>"								{	printf("[Lexor]: '>>' found\n");
										return ('>>');
									}
"<<"								{	printf("[Lexor]: '<<' found\n");
										return ('<<');
									}																																		 
%%



void process_id()
{
	List *symbolRecord = new List;

	string tempYytext(yytext);
	//stackCopy->top->searchKeyExists();//debug
	
	//cout<<"[Lexor][process_id()]:";//for recordSearch print statement
	
	//no record already there
	if(stackCopy->top->recordSearch(tempYytext) == 0) {
		stackCopy->top->insert(tempYytext);
		Record *temp = new Record(tempYytext);
		symbolRecord->current = temp;
	} else {//record in symbol table
		Record *temp = new Record(tempYytext);
		symbolRecord->current = temp;
	}
	yylval.symbolstuff = symbolRecord;
}
