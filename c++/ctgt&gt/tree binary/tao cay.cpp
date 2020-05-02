#include<iostream>
using namespace std;

struct Node{			//cau truc cua nut
	int key;
	Node*left;
	Node*right;
};
typedef struct Node*TREE; //khoi tao cay
void Create(TREE&test){  // khoi tao cay rong
	test=NULL;
}
Node*CreateNode(int x){ // tao nut
	Node*data=new Node[1];
	if(data==NULL)
	return NULL; //bo nho full
	data->key=x;
	data->left=data->right=NULL;
	return data;
}
int Put(TREE& test, int x){ // them nut vao cay
	if(test!=NULL)//chua co cho de them nut
	{
		if(test->key==x) //cac nut khong duoc co key giong nhau
			return 0;
		if(test->key > x) 
			return Put(test->left,x);//them x vao nut ben trai
		else 
			return Put(test->right,x);//them x vao nut ben phai
	}
	//da co cho de them nut
	test=CreateNode(x);
	return 1;
}
//tim nut co khoa x (khong dung de quy)
Node*Search(TREE t,int x){
	Node*p=t;
	while(p!=NULL){
		if(x==p->key)
			return p; //tim duoc nut p co khoa x
		if(x<p->key)
			p=p->left; //tim tiep o nut ben trai
		if(x>p->key)
			p=p->right; //tim tiep o nut ben phai
	}
}
//tim phan tu thay the (truong hop co day du 2 cay con)
void thaythe(TREE &nut, TREE &t){  //t la nut ben phai cua 'nut' can thay the
	if(t->left!=NULL) // t van con co nut ben trai
		thaythe(nut,t->left);
	else // t khong con nut nao ben trai
	{
		nut->key=t->key; // thay the nut bang key -nut nho nhat ben phai
		nut=t;
		t=t->right;
	}
}
// xoa nut x khoi cay
void DelNode(TREE &test,int x){
	if(test==NULL)
		cout<<"khong tim thay nut can xoa : "<<"\n";
	else{
		if(test->key<x)
			DelNode(test->right,x);
			else{
				if(test->key>x)
					DelNode(test->left,x);
				else{
					Node *p;
					p=test;
					if(test->left==NULL)
						test=test->right;
					else{
						if(test->right==NULL)
							test=test->left;
						else
							thaythe(p,test->right);
					}
				delete p;
				}
			}
	}	
}



int main(){
	TREE test,t;
	int i,n,x;
	Create(test);
	cout<<"nhap so luong cac nut trong cay :";
	cin>>n;
	cout<<"nhap vao cac nut cho cay : \n";
	for(i=1;i<=n;i++){
		cin>>x;
		Put(test,x);
	}
	cout<<"nhap 1 gia tri ma ban muon tim kiem : \n";
	cin>>x;
	t=Search(test,x);
	if(t!=NULL)
		cout<<"tim thay x = "<<x<<" trong cay \n";
	else
		cout<<"khong tim thay x = "<<x<<"trong cay \n";
	cout<<"nhap 1 gia tri can xoa :\n";
	cin>>x;
	DelNode(test,x);
		
	
}
