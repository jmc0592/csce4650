#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <list>
using namespace std;

class Record
{
public:
	Record(string);
    void setType(string);
    void setOffset(int);
    void setArrayDimensionList(list<int>);
    list<int> getArrayDimensionList();
    
	Record *after;
	string key;
    string type;
    int iValue;
    int offset;
    list<int> arrayDimension;
};
#endif