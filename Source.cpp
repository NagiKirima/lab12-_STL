#include <iostream>
#include <list>
#include <string>
#include <iterator>
using namespace std;
list <string> list_of_char;
void Create_list(int size) 
{
	string tmp;
	for (int i = 0; i < size; i++)
	{
		cout << "������� " << i << "-� ������� ������:\t";
		cin >> tmp;
		list_of_char.push_back(tmp);
	}
}
void Print_list()
{
	list <string> ::iterator startpos = list_of_char.begin();
	list <string> ::iterator endpos = list_of_char.end();
	int i = 0;
	for (startpos; startpos != endpos; startpos++)
	{
		cout << i << "-� ������� ������:\t" << *startpos << endl;
		i++;
	}
}
bool AddElement()
{
	string value;
	bool check = false;
	list <string> ::iterator startpos = list_of_char.begin();
	list <string> ::iterator endpos = list_of_char.end();
	cout << "������� ��� ����, ����� �������� ����� �������� �������:\t";
	cin >> value;
	for (startpos; startpos != endpos; startpos++) 
	{
		if ((*startpos) == value) 
		{
			string tmp;
			list <string> ::iterator currentpos = startpos;
			cout << "������� �������� ������ ����:\t";
			cin >> tmp;
			list_of_char.insert(++currentpos, tmp);
			check = true;
		}
	}
	return check;
}
int GetSize() 
{
	int size;
	cout << "������� ������ ������:\t";
	cin >> size;
	while (size < 1) 
	{
		cout << "������� ���������� �����:\t";
		cin >> size;
	}
	return size;
}
int main()
{
	setlocale(LC_ALL, "ru");
	int size;
	size = GetSize();
	Create_list(size);
	cout << "=============================" << endl;
	cout << "������ ����� ����������:" << endl;
	Print_list();
	cout << "=============================" << endl;
	if (AddElement())
	{
		cout << "=============================" << endl;
		cout << "������ ����� ���������:" << endl;
		Print_list();
		cout << "=============================" << endl;
	}
	else 
	{
		cout << "������ �������� � ������ ���!" << endl;
		cout << "=============================" << endl;
	}
}