run: a.out
	./a.out
program1: driver.cpp List.cpp List.h Record.cpp Record.h Stack.cpp Stack.h SymbolTableList.cpp SymbolTableList.h
	g++ *.cpp
