#ifndef RECORD_H
#define RECORD_H
#include <string>

using namespace std;

class Record
{
public:
	Record(string);
    void setType(string);
    void setOffset(int);
    
	Record *after;
	string key;
    string type;
    int offset;
};
#endif