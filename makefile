run: a.out
	./a.out
a.out: driver.cpp List.cpp List.h Record.cpp Record.h Stack.cpp Stack.h SymbolTableList.cpp SymbolTableList.h
	g++ *.cpp
