Digit		[0-9]
Letter		[a-zA-Z]
IntLit		{Digit}+

%{
#include "SymbolTableList.h"
#include "y.tab.h"
%}

%%
[ \t\n]+							{ /* delete */		}
{Letter}({Letter}|{Digit}|_)*		{ process_id();
					  				return (ID);		}
{IntLit}							{ yylval.intstuff = atoi(yytext);
				          			return (INTLITERAL);}
"begin"								{ return ("begin");	
                                    printf("begin token found\n");//debug 
                                    }
"end"								{ return ("end");	
                                    printf("end token found\n");//debug
                                    }
"="									{ return ('=');		}
";"									{ return (';');		}
"*"									{ return ('*');		}
"/"									{ return ('/');		}
"+"									{ return ('+');		}
"-"                                 { return ('-');     } 
%%

/*
 * TODO: Change this to to fit our data structures
 */
process_id()
{
	/*  The following uses a chained hash table implementation of
            a symbol table.  Each "bucket" of the hash table consists
            of a list.  Each element of THOSE lists (Nodes) contain
	    a field "stuff" which has the acutal symbol table goodies,
	    like a character string "key" and an integer "register number."
	*/

	Node list_node;
	SymbolTableElement symbol_table_node;
	if( ! (list_node = (Node) search_table(yytext) ) )
	{
	   /*  a symbol table entry has a character string "key" taken
               from yytext, and a register "number", in the range 4-31.  */

		symbol_table_node = create_symbol_table_entry(
			yytext,assign_next_register());
		insert_in_table(symbol_table_node);
	}
	else
	{
	    /* the identifier (whose name is stored in yytext) is already
               in the symbol table.  */

		symbol_table_node = list_node->stuff;
	}
	yylval.symbolstuff = symbol_table_node;
}

int assign_next_register()
{
	/* The compiler allocates each variable to a different machine
           register.  This routine just chooses the next register in
           the range r4 to r31.  Registers r0-r3 are reserved for other
           purposes  */

	static int register_number;
	register_number = (register_number + 1) % 28;
	return register_number + 4;
}
