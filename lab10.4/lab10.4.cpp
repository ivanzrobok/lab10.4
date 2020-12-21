// lab10.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Варіант 9.
//Створити текстовий файл, рядки якого містять дані про назву фірми, назву товару,
//ціну в доларах.Перерахувати ціни в гривнях у відповідності з курсом гривні та дописати в
//кожний рядок нового файлу отримані значення.
//Кожний рядок нового файлу має містити вміст відповідного рядка першого файлу, в
//кінці якого має бути записана ціна товару в гривнях.


#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Firm
{
	string name_firm;
	string name_item;
	double price;
};
void input_file(const string fname);
void print_file(const string fname);
void recalculate_money(const string fname,const string gname);
void print_change_money(const string gname);
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string namef;
	cout << "Введіть назву файлу: ";
	getline(cin, namef);
	cout << endl;

	int d;
	string nameg= "text_chang_file";
	do
	{
		cout << "1-ввід даних " << endl;
		cout << "2-виведення даних" << endl;
		cout << "3-перерахунок грошей" << endl;
		cout << "4-виведення змінених даних " << endl;
		cout << "0-EXID" << endl;
		cin >> d;
		switch (d)
		{
		case 1:
			input_file(namef);
			break;
		case 2:
			print_file(namef);
			break;
		case 3:
			recalculate_money(namef, nameg);
			break;
		case 4:
			print_change_money(nameg);
			break;
		case 0:
			exit(1);
		}
	} while (d!=0);
}
void print_change_money(const string gname)
{
	ifstream file(gname, ios::in);
	if (!file.is_open())
	{
		cout << "файл не відкрився ";
		return;
	}
	int count = 0;
	string str;
	char ch[20];
	while (!file.eof())
	{
		getline(file,str);//визначаємо кількість рядків в файлі
		count += 1;
	}
	file.close();
	file.open(gname, ios::in);
	int num = 1;
	cout << "===============================================================================" << endl;
	cout << "| № |  Назва фірми     |  Назва товару  | Вартість товару $ |  Ціна в гривнях  | " << endl;
	cout << "-------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < count /4; i++)
	{
		cout << "|" << setw(2) << num++ << setw(2) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(9) << ch << setw(10) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(9) << ch << setw(8) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(10) << ch << setw(10) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(9) << ch << setw(10) << "|" << endl;
	}


	cout << "===============================================================================" << endl;

}
void recalculate_money(const string fname, const string gname)
{
	ofstream gfile(gname, ios::out);
	ifstream ffile(fname, ios::in);	
	if (!gfile.is_open())
	{
		cout << "файл "<<gname<<"< не відкрився ";
		return;
	}
	if (!ffile.is_open())
	{
		cout << "файл " << fname << "< не відкрився ";
		return;
	}
	
	//char str[40];
	//char str2[40];
	double g;
	string str, str2;
	cin.get();
	cin.sync();
	while (!ffile.eof())
	{
		//cin.get();
		
		
		getline(ffile, str);
		gfile << str << endl;

		getline(ffile, str2);
		gfile << str2 << endl;
		
		ffile >> g;
		gfile << g << endl << g*27.41 <<endl;

	}
}
void print_file(const string fname)
{
	ifstream file(fname, ios::in);
	if (!file.is_open())
	{
		cout << "файл не відкрився ";
		return;
	}
	
	int count = 0;
	string str;
	char ch[20];
	cout << "============================================================" << endl;
	cout << "| № |  Назва фірми     |  Назва товару  | Вартість товару $ | " << endl;
	cout << "------------------------------------------------------------" << endl;
	while (!file.eof())
	{
		getline(file,str);//визначаємо кількість рядків в файлі
		count ++;
	}
	file.close();
	file.open(fname, ios::in);

	int num = 1;

	cin.get();
	cin.sync();
	for (int i = 0; i < count/3; i++)
	{
		cout << "|" << setw(2) << num++ << setw(2) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(9) << ch << setw(10) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(9) << ch << setw(8) << "|";

		file.getline(ch, sizeof(ch));
		cout << setw(10) << ch << setw(10) << "|"<<endl;

	}
	cout << "============================================================" << endl;
}
void input_file(const string fname)
{
	Firm firm;
	ofstream file(fname, ios::out);
	if (!file.is_open())
	{
		cout << "файл не відкрився ";
		return;
	}
	string str;

	cin.get();
	cin.sync();
	do
	{
		cout << "Введіть назву фірми: "; getline(cin,firm.name_firm);
		file << firm.name_firm << endl;;

		cout << "Введіть надзву товару: "; getline(cin, firm.name_item);
		file << firm.name_item<<endl;

		cout << "Введіть ціну товару в $: "; cin >> firm.price;
		file << firm.price<<endl;

		cin.get();
		cout << "Якщо ви хочете продовжити то введіть yes, якщо ні no : " << endl;
		getline(cin, str);

	} while (str=="yes"||str=="Yes");
	cout << endl;
}
//
//             ____________
//            /   _    _   \
//           /    *    *    \
//           |      __      |
//           |              |
//           |______________|
//           ||||||||||||||||
//           \||||||||||||||/
//            \\\\\\////////