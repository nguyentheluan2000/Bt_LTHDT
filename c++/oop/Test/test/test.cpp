#include<iostream>
#include"test.h"
using namespace std;

int CRectangle::get_Height() const
{
	return height;
}

int CRectangle::get_Width() const   // phuong thuc get_width() nam trong phan vi lop
{
	return width;
}

void CRectangle::set_Height(int _height)
{
	height=_height;
}
void CRectangle::set_Width(int _width) //thanh vien du lieu "height" duoc phep truy cap 
{									  //truc tiep trong phuong thuc thanh vien set_height()
	width=_width;
}
int CRectangle::area()
{
	return width*height;	
}
