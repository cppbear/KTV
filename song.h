#pragma once
#include<iostream>
#include<string>
using namespace std;
class Song
{
public:
	Song() {}
	Song(string songname, string singername, string pinyinname);
	~Song() {}
	int outputID() { return ID; }
	double outputPoints() { return points; }
	string outname() { return name; }
	string outsinger() { return singer; }
	void print();
	void print_with_points();
	bool name_match(string songname);
	bool singer_match(string singername);
	bool pinyin_match(string pinyinname);
	void modiID(int n);
	void modiStatus(int n);
	void addCounts();
	void addReview();
	void modiPoints(double x);
private:
	int ID;
	string name;
	string singer;
	string pinyin;
	int status = 1;
	int display_counts = 0;
	int review_counts = 0;
	double points = 0.0;
};

