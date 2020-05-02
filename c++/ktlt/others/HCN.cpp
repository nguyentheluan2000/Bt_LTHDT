#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cout<<"nhap n";
	cin>>n;
	cout<<"nhap m";
	cin>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
		if(i==1||i==n||j==1||j==m)
			cout<<"1";
		else
		cout<<"0";
		cout<<endl;
	}
	
}
