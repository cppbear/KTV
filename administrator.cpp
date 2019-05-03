#include<iostream>
#include<string>
#include"administrator.h"
using namespace std;
bool Admin::rightID(string id)
{
	return id == ID ? true : false;
}
bool Admin::rightCode(string code_)
{
	return code_ == code ? true : false;
}
void Admin::changeCode(string newcode)
{
	code = newcode;
}
