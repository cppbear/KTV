#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"song.h"
using namespace std;
class SongList
{
public:
	SongList() {};
	~SongList() {};
	void importList();
	void printList(int begin);
	void printwithpoints(int begin);
	void print_by_ID(int ID_);
	Song outputSong(int ID_) { return list[ID_ - 1]; };
	void addSong(Song a);
	void modifySong();
	void deleteSong(int ID_);
	void sortList();
	bool searchSinger(string singername);
	bool searchSong(string songname);
	bool searchPinyin(string pinyinname);
	void changeStatus(int ID_) { list[ID_ - 1].modiStatus(0); };
	void topIt(int ID_);
	int outSize() { return list.size(); }
	void regard(double p, Song a);
	void addreview(Song a);
	void addcounts(Song a);
private:
	vector<Song> list;
};

