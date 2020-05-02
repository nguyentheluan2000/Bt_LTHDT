#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;
int main()
{
	srand(time(NULL)); // random
	int n;
	cout<< "nhap so phan tu mang : "<"\n";	
	cin>>n;
	int M[n];
	for(int i=0; i<n; i++)
	{
		M[i]=rand()%100;
	}
	cout<<"mang sau khi da nhap la : "<<"\n";
	for( int i=0; i<n; i++)
	{
		cout<<M[i]<<"\t";
	}
	cout<<"\n";
	//sort from min to max numbers
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
				if(M[i] > M[j])
				{
					int tam= M[i];
					M[i]=M[j];
					M[j]=tam;
				}
		}
	}
	// print after sorting
	cout<<"phan tu da sap xep la : "<<"\n";
	for(int i =0; i<n; i++){
		cout<<M[i]<<"\t";
	}
	cout<<"\n";
	int k, dem=0;
	cout<<"nhap so k: ";
	cin>>k;
	for(int i=0; i<n; i++){
		if(M[i]==k)
			dem++;
	}
	cout<<"so "<< k <<" xuat hien "<<dem<<" lan";
	
	return 0;
}
