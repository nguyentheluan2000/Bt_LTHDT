#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

int main(){
	srand(time(NULL));
	int so_may = 1 + rand() %100;  // chay ngau nhien tu 1 den 100
	cout<<" Tro Choi Doan So"<<"\n";
	cout<<" So trong khoang (1,100),... moi ban doan"<<"\n";
	int so_doan,so_lan=0;
	cout<<" Nhap so ban doan: ";
	cin>>so_doan;
	do	{
	if(so_doan == so_may)
		{
			cout<<"correctly"<<"\n";
			break;	
		}
	else if (so_doan != so_may)
		cout<<"wrong!!"<<"\n";
	cout<<"wrong"<<so_lan +1 <<"st time"<<"\n";
	so_lan++;
	} while(so_lan<7);
	cout<<" so cua may la : "<<so_may;
	return 0;
}
