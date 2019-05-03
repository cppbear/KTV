#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include"interface.h"

using namespace std;

void Interface::mainmenu()
{
	SongList origin;
	//origin.importList();
	//origin.printList();
	Admin admin;
	User user;
	SongList userlist;
	while (true)
	{
		system("cls");
		for (int i = 0; i < 23; i++)
			cout << " ";
		cout << "KTV点歌系统";
		cout << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		for (int i = 0; i < 33; i++)
			cout << "=";
		cout << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		cout << "*";
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "1  用户直达";
		for (int i = 0; i < 11; i++)
			cout << " ";
		cout << "*" << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		cout << "*";
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "2  管理员登陆";
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "*" << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		cout << "*";
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "0  退出系统";
		for (int i = 0; i < 11; i++)
			cout << " ";
		cout << "*" << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		for (int i = 0; i < 33; i++)
			cout << "=";
		cout << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		cout << "请输入选项[ ]\b\b";
		int a;
		while (cin >> a)
		{
			if (a == 0)
				return;
			else if (a == 1)
			{
				//用户界面
				system("cls");
				user_main(user, userlist, origin);
				break;
			}
			else if (a == 2)
			{
				//管理员登录
				//admin_main(admin, origin);
				
				cin.get();
				system("cls");
				login(admin);
				if (admin.outwrong() < 4)
					admin_main(admin, origin);

				break;
			}
			else
				cout << "输入错误，请重新输入选项[ ]\b\b";
		}
	}
}

void Interface::login(Admin &admin)//登录验证
{
	while (true)
	{
		if (admin.outwrong() >= 4)
		{
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "您的输入错误次数已达上限！\n";
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "系统即将锁定……";
			Sleep(2 * 1000);
			return;
		}
		else
		{
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*******管理员登录*******" << endl << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "  管理员ID：";
			string id;
			getline(cin, id);
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "  登录密码：";
			char temp[13];
			string code_;
			for (int i = 0; i < 13; i++)
			{
				temp[i] = _getch();
				if (temp[i] == '\r')
				{
					temp[i] = '\0';
					break;
				}
				cout << "*";
			}
			code_ = temp;
			cout << endl;
			//验证账号、密码
			if (admin.rightID(id) && admin.rightCode(code_))
			{
				cout << endl;
				for (int i = 0; i < 12; i++)
					cout << " ";
				cout << "登录成功！即将为您跳转页面……";
				Sleep(2 * 1000);
				return;
			}
			else
			{
				cout << endl;
				for (int i = 0; i < 12; i++)
					cout << " ";
				cout << "账户名或密码错误！\n";
				for (int i = 0; i < 12; i++)
					cout << " ";
				cout << "请重新登录！\n";
				Sleep(2 * 1000);
				admin.addWrong();
				system("cls");
			}
		}
	}
}

