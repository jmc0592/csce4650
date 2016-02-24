run: compiler
	./compiler

compiler: main.o gram.o List.o Record.o Stack.o SymbolTableList.o
		g++ main.o gram.o lex.o List.o Record.o Stack. SymbolTableList.o -o compiler

gram.o:	gram.c lex.o main.o
		g++ -c gram.c -lfl

gram.c:	gram.y
		bison -d gram.y
		mv gram.tab.c gram.c

gram.y:	gram.tok gram.prod
		cat gram.tok gram.prod > gram.y

lex.o:	gram.tok lex.c
		g++ -c lex.c -lfl

lex.c:	lex.l
		flex lex.l
		mv lex.yy.c lex.c

Stack.o:	Stack.cpp Stack.h
			g++ -c Stack.cpp

SymbolTableList.o:	SymbolTableList.cpp SymbolTableList.h
					g++ -c SymbolTableList.cpp

Record.o:	Record.cpp Record.h
			g++ -c Record.cpp

List.o:	List.cpp List.h
		g++ -c List.cpp

main.o:	main.cpp
		g++ -c main.cpp
		
clean:	
		rm *.o compiler gram.y gram.c lex.c gram.tab.h