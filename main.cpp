/*  global variable(s), used in the compiler  */
int const_value;
extern "C" int yyparse();



int main()
{
        int yyparse();

        /*  first we set up any initialization necessary for the compiler  */


        /*  We MIGHT have some code here to spit out any "formatting" that
            the output (assembler ?) requires  before the "real" code
            things like .csect commands, .text,  etc. */

        /*  yyparse is the name of the parser.  It parses the program, and
            allows us to spit out code during the parse.  */
        
        return(yyparse());

        /*  Having compiled the program an spit out the code, we might need
            to add some postscript to the assembler output --- space statements,
            etc.  */
}