void Interface::admin_main(Admin &admin, SongList &g)
{
	while (true)
	{
		system("cls");
		//界面输出
		{
			for (int i = 0; i < 18; i++)
				cout << " ";
			cout << "KTV点歌系统——管理员";
			cout << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			for (int i = 0; i < 33; i++)
				cout << "=";
			cout << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "1  所有歌曲";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "2  添加歌曲";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "3  批量导入歌曲";
			for (int i = 0; i < 7; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "4  删除歌曲";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "5  歌曲排序";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "6  修改密码";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "0  退    出";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			for (int i = 0; i < 33; i++)
				cout << "=";
			cout << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "请输入选项[ ]\b\b";
		}
		int a;
		while (cin >> a)
		{
			if (a == 0)
				return;
			else if (a == 1)
			{
				//所有歌曲
				system("cls");
				allSongs(g);
				break;
			}
			else if (a == 2)
			{
				//添加歌曲
				system("cls");
				while (true)
				{
					cout << "请输入\n" << "歌名\t" << "歌手\t" << "拼音\t\n";
					string songname;
					string singername;
					string pinyinname;
					cin >> songname >> singername >> pinyinname;					
					int i;
					for (i = 1; i <= g.outSize(); i++)
					{
						Song h = g.outputSong(i);
						if (h.name_match(songname) && h.singer_match(singername))
						{
							cout << "歌曲添加失败，该歌曲已存在！\n\n";
							break;
						}
					}
					if (i == g.outSize() + 1)
					{
						Song temp(songname, singername, pinyinname);
						g.addSong(temp);
						cout << "歌曲添加成功，你真棒！\n\n";
					}
					cout << "输入其它继续添加，输入0返回\n";
					string a;
					cin >> a;
					if (a == "0")
						break;
				}
				break;
			}
			else if (a == 3)
			{
				//批量导入歌曲
				system("cls");
				g.importList();
				system("pause");
				break;
			}
			else if (a == 4)
			{
				//删除歌曲
				system("cls");
				Delete(g);
				break;
			}
			else if (a == 5)
			{
				//歌曲排序
				system("cls");
				sortface(g);
				break;
			}
			else if (a == 6)
			{
				//修改密码
				system("cls");
				cout << "旧密码：";
				string old;
				cin >> old;
				cout << "新密码：";
				string new1;
				cin >> new1;
				cout << "确  认：";
				string new2;
				cin >> new2;
				if (!admin.rightCode(old) || old == new1 || new1 != new2)
				{
					cout << "修改失败！即将返回系统！";
					Sleep(2 * 1000);
					return;
				}
				else
				{
					admin.changeCode(new1);
					cout << "修改成功！\n";
					system("pause");
				}
				break;
			}
			else
				cout << "输入错误，请重新输入选项[ ]\b\b";
		}
	}
}

void Interface::user_main(User a, SongList &b, SongList &g)
{
	while (true)
	{
		system("cls");
		//界面输出
		{
			for (int i = 0; i < 19; i++)
				cout << " ";
			cout << "KTV点歌系统——用户";
			cout << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			for (int i = 0; i < 33; i++)
				cout << "=";
			cout << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "1  歌手点歌";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "2  歌曲搜索";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "3  拼音点歌";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "4  所有歌曲";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "5  已点歌曲";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "6  切    歌";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "0  退    出";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			for (int i = 0; i < 33; i++)
				cout << "=";
			cout << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "请输入选项[ ]\b\b";
		}
		int a;
		while (cin >> a)
		{
			if (a == 0)
				return;
			else if (a == 1)
			{
				//歌手点歌
				system("cls");
				cout << "请输入要查找的歌手名，输入1返回：";
				string singername;
				cin >> singername;
				if (singername == "1")
					break;
				else
				{
					bool flag = g.searchSinger(singername);
					while (flag)
					{
						cout << "请输入要添加的歌曲的编号，输入0返回：";
						int t;
						cin >> t;
						if (t == 0)
							break;
						else
						{
							Song h = g.outputSong(t);
							if (!h.singer_match(singername))
							{
								cout << "歌曲不存在！添加失败！\n";
								continue;
							}
							else
							{
								g.print_by_ID(t);
								b.addSong(h);
								b.changeStatus(1);
								cout << "添加成功！\n";
							}
						}
					}
				}
				break;
			}
			else if (a == 2)
			{
				//歌曲搜索
				system("cls");
				cout << "请输入要查找的歌曲名，输入1返回：";
				string songname;
				cin >> songname;
				if (songname == "1")
					break;
				else
				{
					bool flag = g.searchSong(songname);
					while (flag)
					{
						cout << "请输入要添加的歌曲的编号，输入0返回：";
						int t;
						cin >> t;
						if (t == 0)
							break;
						else 
						{
							Song h = g.outputSong(t);
							if (!h.name_match(songname))
							{
								cout << "歌曲不存在！添加失败！\n";
								continue;
							}
							else
							{
								g.print_by_ID(t);
								b.addSong(h);
								b.changeStatus(1);
								cout << "添加成功！\n";
							}
						}
					}
				}
				break;
			}
			else if (a == 3)
			{
				//拼音点歌
				system("cls");
				cout << "请输入要查找的歌曲拼音名，输入1返回：";
				string pinyinname;
				cin >> pinyinname;
				if (pinyinname == "1")
					break;
				else
				{
					bool flag = g.searchPinyin(pinyinname);
					while (flag)
					{
						cout << "请输入要添加的歌曲的编号，输入0返回：";
						int t;
						cin >> t;
						if (t == 0)
							break;
						else
						{
							Song h = g.outputSong(t);
							if (!h.pinyin_match(pinyinname))
							{
								cout << "歌曲不存在！添加失败！\n";
								continue;
							}
							else
							{
								g.print_by_ID(t);
								b.addSong(h);
								b.changeStatus(1);
								cout << "添加成功！\n";
							}
						}
					}
				}
				break;
			}
			else if (a == 4)
			{
				//所有歌曲
				system("cls");
				allSongs(g);
				break;
			}
			else if (a == 5)
			{
				//已点歌曲
				while (true)
				{
					system("cls");
					int m;
					int page = 1;
					bool flag = true;
					while (flag)
					{
						system("cls");
						cout << setw(9) << "编号" << setw(15) << "歌曲名" << setw(16) << "歌手\n";
						cout << "--------------------------------------------------\n";
						if (page < 1)
							page = 1;
						else if (page > b.outSize() / 10 + 1)
							page = b.outSize() / 10 + 1;
						b.printList(10 * (page - 1));
						cout << endl;
						cout << "第" << page << "页，共" << b.outSize() / 10 + 1 << "页，上一页（↑），下一页（↓），输入ESC返回主页";
						cout << endl << endl << "输入1-->置顶歌曲\n" << "输入2-->移除歌曲\n" << "输入3-->切歌\n" << "输入0-->退出\n";
						char ch = _getch();
						switch (ch) {
						case 72: --page; break;  // up
						case 80: ++page; break;  // down
						case 27: m = 0; flag = false; break;  // esc
						case 48: m = 0; flag = false; break;
						case 49: m = 1; flag = false; break;
						case 50: m = 2; flag = false; break;
						case 51: m = 3; flag = false; break;
						//default: break;
						}
					}
					if (m == 0)
						break;
					//置顶
					else if (m == 1)
					{
						cout << "请输入你想要置顶的歌曲编号：";
						int s;
						cin >> s;
						if (s == 1)
						{
							cout << "当前歌曲正在播放中，无法置顶！\n";
							Sleep(2 * 1000);
						}
						else if (s > b.outSize() || s <= 0)
						{
							cout << "该歌曲不存在，操作失败！\n";
							Sleep(2 * 1000);
						}
						else
						{
							b.topIt(s);
							cout << "置顶成功！即将更新歌单\n";
							Sleep(2 * 1000);
						}
					}
					//移除
					else if (m == 2)
					{
						cout << "请输入你想要移除的歌曲编号：";
						int s;
						cin >> s;
						if (s == 1)
						{
							cout << "当前歌曲正在播放中，无法移除！\n";
							Sleep(2 * 1000);
						}
						else if (s > b.outSize() || s <= 0)
						{
							cout << "该歌曲不存在，操作失败！\n";
							Sleep(2 * 1000);
						}
						else
						{
							b.deleteSong(s);
							cout << "移除成功！即将更新歌单\n";
							Sleep(2 * 1000);
						}
					}
					//切歌
					else if (m == 3)
					{
						cout << "你确定要切歌吗？(y/n)";
						char key;
						cin >> key;
						if (key == 'n')
						{
							cout << "操作中止！\n";
							Sleep(2 * 1000);
						}
						else if (key == 'y')
						{						
							Song first = b.outputSong(1);
							if (b.outSize() > 1)
							{
								cout << "你想为这首歌评分吗？(y/n)";
								char ans;
								cin >> ans;
								if (ans == 'y')
								{
									cout << "请输入你的评分(1~5)：";
									double p;
									cin >> p;
									g.regard(p, first);
									g.addreview(first);
								}
								else if (ans == 'n')
									cout << "祝你K歌愉快！";
								g.addcounts(first);
								b.deleteSong(1);
								b.changeStatus(1);
								cout << "切歌成功！即将更新歌单\n";
								Sleep(2 * 1000);
							}
							else
							{
								cout << "当前歌单无法进行切歌操作！";
								Sleep(2 * 1000);
							}
						}
					}
					else
					{
						cout << "输入错误，请重新输入";
						Sleep(1 * 1000);
					}
				}
				break;
			}
			else if (a == 6)
			{
				//切歌
				system("cls");
				int m;
				int page = 1;
				bool flag = true;
				while (flag)
				{
					system("cls");
					cout << setw(9) << "编号" << setw(15) << "歌曲名" << setw(16) << "歌手\n";
					cout << "--------------------------------------------------\n";
					if (page < 1)
						page = 1;
					else if (page > b.outSize() / 10 + 1)
						page = b.outSize() / 10 + 1;
					b.printList(10 * (page - 1));
					cout << endl;
					cout << "第" << page << "页，共" << b.outSize() / 10 + 1 << "页，上一页（↑），下一页（↓），输入ESC返回主页";
					cout << endl << endl << "输入1-->切歌\n";
					char ch = _getch();
					switch (ch) {
					case 72: --page; break;  // up
					case 80: ++page; break;  // down
					case 27: m = 0; flag = false; break;  // esc
					case 49: m = 1; flag = false; break;
						//default: break;
					}
					if (m == 0)
						break;
					else if (m == 1)
					{
						cout << "你确定要切歌吗？(y/n)";
						char key;
						cin >> key;
						if (key == 'n')
						{
							cout << "操作中止！\n";
							Sleep(2 * 1000);
						}
						else if (key == 'y')
						{
							Song first = b.outputSong(1);
							if (b.outSize() > 1)
							{
								cout << "你想为这首歌评分吗？(y/n)";
								char ans;
								cin >> ans;
								if (ans == 'y')
								{
									cout << "请输入你的评分(1~5)：";
									double p;
									cin >> p;
									g.regard(p, first);
									g.addreview(first);
								}
								else if (ans == 'n')
									cout << "祝你K歌愉快！";
								g.addcounts(first);
								b.deleteSong(1);
								b.changeStatus(1);
								cout << "切歌成功！即将更新歌单\n";
								Sleep(2 * 1000);
							}
							else
							{
								cout << "当前歌单无法进行切歌操作！";
								Sleep(2 * 1000);
							}
						}
					}
				}
				break;
			}
			else
				cout << "输入错误，请重新输入选项[ ]\b\b";
		}
	}
}

void Interface::allSongs(SongList h)
{
	int page = 1;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << setw(9) << "编号" << setw(15) << "歌曲名" << setw(16) << "歌手\n";
		cout << "--------------------------------------------------\n";
		if (page < 1)
			page = 1;
		else if (page > h.outSize() / 10 + 1)
			page = h.outSize() / 10 + 1;
		h.printList(10 * (page - 1));
		cout << endl;
		cout << "第" << page << "页，共" << h.outSize() / 10 + 1 << "页，上一页（↑），下一页（↓），输入ESC返回主页";
		char ch = _getch();
		switch (ch) {
		case 72: --page; break;  // up
		case 80: ++page; break;  // down
		case 27: flag = false; break;  // esc
		//default: break;
		}
	}
}

