#pragma once
class CRectangle{
	private :
		int width, height;
	public :
		void set_Width(int _width);
		int get_Width() const;
		void set_Height(int _height);
		int get_Height() const;
		int area();
};	
