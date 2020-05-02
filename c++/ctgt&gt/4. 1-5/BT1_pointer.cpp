#include<iostream>
using namespace std;
typedef struct Student{
	int Id;
	char Name[31];
	int  year;
	float marks;//marks avaregae in the Student
	struct Student * Next;
}Stu;
struct List{
	Stu *Top;// Pointer Top
	Stu *Pot;// Pointer Pop
};
void CreatANewList(List &L)
{
	L.Top=L.Pot=NULL;	
}
Stu* CreatSTU()//Creat a node  Student 
{
	Stu* STU;//creat a new varriable Student
	STU= new Stu;
	cout<<"Enter-id-Student: ";
	cin>>STU->Id;
	cin.ignore();
	cout<<"Enter-Name-Student: ";
	cin.getline(STU->Name,31);
	cout<<"Enter-Year-Born: ";
	cin>>STU->year;
	cout<<"Enter-marks-avarage: ";
	cin>>STU->marks;
	STU->Next=NULL;
	return STU;
}
void InsertPop(List &L,Stu *x)
{
	if(L.Top==NULL)
	{
		L.Pot=L.Top=x;
	}
	else{
		L.Pot->Next=x;
		L.Pot=x;
	}
}
void Print(List L)
{
	int i=1;	Stu *x;
	x=L.Top;
	while(x!=NULL)
	{
		cout<<"\t===Student"<<i<<"===\n";
		cout<<"ID: "<<x->Id<<endl;
		cout<<"Name :"<<x->Name<<endl;
		cout<<"Year Born: "<<x->year<<endl;
		cout<<"Marks Avarage: "<<x->marks<<endl;
		x=x->Next;
		i++;
	}
}
void InsertHead(List&L, Stu *Data)
{
	if(L.Top==NULL)
	{
		L.Pot=L.Top=NULL;
	}
	else{
		Data->Next=L.Top;
		L.Top=Data;
	}
}
void SortListById(List &L)
{
	Stu *a,*b,*pa,*pb,*na;
	a=L.Top;
	b=a->Next;
	while(b!=NULL)//case 1:a stand head
	{
		if(a->Next==b)
		{
			if(a->Id>b->Id)
			{
				a->Next=b->Next;
				b->Next=a;
				L.Top=b;
				a	=L.Top;
				b=a->Next;
			}
			na=pb=b;
		}
		else
		{
			if(a->Id>b->Id)
			{
				a->Next=b->Next;
				b->Next=na;
				pb->Next=a;
				L.Top=b;
				a=b;
				b=pb->Next;
			}
			pb=pb->Next;
		}
		b=b->Next;	
	}
	a=a->Next;
	pa=L.Top;
	while(a!=NULL)
	{
		b=a->Next;
		while(b!=NULL)
		{
			if(a->Next==b)
			{
				if(a->Id>b->Id)
				{
					a->Next=b->Next;
					b->Next=a;
					pa->Next=b;
					a=b;
					b=a->Next;
				}
				pb=na=a->Next;
 			}else
 			{
				if(a->Id>b->Id)
				{
					a->Next=b->Next;
					b->Next=na;
					pb->Next=a;
					pa->Next=b;
					a=b;
					b=pb->Next;
				}
				pb=pb->Next;
			}	
			b=b->Next;
		}
		pa=pa->Next;
		a=a->Next;
	}
}
int Delete(List &L,int y)
{
	Stu *a,*b;
	a=L.Top;
	if(a->Id==y)
	{
		L.Top=a->Next;
		delete a;
		return 1;
	}
	a=a->Next;
	b=L.Top;
	while(a!=NULL)
	{
		if(a->Id==y)
		{
			b->Next=a->Next;
			delete a;
			return 1;
		}
		a=a->Next;
		b=b->Next;
	}
}
void FindById(List L,int x)
{
	Stu *a;
	a=L.Top;
	int i=1;
	while (a!=NULL)
	{
		if(a->Id==x)
		{
			cout<<"\t===Student "<<x<<"==="<<endl;
			cout<<"ID: "<<a->Id<<endl;
			cout<<"Name: "<<a->Name<<endl;	
			cout<<"Years born: "<<a->year<<endl;
			cout<<"Mark avareage: "<<a->marks<<endl;
		}
		a=a->Next;
		i++;
	}
}
void InsertData(List& L,Stu *Data)
{
	if(Data->Id<L.Top->Id)
	{
		Data->Next=L.Top;
		L.Top=Data;
		return ;
	}
	Stu*a,*pa;
	pa=L.Top;
	a=pa->Next;
	while(a!=NULL)
	{
		if(Data->Id<a->Id)
		{
			pa->Next=Data;
			Data->Next=a;
			return ;
		}
		a=a->Next;
		pa=pa->Next;
	}
	pa->Next=Data;
	L.Pot=Data;
}
main(){
	Stu *a;	int n;	List L;
	CreatANewList(L);
	cout<<"Enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"\t===Student "<<i+1<<"===\n";
		a=CreatSTU();
		InsertPop(L,a);
	}
	system("cls");
	Print(L);
	SortListById(L);
	Print(L);
	int y;
	cout<<"Enter ID to Delete: ";cin>>y;
	Delete(L,y);
	Print(L);
	cout<<"Enter-ID-Student: ";
	cin>>y;
	FindById(L,y);
	cout<<"Enter-Number-Insert-Student: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		a=CreatSTU();
		InsertData(L,a);
	}
	Print(L);
}
