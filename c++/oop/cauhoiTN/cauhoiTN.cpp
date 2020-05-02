
#include "cauhoiTN.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

void cauhoiTN::tao(int n,char name[100])
{
	cauhoiTN QS;
	int i = 1;
	string ten;
	ten = name;
	fstream f(ten+".txt",ios::out);
	if (f.fail())
	{
		cout << " cannot create this file";
		return;
	}
	while (i <= n)
	{
		cout << "nhap cau hoi : ";
		if (i == 1)
		{
			gets_s(QS.cauhoi, sizeof(QS.cauhoi));
		}
		gets_s(QS.cauhoi, sizeof(QS.cauhoi));
		f << QS.cauhoi << endl;
		cout << "nhap cau A : ";
		gets_s(QS.A, sizeof(QS.A));
		cout << "nhap cau B : ";
		gets_s(QS.B, sizeof(QS.B));
		cout << "nhap dap an (A/B): ";
		gets_s(QS.dapan, sizeof(QS.dapan));

		f << QS.A << endl;
		f << QS.B << endl;
		f << QS.dapan << endl;
		i++;
	}
	f.close();

};
void cauhoiTN::them(int n, char name[100])
{
	cauhoiTN QS;
	string ten;
	ten = name;
	int i = 1;
	ofstream f;
	f.open(ten + ".txt",ios::out|ios::app);
	if (f.fail())
	{
		cout << " cannot create this file!!!";
		return;
	}
	while (i <= n)
	{
		cout << "nhap cau hoi : ";
		if (i == 1)
		{
			gets_s( QS.cauhoi, sizeof(QS.cauhoi));
		}
		gets_s(QS.cauhoi, sizeof(QS.cauhoi));
		f << QS.cauhoi << endl;
		cout << "nhap cau A : ";
		gets_s(QS.A, sizeof(QS.A));
		cout << "nhap cau B : ";
		gets_s(QS.B, sizeof(QS.B));
		cout << "nhap dap an (A/B): ";
		gets_s(QS.dapan, sizeof(QS.dapan));

		f << QS.A << endl;
		f << QS.B << endl;
		f << QS.dapan << endl;
		i++;
	}
	f.close();
};
void cauhoiTN::xuat(char name[100],int g)
{
	string ten;
	ten = name;
	ifstream f(ten+ ".txt" ,ios::out);
	if (f.fail())
	{
		cout << " cannot open this file";
		system("pause");
		return;
	}
	cauhoiTN QS;
	for(int i=1;i<=g;i++)
	{
		f.getline(QS.cauhoi, sizeof(QS.cauhoi));
		cout << "cau hoi : " <<QS.cauhoi << endl;
		f.getline(QS.A, sizeof(QS.A));
		cout << "dap an A :"<<QS.A << endl;
		f.getline(QS.B, sizeof(QS.B));
		cout << "dap an B :" << QS.B << endl;
		f.getline(QS.dapan, sizeof(QS.dapan));
		cout << "cau tra loi : " << QS.dapan << endl;
		cout << endl;
		
	}
	f.close();
};
int cauhoiTN::luu(char from[100], char to[100])
{
	string name2;
	name2 = to;
	fstream e(name2, ios::out);
	if (e.fail())
	{
		cout << " cannot create this file";
		system("pause");
		return 0;
	}
	ifstream f;
	string name;
	name = from;
	f.open(name + ".txt");
	if (f.fail())
	{
		cout << " cannot oppen this file";
		system("pause");
		return 0;
	}
	
	int i = 1;
	while (!f.eof())
	{
			char a[100];
			f.getline(a, sizeof(a));
			e << a << endl;
			i++;
	}
	f.close();
	e.close();
	return i;
}
int cauhoiTN::kiemtra(char name[100])
{
	string ten;
	ten = name;
	ifstream f(ten+".txt",ios::out);
	if (f.fail())
	{
		cout << " cannot open this file";
		return -1;
	}
	cauhoiTN QS;
	int e = 0;
	while(!f.eof())
	{
		string a;
		f.getline(QS.cauhoi, sizeof(QS.cauhoi));
		f.getline(QS.A, sizeof(QS.A));
		f.getline(QS.B, sizeof(QS.B));
		f.getline(QS.dapan, sizeof(QS.dapan));
		cout << "cau hoi : "<<QS.cauhoi << endl;
		cout << "A: "<<QS.A << endl;
		cout << "B: "<<QS.B << endl;
		cout << "nhap dap an (A/B) : ";
		cin >> a;
		if (a == QS.dapan)
		{
			cout << "dap an dung !!!";
			e++;
		}
		else
		{
			cout << "sai roi !!!";
		}
	}
	f.close();
	return e;
};
bool cauhoiTN::test(char name[100], int n, int m)
{
	cauhoiTN QS;
	string ten, cauhoi1,cauhoi2;
	ten = name;
	ifstream f(ten + ".txt", ios::out);
	for (int i = 1; i <= m; i++)
	{
		f.getline(QS.cauhoi, sizeof(QS.cauhoi));
		f.getline(QS.A, sizeof(QS.A));
		f.getline(QS.B, sizeof(QS.B));
		f.getline(QS.dapan, sizeof(QS.dapan));
		if (i == n)
		{
			cauhoi1 = QS.cauhoi;
		}
		if (i == m)
		{
			cauhoi2 = QS.cauhoi;
		}
	}
	if (cauhoi1 == cauhoi2)
		return true;
	else
		return false;
}
