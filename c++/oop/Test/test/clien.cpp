#include<iostream>
#include"test.cpp"
using namespace std;
main(){
	CRectangle rect1;  // tao doi tuong rect
	CRectangle *rect2; // doi tuong là con tro
//	rect.height=2;
	rect1.set_Height(3);
	rect1.set_Width(4);
	cout<<"Height1: "<<rect1.get_Height()<<endl;
	cout<<"Width1: "<<rect1.get_Width()<<endl;
	cout<< "S1: "<<rect1.area()<<endl;
	cout<<"==========================================="<<endl;
	rect2= new CRectangle();
	rect2->set_Height(5);
	rect2->set_Width(6);
	cout<<"Height2: "<<rect2->get_Height()<<endl;
	cout<<"Width2: "<<rect2->get_Width()<<endl;
	cout<<"S2: "<<rect2->area()<<endl;
	return 0;
}
