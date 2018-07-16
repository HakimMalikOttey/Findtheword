#pragma once
#ifndef RECORDME_H
#define RECORDME_H

#include <string>
using namespace std;

class record {
public:
	record();
	~record();
	record(string);
	string getword();
	void setword(string);
private:
	string Name;
};



#endif