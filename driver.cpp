#include "SymbolTableList.h"

int main()
{
	cout<<"Hello World"<<endl;
    SymbolTableList stl;
    stl.insert("test");
    stl.insert("test2");
    stl.recordSearch("test");
    stl.recordSearch("random");
    stl.recordSearch("test2");

	return 0;
}