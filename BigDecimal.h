#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>

class BigDecimal {
private:
	char* wrt; //value
	bool sign;
	int size;
public:
	BigDecimal();
	BigDecimal(const int &number);
	BigDecimal(const char* number);
	BigDecimal(const BigDecimal &DL);
	~BigDecimal();

	//friendly functions
	friend BigDecimal add(const BigDecimal & a, const BigDecimal & b);
	friend BigDecimal substract(const BigDecimal & a, const BigDecimal & b);
	friend bool compare(const BigDecimal & a, const BigDecimal & b);
	friend BigDecimal get_bigger(const BigDecimal & a, const BigDecimal & b);
	friend BigDecimal absl(const BigDecimal & a);
	void from_str(const char * number);
	
	//setters for sign and value
	void set_sign(bool &b)
	{
		sign = b;
	}
	void set_wrt(char* str)
	{	
		if(wrt)
			delete[] wrt;
		
		wrt = str;
		size= strlen(wrt)+1;
	}

	//operators
	BigDecimal operator !();
	bool operator ==(const BigDecimal & a);
	BigDecimal & operator =(const BigDecimal & a);
	BigDecimal operator+(const BigDecimal & a);
	BigDecimal operator-(const BigDecimal & a);
	BigDecimal operator-();
	BigDecimal & operator +=(const BigDecimal & a);
	BigDecimal & operator -=(const BigDecimal & a);
	BigDecimal operator *(const BigDecimal & a);
	BigDecimal operator /(const BigDecimal & a);
	bool operator <(const BigDecimal & a);
	bool operator >(const BigDecimal & a);
	bool operator <=(const BigDecimal & a);
	bool operator >=(const BigDecimal & a);
	BigDecimal & operator *=(const BigDecimal & a);
	BigDecimal & operator /=(const BigDecimal & a);
	bool operator !=(const BigDecimal & a);
	friend std::ostream& operator<<(std::ostream&s, const BigDecimal & a);
	friend std::istream& operator>>(std::istream & s, BigDecimal &a);
	friend char* strrev2( char* s);
};
