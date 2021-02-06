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
		cout << "Введите " << i << "-й элемент списка:\t";
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
		cout << i << "-й элемент списка:\t" << *startpos << endl;
		i++;
	}
}
bool AddElement()
{
	string value;
	bool check = false;
	list <string> ::iterator startpos = list_of_char.begin();
	list <string> ::iterator endpos = list_of_char.end();
	cout << "Введите имя поля, после которого нужно добавить элемент:\t";
	cin >> value;
	for (startpos; startpos != endpos; startpos++) 
	{
		if ((*startpos) == value) 
		{
			string tmp;
			list <string> ::iterator currentpos = startpos;
			cout << "Введите значение нового поля:\t";
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
	cout << "Введите размер списка:\t";
	cin >> size;
	while (size < 1) 
	{
		cout << "Введите корректное число:\t";
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
	cout << "Список перед изменением:" << endl;
	Print_list();
	cout << "=============================" << endl;
	if (AddElement())
	{
		cout << "=============================" << endl;
		cout << "Список после изменения:" << endl;
		Print_list();
		cout << "=============================" << endl;
	}
	else 
	{
		cout << "Такого элемента в списке нет!" << endl;
		cout << "=============================" << endl;
	}
}