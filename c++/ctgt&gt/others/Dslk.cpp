#include<iostream>
using namespace std;

//ctdl cua Node
struct SinhVien{
	char HoTen[33];
	int MSSV;
	SinhVien*tiep;
};

//ctdl cua danh sach lien ket
struct DanhSach{
	SinhVien *dau;
	SinhVien *cuoi;
	
};

//tao ham dslk don rong
void CreateList(DanhSach&DSSV){
	DSSV.dau=DSSV.cuoi=NULL;
}

//tao 1 ham Node moi
SinhVien*CreateNode(){
	SinhVien*x= new SinhVien[1];
	cout<<"nhap vao ma so sinh vien ";
	cin>>x->MSSV;
	cout<<"nhap vao ten sinh vien ";
	cin.ignore(1);
	cin.getline(x->HoTen,33);
	x->tiep=NULL;
	return x;
}

//chen dau 
void chendau(DanhSach&DSSV,SinhVien*x){
	if(DSSV.dau==NULL)
	{
		DSSV.dau=DSSV.cuoi=x;
	}
	else
	{
		x->tiep=DSSV.dau;
		DSSV.dau=x;
	}
}

//chen cuoi
void chencuoi(DanhSach&DSSV,SinhVien*x){
	if(DSSV.dau==NULL){
		DSSV.dau=DSSV.cuoi=x;
	}
	else
	{
		DSSV.cuoi->tiep=x;
		DSSV.cuoi=x;
	}
}

//chen phan tu data vao sau nut "q"
void InsertAfterQ(DanhSach&DSSV,SinhVien*data,SinhVien*q){
	if(q!=NULL){
	data->tiep=q->tiep;
	q->tiep=data;
	if(DSSV.cuoi==q)
	DSSV.cuoi=data;
	}
	else
	chendau(DSSV,data);
}

//ham duyet qua danh sach
void OutPut(DanhSach&DSSV)
{
	SinhVien*data;
	data=DSSV.dau;
	cout<<"Danh sach cac phan tu cua DSLK : \n";
	cout<<"Ma so \t Ho va ten : "<<"\n";
	while(data!=NULL){
		cout<<data->MSSV<<"\t"<<data->HoTen;
		data=data->tiep;
	}
}

//ham xoa phan tu khoi dslk
int RemoveX(DanhSach&DSSV,SinhVien *x){
	SinhVien *p;
	p = DSSV.dau;
	if(DSSV.dau==x){
		DSSV.dau=x->tiep;
		delete x;
			return 1;
	}
	while((p!=NULL)&&(p->tiep!=x)){  //tim p lien truoc x
		p=p->tiep;
	if(p==NULL)
		return 0;
	else{
		p->tiep=x->tiep;
		delete x;
			return 1;
	}
	}
}

int main(){
	DanhSach ds;
	CreateList(ds);
	int i,n;
	SinhVien*t;
	cout<<"nhap so luong sinh vien :"; cin>>n;
	for(int i=1; i<=n;i++){
		cout<<"sinh vien thu "<<i<<"\n";
		t=CreateNode();
		chendau(ds,t);
	}
	cout<<"\n============================\n";
	OutPut(ds);
	cout<<endl<<" chen them 1 sv vao cuoi danh sach :\n";
	t=CreateNode();
	chencuoi(ds,t);
	cout<<"\n============================\n";
	OutPut(ds);
	cout<<endl<<" chen them 1 sv vao sao phan tu thu nhat :\n";
	t=CreateNode();
	InsertAfterQ(ds,t,ds.dau);
	cout<<"\n============================\n";
	OutPut(ds);
	cout<<"\n============================\n";
	cout<<" xoa sv dau tien ra khoi danh sach :\n";
	RemoveX(ds,ds.dau);
	OutPut(ds);
}
