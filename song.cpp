#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
#include"song.h"
const double ZERO = 1e-6;
using namespace std;

void Song::print()
{
	cout << setw(8) << ID << setw(16) << name << setw(16) << singer;
	if (status == 0)
		cout << "-----ÕýÔÚ²¥·Å";
	cout << endl;
}

void Song::print_with_points()
{
	cout << setw(8) << points << setw(9) << ID << setw(16) << name << setw(16) << singer << endl;
}

bool Song::name_match(string songname)
{
	if (songname == name)
		return true;
	else
		return false;
}

bool Song::singer_match(string singername)
{
	if (singername == singer)
		return true;
	else
		return false;
}

bool Song::pinyin_match(string pinyinname)
{
	if (pinyinname == pinyin)
		return true;
	else
		return false;
}

void Song::modiID(int n)
{
	ID = n;
}

void Song::modiStatus(int n)
{
	status = n;
}

void Song::addCounts()
{
	display_counts++;
}

void Song::addReview()
{
	review_counts++;
}

void Song::modiPoints(double x)
{
	points = (points * review_counts + x) / (double(review_counts) + 1.0);
}

Song::Song(string songname, string singername, string pinyinname)
{
	name = songname;
	singer = singername;
	pinyin = pinyinname;
}