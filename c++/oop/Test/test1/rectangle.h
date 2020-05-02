#pragma once

class CRectangle{
	private:
		int width, height;
	public:
		CRectangle(); //1
		CRectangle(int , int); //2,  hai phuong thuc khoi tao doi tuong
		void set_Width(int _width);
		int get_Width() const;
		void set_Height(int _height);
		int get_Height() const;
		int area();
};
