#pragma once
class fraction{
	private:
		int numerator;
		int demoninator;
	public:
		fraction(){};
		fraction(int,int);
		friend int area(fraction);
		get_numerator() const;
		get_demoninator() const;
		void set_fraction();
	//	~fraction();
};
