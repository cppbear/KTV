#pragma once
#include<iostream>
#include<string>
#include"administrator.h"
#include"user.h"
#include"song_list.h"
using namespace std;
class Interface
{
public:
	Interface() {};
	~Interface() {};
	void mainmenu();
	void login(Admin &admin);
	void admin_main(Admin &admin, SongList &g);
	void user_main(User a, SongList &b, SongList &g);
	void allSongs(SongList origin);
	void Delete(SongList &h);
	void sortface(SongList origin);
private:

};

