#include<iostream>
using namespace std;

int main(){
	char s[]="programming";  // 10 ki tu
	cout<<"so ki tu xuat ra gom 1 ki tu la: ";
	for(int i=0; i<10; i++)
	{
		cout<<s[i]<<"\t";
	}
	int i=0;
	while( i < 10) 
	{
		int j=1;
		for( ;j< 10; j++)
	{
		cout<<s[i]<<s[j]<<"\t";
	}
		i++;
		j++;
	}
}
