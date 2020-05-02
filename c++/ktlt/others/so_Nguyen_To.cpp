#include<iostream>
#include<stdio.h>
using namespace std;

void so_Nguyen_To(int n){
	int dem=0;
for(int i=2;i<n/2;i++)
{
	if(n%i==0)
	dem++;
	}	
if(dem==0||n==2||n==3){
cout<<n<<"la so nguyen to";
}

else if(dem!=0){
cout<<n<<"khong phai so nguyen to";
}
}

int main(){
	int n;
	cout<<"nhap so n: ";
	cin>>n;
	so_Nguyen_To(n);
}
