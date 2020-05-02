#include<iostream>
#include<stdio.h>
using namespace std;

const int max = 1000;

//cau truc cua stack
typedef struct tagStack{
	int S[max];
	int top;
		}Stack;

//khoi tao stack
void CreateStack(Stack &st){
	st.top=-1;
}

// kiem tra ngan xep rong
int IsEmpty(Stack st){
	if(st.top==-1)
		return 1;
	else
		return 0;
}

//kiem tra ngan xep day
int IsFull(Stack st){
	if(st.top>max)
		return 1;
	else
		return 0;
}

//them mot phan tu x vao stack
int Push(Stack&st, int x){
	if(IsFull(st)==0) //neu stack chua full
	{
		st.top++; //tang dinh len 1
		st.S[st.top]=x; //gan gia tri x cho dinh
		return 1;  //them thanh cong
	}
	else 
		return 0;  //them that bai
}

//lay mot phan tu ra khoi stack 
int Pop(Stack &st, int &x){
	if(IsEmpty(st)==0)	//neu stack rong
	{
		x=st.S[st.top]; //lay gia tri dinh cho vao x
		st.top--; //giam dinh di 1
		return 1;
	}
	else
		return 0;
}

int main(){
	Stack st;
	int x,result,i;
	CreateStack(st);
	for(i=2;i<=5;i++)
		Push(st,i);
	result=Pop(st,x);
	if(result==1)
	cout<<"gia tri lay duoc tu stack la "<<x;
	}

