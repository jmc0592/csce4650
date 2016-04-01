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