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
		cout << "KTV���ϵͳ";
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
		cout << "1  �û�ֱ��";
		for (int i = 0; i < 11; i++)
			cout << " ";
		cout << "*" << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		cout << "*";
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "2  ����Ա��½";
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "*" << endl;
		for (int i = 0; i < 12; i++)
			cout << " ";
		cout << "*";
		for (int i = 0; i < 9; i++)
			cout << " ";
		cout << "0  �˳�ϵͳ";
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
		cout << "������ѡ��[ ]\b\b";
		int a;
		while (cin >> a)
		{
			if (a == 0)
				return;
			else if (a == 1)
			{
				//�û�����
				system("cls");
				user_main(user, userlist, origin);
				break;
			}
			else if (a == 2)
			{
				//����Ա��¼
				//admin_main(admin, origin);
				
				cin.get();
				system("cls");
				login(admin);
				if (admin.outwrong() < 4)
					admin_main(admin, origin);

				break;
			}
			else
				cout << "�����������������ѡ��[ ]\b\b";
		}
	}
}

void Interface::login(Admin &admin)//��¼��֤
{
	while (true)
	{
		if (admin.outwrong() >= 4)
		{
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "���������������Ѵ����ޣ�\n";
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "ϵͳ������������";
			Sleep(2 * 1000);
			return;
		}
		else
		{
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*******����Ա��¼*******" << endl << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "  ����ԱID��";
			string id;
			getline(cin, id);
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "  ��¼���룺";
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
			//��֤�˺š�����
			if (admin.rightID(id) && admin.rightCode(code_))
			{
				cout << endl;
				for (int i = 0; i < 12; i++)
					cout << " ";
				cout << "��¼�ɹ�������Ϊ����תҳ�桭��";
				Sleep(2 * 1000);
				return;
			}
			else
			{
				cout << endl;
				for (int i = 0; i < 12; i++)
					cout << " ";
				cout << "�˻������������\n";
				for (int i = 0; i < 12; i++)
					cout << " ";
				cout << "�����µ�¼��\n";
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
		//�������
		{
			for (int i = 0; i < 18; i++)
				cout << " ";
			cout << "KTV���ϵͳ��������Ա";
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
			cout << "1  ���и���";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "2  ��Ӹ���";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "3  �����������";
			for (int i = 0; i < 7; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "4  ɾ������";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "5  ��������";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "6  �޸�����";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "0  ��    ��";
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
			cout << "������ѡ��[ ]\b\b";
		}
		int a;
		while (cin >> a)
		{
			if (a == 0)
				return;
			else if (a == 1)
			{
				//���и���
				system("cls");
				allSongs(g);
				break;
			}
			else if (a == 2)
			{
				//��Ӹ���
				system("cls");
				while (true)
				{
					cout << "������\n" << "����\t" << "����\t" << "ƴ��\t\n";
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
							cout << "�������ʧ�ܣ��ø����Ѵ��ڣ�\n\n";
							break;
						}
					}
					if (i == g.outSize() + 1)
					{
						Song temp(songname, singername, pinyinname);
						g.addSong(temp);
						cout << "������ӳɹ����������\n\n";
					}
					cout << "��������������ӣ�����0����\n";
					string a;
					cin >> a;
					if (a == "0")
						break;
				}
				break;
			}
			else if (a == 3)
			{
				//�����������
				system("cls");
				g.importList();
				system("pause");
				break;
			}
			else if (a == 4)
			{
				//ɾ������
				system("cls");
				Delete(g);
				break;
			}
			else if (a == 5)
			{
				//��������
				system("cls");
				sortface(g);
				break;
			}
			else if (a == 6)
			{
				//�޸�����
				system("cls");
				cout << "�����룺";
				string old;
				cin >> old;
				cout << "�����룺";
				string new1;
				cin >> new1;
				cout << "ȷ  �ϣ�";
				string new2;
				cin >> new2;
				if (!admin.rightCode(old) || old == new1 || new1 != new2)
				{
					cout << "�޸�ʧ�ܣ���������ϵͳ��";
					Sleep(2 * 1000);
					return;
				}
				else
				{
					admin.changeCode(new1);
					cout << "�޸ĳɹ���\n";
					system("pause");
				}
				break;
			}
			else
				cout << "�����������������ѡ��[ ]\b\b";
		}
	}
}

void Interface::user_main(User a, SongList &b, SongList &g)
{
	while (true)
	{
		system("cls");
		//�������
		{
			for (int i = 0; i < 19; i++)
				cout << " ";
			cout << "KTV���ϵͳ�����û�";
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
			cout << "1  ���ֵ��";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "2  ��������";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "3  ƴ�����";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "4  ���и���";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "5  �ѵ����";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "6  ��    ��";
			for (int i = 0; i < 11; i++)
				cout << " ";
			cout << "*" << endl;
			for (int i = 0; i < 12; i++)
				cout << " ";
			cout << "*";
			for (int i = 0; i < 9; i++)
				cout << " ";
			cout << "0  ��    ��";
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
			cout << "������ѡ��[ ]\b\b";
		}
		int a;
		while (cin >> a)
		{
			if (a == 0)
				return;
			else if (a == 1)
			{
				//���ֵ��
				system("cls");
				cout << "������Ҫ���ҵĸ�����������1���أ�";
				string singername;
				cin >> singername;
				if (singername == "1")
					break;
				else
				{
					bool flag = g.searchSinger(singername);
					while (flag)
					{
						cout << "������Ҫ��ӵĸ����ı�ţ�����0���أ�";
						int t;
						cin >> t;
						if (t == 0)
							break;
						else
						{
							Song h = g.outputSong(t);
							if (!h.singer_match(singername))
							{
								cout << "���������ڣ����ʧ�ܣ�\n";
								continue;
							}
							else
							{
								g.print_by_ID(t);
								b.addSong(h);
								b.changeStatus(1);
								cout << "��ӳɹ���\n";
							}
						}
					}
				}
				break;
			}
			else if (a == 2)
			{
				//��������
				system("cls");
				cout << "������Ҫ���ҵĸ�����������1���أ�";
				string songname;
				cin >> songname;
				if (songname == "1")
					break;
				else
				{
					bool flag = g.searchSong(songname);
					while (flag)
					{
						cout << "������Ҫ��ӵĸ����ı�ţ�����0���أ�";
						int t;
						cin >> t;
						if (t == 0)
							break;
						else 
						{
							Song h = g.outputSong(t);
							if (!h.name_match(songname))
							{
								cout << "���������ڣ����ʧ�ܣ�\n";
								continue;
							}
							else
							{
								g.print_by_ID(t);
								b.addSong(h);
								b.changeStatus(1);
								cout << "��ӳɹ���\n";
							}
						}
					}
				}
				break;
			}
			else if (a == 3)
			{
				//ƴ�����
				system("cls");
				cout << "������Ҫ���ҵĸ���ƴ����������1���أ�";
				string pinyinname;
				cin >> pinyinname;
				if (pinyinname == "1")
					break;
				else
				{
					bool flag = g.searchPinyin(pinyinname);
					while (flag)
					{
						cout << "������Ҫ��ӵĸ����ı�ţ�����0���أ�";
						int t;
						cin >> t;
						if (t == 0)
							break;
						else
						{
							Song h = g.outputSong(t);
							if (!h.pinyin_match(pinyinname))
							{
								cout << "���������ڣ����ʧ�ܣ�\n";
								continue;
							}
							else
							{
								g.print_by_ID(t);
								b.addSong(h);
								b.changeStatus(1);
								cout << "��ӳɹ���\n";
							}
						}
					}
				}
				break;
			}
			else if (a == 4)
			{
				//���и���
				system("cls");
				allSongs(g);
				break;
			}
			else if (a == 5)
			{
				//�ѵ����
				while (true)
				{
					system("cls");
					int m;
					int page = 1;
					bool flag = true;
					while (flag)
					{
						system("cls");
						cout << setw(9) << "���" << setw(15) << "������" << setw(16) << "����\n";
						cout << "--------------------------------------------------\n";
						if (page < 1)
							page = 1;
						else if (page > b.outSize() / 10 + 1)
							page = b.outSize() / 10 + 1;
						b.printList(10 * (page - 1));
						cout << endl;
						cout << "��" << page << "ҳ����" << b.outSize() / 10 + 1 << "ҳ����һҳ����������һҳ������������ESC������ҳ";
						cout << endl << endl << "����1-->�ö�����\n" << "����2-->�Ƴ�����\n" << "����3-->�и�\n" << "����0-->�˳�\n";
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
					//�ö�
					else if (m == 1)
					{
						cout << "����������Ҫ�ö��ĸ�����ţ�";
						int s;
						cin >> s;
						if (s == 1)
						{
							cout << "��ǰ�������ڲ����У��޷��ö���\n";
							Sleep(2 * 1000);
						}
						else if (s > b.outSize() || s <= 0)
						{
							cout << "�ø��������ڣ�����ʧ�ܣ�\n";
							Sleep(2 * 1000);
						}
						else
						{
							b.topIt(s);
							cout << "�ö��ɹ����������¸赥\n";
							Sleep(2 * 1000);
						}
					}
					//�Ƴ�
					else if (m == 2)
					{
						cout << "����������Ҫ�Ƴ��ĸ�����ţ�";
						int s;
						cin >> s;
						if (s == 1)
						{
							cout << "��ǰ�������ڲ����У��޷��Ƴ���\n";
							Sleep(2 * 1000);
						}
						else if (s > b.outSize() || s <= 0)
						{
							cout << "�ø��������ڣ�����ʧ�ܣ�\n";
							Sleep(2 * 1000);
						}
						else
						{
							b.deleteSong(s);
							cout << "�Ƴ��ɹ����������¸赥\n";
							Sleep(2 * 1000);
						}
					}
					//�и�
					else if (m == 3)
					{
						cout << "��ȷ��Ҫ�и���(y/n)";
						char key;
						cin >> key;
						if (key == 'n')
						{
							cout << "������ֹ��\n";
							Sleep(2 * 1000);
						}
						else if (key == 'y')
						{						
							Song first = b.outputSong(1);
							if (b.outSize() > 1)
							{
								cout << "����Ϊ���׸�������(y/n)";
								char ans;
								cin >> ans;
								if (ans == 'y')
								{
									cout << "�������������(1~5)��";
									double p;
									cin >> p;
									g.regard(p, first);
									g.addreview(first);
								}
								else if (ans == 'n')
									cout << "ף��K����죡";
								g.addcounts(first);
								b.deleteSong(1);
								b.changeStatus(1);
								cout << "�и�ɹ����������¸赥\n";
								Sleep(2 * 1000);
							}
							else
							{
								cout << "��ǰ�赥�޷������и������";
								Sleep(2 * 1000);
							}
						}
					}
					else
					{
						cout << "�����������������";
						Sleep(1 * 1000);
					}
				}
				break;
			}
			else if (a == 6)
			{
				//�и�
				system("cls");
				int m;
				int page = 1;
				bool flag = true;
				while (flag)
				{
					system("cls");
					cout << setw(9) << "���" << setw(15) << "������" << setw(16) << "����\n";
					cout << "--------------------------------------------------\n";
					if (page < 1)
						page = 1;
					else if (page > b.outSize() / 10 + 1)
						page = b.outSize() / 10 + 1;
					b.printList(10 * (page - 1));
					cout << endl;
					cout << "��" << page << "ҳ����" << b.outSize() / 10 + 1 << "ҳ����һҳ����������һҳ������������ESC������ҳ";
					cout << endl << endl << "����1-->�и�\n";
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
						cout << "��ȷ��Ҫ�и���(y/n)";
						char key;
						cin >> key;
						if (key == 'n')
						{
							cout << "������ֹ��\n";
							Sleep(2 * 1000);
						}
						else if (key == 'y')
						{
							Song first = b.outputSong(1);
							if (b.outSize() > 1)
							{
								cout << "����Ϊ���׸�������(y/n)";
								char ans;
								cin >> ans;
								if (ans == 'y')
								{
									cout << "�������������(1~5)��";
									double p;
									cin >> p;
									g.regard(p, first);
									g.addreview(first);
								}
								else if (ans == 'n')
									cout << "ף��K����죡";
								g.addcounts(first);
								b.deleteSong(1);
								b.changeStatus(1);
								cout << "�и�ɹ����������¸赥\n";
								Sleep(2 * 1000);
							}
							else
							{
								cout << "��ǰ�赥�޷������и������";
								Sleep(2 * 1000);
							}
						}
					}
				}
				break;
			}
			else
				cout << "�����������������ѡ��[ ]\b\b";
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
		cout << setw(9) << "���" << setw(15) << "������" << setw(16) << "����\n";
		cout << "--------------------------------------------------\n";
		if (page < 1)
			page = 1;
		else if (page > h.outSize() / 10 + 1)
			page = h.outSize() / 10 + 1;
		h.printList(10 * (page - 1));
		cout << endl;
		cout << "��" << page << "ҳ����" << h.outSize() / 10 + 1 << "ҳ����һҳ����������һҳ������������ESC������ҳ";
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
		cout << setw(9) << "���" << setw(15) << "������" << setw(16) << "����\n";
		cout << "--------------------------------------------------\n";
		if (page < 1)
			page = 1;
		else if (page > h.outSize() / 10 + 1)
			page = h.outSize() / 10 + 1;
		h.printList(10 * (page - 1));
		cout << endl;
		cout << "��" << page << "ҳ����" << h.outSize() / 10 + 1 << "ҳ����һҳ����������һҳ������������ESC������ҳ\n\n";
		cout << "����0����ɾ������";
		char ch = _getch();
		switch (ch) {
		case 72: --page; break;  // up
		case 80: ++page; break;  // down
		case 27: flag = false; break;  // esc
		case 48: flag = false; break;
		//default: break;
		}
	}
	cout << "\n������Ҫɾ���ĸ�����ţ�����0����ɾ��������";
	int a;
	cin >> a;
	if (a == 0)
	{
		cout << "������ֹ��\n";
		system("pause");
	}
	else
	{
		cout << "���Ҫɾ����(y/n)";
		char choice;
		cin >> choice;
		if (choice == 'y')
		{
			h.deleteSong(a);
			cout << "ɾ���ɹ���\n";
			system("pause");
		}
		else
		{
			cout << "������ֹ��\n";
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
		cout << setw(9) << "����" << setw(9) << "���" << setw(15) << "������" << setw(16) << "����\n";
		cout << "---------------------------------------------------------\n";
		if (page < 1)
			page = 1;
		else if (page > origin.outSize() / 10 + 1)
			page = origin.outSize() / 10 + 1;
		origin.printwithpoints(10 * (page - 1));
		cout << endl;
		cout << "��" << page << "ҳ����" << origin.outSize() / 10 + 1 << "ҳ����һҳ����������һҳ������������ESC������ҳ";
		char ch = _getch();
		switch (ch) {
		case 72: --page; break;  // up
		case 80: ++page; break;  // down
		case 27: flag = false; break;  // esc
			//default: break;
		}
	}
}
