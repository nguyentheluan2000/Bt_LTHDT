#include<iostream>
using namespace std;

void cap_dao(int n, int A[6]){
	for(int i=0 ; i < n ; i++)			// n times				

		for ( int j= i+1 ; j<n; j++)			// n*(n-1) times
				{
					if(A[i] > A[j])
						cout<<A[i]<<A[j]<<"\n";  // n*(n-1)*2 times
				}
}   //T = n(n-1)*2
	// => O(n*n)

int main(){
	int A[]={1,3,5,2,4,6},n=sizeof(A)/sizeof(int);
	cap_dao(n,A);
}
