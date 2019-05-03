#pragma once
#include<iostream>
#include<string>
#include"song.h"
#include"song_list.h"
using namespace std;
class Admin
{
public:
	Admin() {};
	~Admin() {};
	void changeCode(string newcode);
	bool rightID(string id);
	bool rightCode(string code_);
	void addWrong() { wrongtimes++; }
	void setWrong(int n) { wrongtimes = n; }
	int outwrong() { return wrongtimes; }
private:
	string ID = "njucs";
	string code = "ABCcb1124";
	int wrongtimes = 0;
};

