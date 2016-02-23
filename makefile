run: a.out
	./a.out
a.out: driver.cpp List.cpp List.h Record.cpp Record.h Stack.cpp Stack.h SymbolTableList.cpp SymbolTableList.h
	g++ *.cpp
gram.c:	gram.y
		yacc -d gram.y
		mv y.tab.c gram.c
gram.y:	gram.tok gram.prod
		cat gram.tok gram.prod > gram.y
lex.c:	lex.l
		lex lex.l
		mv lex.yy.c lex.c
		