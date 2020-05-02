
#include"cauhoiTN.cpp"
#include <iostream>
#include<string>
#include<fstream>
using namespace std;
void menu()
{
	int luachon;
	char name[100];
	char name2[100];
	cauhoiTN QS;
	int n = 0, m = 0,temp = 0;
	do
	{
		
		do
		{
			system("cls");
			cout << "\n\n\t\t===============MENU=============";
			cout << "\n\t 1.Tao mot đe thi trac nghiem moi ";
			cout << "\n\t 2.Them mot cau hoi moi tu ban phim vao đe thi hien hanh ";
			cout << "\n\t 3.In danh sach cau hoi hien đang co trong đe thi ";
			cout << "\n\t 4.Luu danh sach cau hoi vao file *.TTN";
			cout << "\n\t 5.Đoc noi dung mot file *.TTN vao bo nho ";
			cout << "\n\t 6.Cho thi và tinh so cau tra loi dung cua thi sinh ";
			cout << "\n\t 7.kiem tra 2 cau bat ki co giong nhau khong ";
			cout << "\n\t 8.Exit ";
			cout << "\n\n\t\t================end=============" << endl;
			cout << "nhap lua chon ban muon : ";
			cin >> luachon;
			if (luachon < 0 || luachon > 9)
			{
				cout << " lua chon sai !!! nhap lai ";
				system("pause");
			}
		} while (luachon < 0 || luachon > 9);

		if (luachon == 1)
		{
			cout << "nhap ten muon tao : ";
			cin.getline(name, sizeof(name));
			cin.getline(name, sizeof(name));
			cout << "nhap so luong cau : ";
			cin >> n;
			
			QS.tao(n, name);
		}
		if (luachon == 2)
		{
			

			cout << "nhap so cau muon them : ";
			cin >> m;
			QS.them(m, name);

		}
		if (luachon == 3)
		{
			int g = m + n;
			QS.xuat(name,g);
			system("pause");
		}
		if (luachon == 4)
		{
			cout << "nhap ten file ban muon luu ( *.TTN ) :  ";
			cin.getline(name2, sizeof(name2));
			cin.getline(name2, sizeof(name2));
			temp = QS.luu(name, name2);
			if (temp > 0)
			{
				cout << "luu thanh cong vao file " << name2;
				system("pause");
			}
			else
			{
				cout << "luu khong thanh cong ";
				system("pause");
			}
			
		}
		if (luachon == 5)
		{
			QS.xuat(name2,temp);
		}
		if (luachon == 6)
		{
			cout<<"Ket qua : "<<QS.kiemtra(name);
			system("pause");
		}
		if (luachon == 7)
		{
			int cau1,cau2;
				
				do
				{
					cout << "nhap so 2 cau can kiem tra : ";
					cin >> cau1;
					cin >> cau2;
					if (cau1 > (n+m) || cau2 > (n+m))
					{
						cout << "cau khong hop le!!!";
					}
				} while (cau1 > (n + m) || cau2 > (n + m));
				if (cau1 > cau2)
				{
					swap(cau1, cau2);
				}
				bool flag = QS.test(name, cau1, cau2);
				if (flag == true)
				{
					cout << "2 cau nay giong nhau !!";
					system("pause");
				}
				else
				{
					cout << "2 cau nay khong giong nhau !!";
					system("pause");
				}

		}
		if (luachon == 8)
			return;
	}
	while (true);
}
int main()
{

	menu();
}
