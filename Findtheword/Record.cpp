#include "stdafx.h"
#include <iostream>
#include "Record.h"
using namespace std;

record::record(){}
record::~record(){}
record::record(string a){
	Name = a;
}
string record::getword(){
	return Name;
}
void record::setword(string a){
	Name = a;
}