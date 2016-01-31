#include "SymbolTableList.h"

int main()
{
	cout<<"Hello World"<<endl;
    SymbolTableList stl;
    stl.insert("test");
    stl.insert("test2");
    stl.record("test");
    stl.record("random");
    stl.record("test2");

	return 0;
}