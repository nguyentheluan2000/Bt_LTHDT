#include "rectangle.h"
CRectangle::CRectangle(int w , int h)
{
	width = w;
	height = h;
}
CRectangle::CRectangle(const CRectangle & r){
	width= r.width;
	height= r.height;
}
CRectangle::CRectangle(){
	height = 1;
	width  = 1;
}
int CRectangle::get_Height() const
{
	return height;
}
int CRectangle::get_Width() const
{
	return width;
}

void CRectangle::set_Height(int _height){
	height=_height;
}
void CRectangle::set_Width(int _width){
	width=_width;
}
int CRectangle::area(){
	return width * height;
}
