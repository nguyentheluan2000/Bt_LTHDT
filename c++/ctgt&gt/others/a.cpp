#include<iostream>
using namespace std;
typedef struct node{
	int data;
	node * next;
};

typedef struct{
	node* head,*tail;
}list;

void Creat_a_new_list(list &l)
{
	l.head=l.tail=NULL;
}

node *creat_node()
{
	node *a= new node ;
	cin>>a->data;
	a->next=NULL;
	return a;
}

void insert_tail(list &l,node *Data)
{
	if(l.head==NULL) l.head=l.tail=Data;
	else 
	{
		l.tail->next=Data;
		l.tail=Data;
	}
}
void print(list l)
{
	node *a=l.head;
	while(a!=NULL)
	{
		cout<<a->data<<"	";
		a=a->next;
	}
	cout<<endl;
}
main()
{
	list L;
	node *a;
	Creat_a_new_list(L);
	for(int i=0;i<5;i++)
	{
		a=creat_node();
		insert_head(L,a);
	}
	print(L);
}
