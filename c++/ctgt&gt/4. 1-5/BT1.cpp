#include<iostream>
using namespace std;

struct student{
	int id;
	int year_birth;
	int score;
	char name[30];
	student*next;
	
};

struct Node{
	student*head;
	student*tail;
	
};
void create_List(Node&n){
	n.head=n.tail=NULL;
}

student*CreateNode(){
	student*x= new student;
	cout<<"Enter name of student : ";
	cin>>x->name;
	cout<<"Enter name of birth : ";
	cin>>x->year_birth;
	cout<<"Enter name of score : ";
	cin>>x->score;
	cout<<"Enter name of id-student : ";
	cin>>x->id;
	x->next=NULL;
	return x;
}

void insertTail(Node&n,student*x){
	if(n.head==NULL){
		n.head=n.tail=x;
	}
	else{
		n.tail->next=x;
		n.tail=x;
	}
}
void sortById(Node&n)			//false
{
	student *a, *b, *cache;
	a=n.head;
	b=a->next;
	while(a!=NULL)
	{	if(a->id>b->id)
		{
		a=cache;
		a=b;
		b=cache;
		}
	cout<<a->id<<" "<<a->name<<" "<<a->score<<" "<<a->year_birth<<"\n";	
	a=b;
	b=b->next;
	}
}
void findByID(Node&n){						//false
	student *a;
	int ID;
	a=n.head;
	cout<<"enter ID student: ";
	cin>>ID;
	while(a!=NULL){
		if(a->id==ID){
			cout<<a->id<<" "<<a->name<<" "<<a->score<<" "<<a->year_birth<<"\n";	
		}
	a=a->next;	
	}
}
	

void outPut(Node&n){
	student*data;
	data=n.head;
	cout<<"List of students: \n";
	while(data!=NULL){
		cout<<data->id<<" "<<data->name<<" "<<data->score<<" "<<data->year_birth<<"\n";
		data=data->next;
	}
	
}




int main(){
	Node p;
	create_List(p);
	student*a;
	int n;
	cout<<"enter the numbers of student: ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cout<<"enter the student of number "<<i<<"\n";
		a=CreateNode();
	cout<<"\n";
		insertTail(p,a);
		}
	outPut(p);
	
	cout<<"sort by ID: "<<"\n";
	sortById(p);
	findByID(p);
	
}
