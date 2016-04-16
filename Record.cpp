#include "Record.h"

Record::Record(string k){
	key = k;
	after = NULL;
}

void Record::setOffset(int os)
{
    offset = os;
}

void Record::setType(string t)
{
    type = t;
}

void Record::setArrayDimensionList(list<int> l)
{
    arrayDimension = l;
}

list<int> Record::getArrayDimensionList()
{
    return arrayDimension;
}