#include<iostream>
using namespace std;

struct Decimal{
	int num;
	Decimal *next;
};
struct Node{
	Decimal *head;
	Decimal *tail;
};

void create_List(Node&p){
	p.head=p.tail=NULL;
}
Decimal *create_Node(){
	int i=0;
	Decimal *n= new Decimal;

	cin>>n->num;
	n->next=NULL;
	return n;
}
void insert_Tail(Node&p,Decimal *data){
	if(p.head==NULL){
		p.head=p.tail=data;
	}
	else
	{
		p.tail->next=data;
		p.tail=data;
	}
	
	
}
void output(Node&p){
	Decimal *data;
	data=p.head;
	cout<<"this is the number,you need: ";
	while(data!=NULL)
	{
		cout<<data->num<<"\t";
		data=data->next;
	}
}
main(){
	Node n;
	create_List(n);
	Decimal *a;
	int b;
	cout<<"enter a mount of numbers : ";
	cin>>b;
	for(int i=0;i<b;i++){
	cout<<"enter the decimal number "<<i+1<<" is : ";
	a=create_Node();
	insert_Tail(n,a);
	}
	output(n);
}