void Interface::Delete(SongList &h)
{
	int page = 1;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << setw(9) << "编号" << setw(15) << "歌曲名" << setw(16) << "歌手\n";
		cout << "--------------------------------------------------\n";
		if (page < 1)
			page = 1;
		else if (page > h.outSize() / 10 + 1)
			page = h.outSize() / 10 + 1;
		h.printList(10 * (page - 1));
		cout << endl;
		cout << "第" << page << "页，共" << h.outSize() / 10 + 1 << "页，上一页（↑），下一页（↓），输入ESC返回主页\n\n";
		cout << "输入0进行删除操作";
		char ch = _getch();
		switch (ch) {
		case 72: --page; break;  // up
		case 80: ++page; break;  // down
		case 27: flag = false; break;  // esc
		case 48: flag = false; break;
		//default: break;
		}
	}
	cout << "\n请输入要删除的歌曲编号，输入0结束删除操作：";
	int a;
	cin >> a;
	if (a == 0)
	{
		cout << "操作中止！\n";
		system("pause");
	}
	else
	{
		cout << "真的要删除吗？(y/n)";
		char choice;
		cin >> choice;
		if (choice == 'y')
		{
			h.deleteSong(a);
			cout << "删除成功！\n";
			system("pause");
		}
		else
		{
			cout << "操作中止！\n";
			system("pause");
		}
	}
}

void Interface::sortface(SongList origin)
{
	origin.sortList();
	int page = 1;
	bool flag = true;
	while (flag)
	{
		system("cls");
		cout << setw(9) << "评分" << setw(9) << "编号" << setw(15) << "歌曲名" << setw(16) << "歌手\n";
		cout << "---------------------------------------------------------\n";
		if (page < 1)
			page = 1;
		else if (page > origin.outSize() / 10 + 1)
			page = origin.outSize() / 10 + 1;
		origin.printwithpoints(10 * (page - 1));
		cout << endl;
		cout << "第" << page << "页，共" << origin.outSize() / 10 + 1 << "页，上一页（↑），下一页（↓），输入ESC返回主页";
		char ch = _getch();
		switch (ch) {
		case 72: --page; break;  // up
		case 80: ++page; break;  // down
		case 27: flag = false; break;  // esc
			//default: break;
		}
	}
}
