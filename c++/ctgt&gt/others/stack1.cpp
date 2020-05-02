#include<iostream>
using namespace std;

typedef struct node{
	int item;
	node *next;
}*stacknode;
typedef struct stack{
	stacknode top;
}stack;
int CheckEmpty(stack &s){
	return s.top==NULL;
}
void Push(stack &s, int x){
	stacknode p = new node[1];
	p->item=x;
	p->next=s.top;
	s.top=p;
}
int Pop(stack &s){
	stacknode p;
	int x;
	if(CheckEmpty(s))
		cout<<"\n Danh sach rong : ";
	else{
		p=s.top;
		x=p->item;
		s.top=s.top->next;
		delete p;
		return x;
	}
}

int main(){
	stack s;
	s.top=NULL;
	CheckEmpty(s);
	for(int x=1;x<99;x+=2)
		Push(s,x);
	int t=Pop(s);
	cout<<"Phan tu lay ra duoc : "<<t;
}
