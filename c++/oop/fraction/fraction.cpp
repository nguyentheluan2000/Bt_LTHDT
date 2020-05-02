#include<iostream>
#include"fraction.h"
using namespace std;


fraction::fraction(int _numerator, int _demoninator)
{
	this->numerator = _numerator;
	this->demoninator = _demoninator;
}
int area(fraction _area){
	return _area.numerator * _area.demoninator;
}
fraction::get_numerator() const{
	return numerator;
}
fraction::get_demoninator() const{
	return demoninator;
}
 void fraction::set_fraction() {
	int _numerator,_demoninator;
	cin>>_numerator>>_demoninator;
	numerator=_numerator;
	demoninator=_demoninator;
}
int main()
{
	
	fraction a;
	cout<<"Enter numerator and demoninator : "<<"\n";
	a.set_fraction(); // nhap tu va mau tu ban phim không dc
	cout<<"Numerator is: "<<a.get_numerator()<<"\n";
	cout<<"Demoninator is: "<<a.get_demoninator()<<"\n";
	cout<<"Area is : "<< area(a)<<"\n";
	cout<<endl;
	cout<<"Fractions are assigned: "<<"\n";
	fraction b(7,8);
	cout<<"Numerator is: "<<b.get_numerator()<<"\n";
	cout<<"Demoninator is: "<<b.get_demoninator()<<"\n";
	cout<<"Area is : "<< area(b)<<"\n";
	system("pause");
	return 0;
}

