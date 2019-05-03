#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<Windows.h>
#include<algorithm>
#include"song_list.h"
using namespace std;

//还有添加编号
void SongList::importList()
{
	cout << "请输入要导入的文件名，输入1返回\n";
	string filename;
	cin >> filename;
	if (filename == "1")
		return;
	else
	{
		ifstream fin;
		fin.open(filename);
		if (!fin.is_open())
		{
			cout << "文件不存在！\n" << "3秒后退出！\n";
			Sleep(3 * 1000);
			return;
		}
		else
		{
			int same = 0;
			int diff = 0;
			while (fin.good())
			{
				string songname;
				string singername;
				string pinyinname;
				fin >> songname;
				fin >> singername;
				fin >> pinyinname;
				int i;
				for (i = 0; i < list.size(); i++)
					if (list[i].name_match(songname) && list[i].singer_match(singername))
					{
						same++;
						break;
					}
				if (i == list.size())
				{
					Song song(songname, singername, pinyinname);
					list.push_back(song);
					diff++;
				}
			}
			for (int i = 0; i < list.size(); i++)
				list[i].modiID(i + 1);
			cout << diff << "首添加成功！\n";
			if (same > 0)
			{
				cout << same << "首添加失败！\n";
				cout << "失败原因：歌曲已存在\n";
			}
		}
	}
}

void SongList::printList(int begin)
{
	for (int i = begin; i < list.size() && i < begin + 10; i++)
	{
		list[i].print();
	}
}

void SongList::printwithpoints(int begin)
{
	for (int i = begin; i < list.size() && i < begin + 10; i++)
	{
		list[i].print_with_points();
	}
}

void SongList::print_by_ID(int ID_)
{
	list[ID_ - 1].print();
}

void SongList::addSong(Song a)
{
	list.push_back(a);
	for (int i = 0; i < list.size(); i++)
		list[i].modiID(i + 1);
}

void SongList::modifySong()
{

}

void SongList::deleteSong(int ID_)
{
	int i;
	for (i = 0; i < list.size(); i++)
		if (list[i].outputID() == ID_)
		{
			list.erase(list.begin() + i);
			break;
		}
	int j;
	for (j = i; j < list.size(); j++)
		list[j].modiID(list[j].outputID() - 1);
}

bool comp_points(Song a, Song b)
{
	return a.outputPoints() > b.outputPoints();
}

void SongList::sortList()
{
	sort(list.begin(), list.end(), comp_points);
}

bool SongList::searchSinger(string singername)
{
	int n = 0;
	for (int i = 0; i < list.size(); i++)
		if (list[i].singer_match(singername))
		{
			list[i].print();
			n++;
		}
	if (n == 0)
	{
		cout << "您要查找的歌手不存在！即将退出";
		Sleep(2 * 1000);
		return false;
	}
	else
		return true;
}

bool SongList::searchSong(string songname)
{
	int n = 0;
	for (int i = 0; i < list.size(); i++)
		if (list[i].name_match(songname))
		{
			list[i].print();
			n++;
		}
	if (n == 0)
	{
		cout << "您要查找的歌曲不存在！即将退出";
		Sleep(2 * 1000);
		return false;
	}
	else
		return true;
}

bool SongList::searchPinyin(string pinyinname)
{
	int n = 0;
	for (int i = 0; i < list.size(); i++)
		if (list[i].pinyin_match(pinyinname))
		{
			list[i].print();
			n++;
		}
	if (n == 0)
	{
		cout << "您要查找的歌曲不存在！即将退出";
		Sleep(2 * 1000);
		return false;
	}
	else
		return true;
}

void SongList::topIt(int ID_)
{
	Song temp;
	temp = list[ID_ - 1];
	for (int i = ID_ - 1; i > 1; i--)
		list[i] = list[i - 1];
	list[1] = temp;
	for (int i = 0; i < list.size(); i++)
		list[i].modiID(i + 1);
}

void SongList::regard(double p, Song a)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].outname() == a.outname() && list[i].outsinger() == a.outsinger())
			list[i].modiPoints(p);
}

void SongList::addreview(Song a)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].outname() == a.outname() && list[i].outsinger() == a.outsinger())
			list[i].addReview();
}

void SongList::addcounts(Song a)
{
	for (int i = 0; i < list.size(); i++)
		if (list[i].outname() == a.outname() && list[i].outsinger() == a.outsinger())
			list[i].addCounts();
}




