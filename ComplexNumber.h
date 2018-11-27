#pragma once
#include <iostream>
#include "BigDecimal.h"
#include "Utility.h"
#include <stdio.h>
#include <string>
#include<cstdio>
#include<cstdlib>
#include "ComplexNumber.h"


class ComplexNumber{
private:
		BigDecimal real;
		BigDecimal imaginary;
public:
		ComplexNumber();
		ComplexNumber(const int & a,const int & b);
		ComplexNumber(const char* a, const char* b);
		ComplexNumber(const BigDecimal & a, const BigDecimal b);
		~ComplexNumber();
		
	//operatory	
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
	
};