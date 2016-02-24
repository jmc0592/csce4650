Digit		[0-9]
Letter		[a-zA-Z]
IntLit		{Digit}+

%{
#include "SymbolTableList.h"
#include "gram.tab.h"
#define YY_DECL extern "C" int yylex()
%}

%%
[ \t\n]+							{ /* delete */		}
{Letter}({Letter}|{Digit}|_)*		{ process_id();
					  				return (ID);		}
{IntLit}							{ yylval.intstuff = atoi(yytext);
				          			return (INTLITERAL);}
"begin"								{ return (BEGIN);	
                                    printf("begin token found\n");//debug 
                                    }
"end"								{ return (END);	
                                    printf("end token found\n");//debug
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
}
