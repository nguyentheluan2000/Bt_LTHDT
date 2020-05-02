#pragma once
class cauhoiTN
{	
public:
	char cauhoi[100];
	char A[100];
	char B[100];
	char dapan[100];
	void tao(int n,char name[100]);
	void them(int n, char name[100]);
	void xuat(char name[100],int temp);
	int luu(char from[100], char to[100]);
	int kiemtra(char name[100]);
	bool test(char name[100], int n, int m);//kiem tra 2 cau bat kì co trung cau hoi voi nhau khong 
};

