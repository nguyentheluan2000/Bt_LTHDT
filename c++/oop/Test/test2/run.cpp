#include<iostream>
#include"trainee.cpp"
using namespace std;
main(){
	Trainee *t1, *t2;
	cout<< "total sum of trainees: "<<Trainee::getTotalTrainees()<<endl; //0
	t1 = new Trainee(1, "Luan vip"); // nhap 1 trainee
	cout<< "total sum of trainees: "<<Trainee::getTotalTrainees()<<endl; //1
	t2 = new Trainee(2, "Luan pro"); // nhap them 1 trainee
	cout<< "total sum of trainees: "<<Trainee::getTotalTrainees()<<endl; //2
	delete t1;
	cout<< "total sum of trainees: "<<Trainee::getTotalTrainees()<<endl;
	delete t2;
	cout<< "total sum of trainees: "<<Trainee::getTotalTrainees()<<endl;
	return 0;
}
