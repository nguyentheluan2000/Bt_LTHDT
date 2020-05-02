#include<iostream>
#include"rectangle.cpp"
using namespace std;

main(){
	CRectangle rect1(10,50);
	cout<< "S1= "<<rect1.area()<<endl;
	cout<<"===================="<<endl;
	CRectangle *rect2 = new CRectangle(20,30);
	cout<<"S2= "<<rect2->area()<<endl;
	cout<<"===================="<<endl;
	CRectangle rect3;
	rect3.set_Height(30);
	rect3.set_Width(40);
	cout<<"S3= "<<rect3.area()<<endl;
	return 0;
}
