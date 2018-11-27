#include <iostream>
#include "BigDecimal.h"
#include "Utility.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include "MyList.h"
#include "ComplexNumber.h"


ComplexNumber::ComplexNumber()
{
	real=BigDecimal;
	imaginary=BigDecimal;
}

ComplexNumber::ComplexNumber(const int & a,const int & b)
{
	real=BigDecimal(a);
	imaginary=BigDecimal(b);
}

ComplexNumber::ComplexNumber(const char* a, const char* b)
{
	real=BigDecimal(a);
	imaginary=BigDecimal(b);
}

ComplexNumber::ComplexNumber(const BigDecimal & a, const BigDecimal & b)
{
	real=a;
	imaginary=b;
}

ComplexNumber::~ComplexNumber()
{
	delete[] real.wrt;
	real.wrt = NULL;
	delete[] imaginary.wrt;
	imaginary.wrt = NULL;
}

ComplexNumber::ComplexNumber operator !()
{
	
}

bool ComplexNumber:: operator ==(const ComplexNumber & a)
{
	return (this->real==a.real && this->imaginary==a.imaginary);
}

ComplexNumber & ComplexNumber::operator=(const ComplexNumber & a)
{
	this->real=a.real;
	this->imaginary=a.imaginary;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber & a)
{
	return ComplexNumber(this->real+a.real,this->imaginary+a.imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber & a)
{
	return ComplexNumber(this->real-a.real,this->imaginary-a.imaginary);
}

ComplexNumber ComplexNumber::operator-()
{
	this->real.sign=-this->real.sign;
	this->imaginary.sign=-this->imaginary.sign;
	return *this;
}

ComplexNumber & ComplexNumber::operator +=(const ComplexNumber & a)
{
	this->real+=a.real;
	this->imaginary+=a.real;
	return *this;
}

ComplexNumber & operator -=(const ComplexNumber & a)
{
	this->real-=a.real;
	this->real-=a.real;
	return *this;
}

ComplexNumber ComplexNumber::operator *(const ComplexNumber & a)
{
	return ComplexNumber((this->real*a.real) - (this->imaginary*a.imaginary),(this->real*a.imaginary)+(a.real*this->imaginary);
}

ComplexNumber ComplexNumber::operator /(const ComplexNumber & a)
{
	return(ComplexNumber( ( ( (this->real*a.real) + ( this->imaginary*a.imaginary ) )/( ( a.imaginary*a.imaginary ) + ( a.real*a.real ) ) ) , ( ( ( this->imgainary*a.real )-( this->real*this.imaginary ) )/( ( a.real*a.real ) + ( a.imaginary*b.imaginary ) )  ) );
}

ComplexNumber & ComplexNumber::operator *=(const ComplexNumber & a)
{
	*this=*this*a;
	return *this;
}

BigDecimal & ComplexNumber::operator /=(const ComplexNumber & a)
{
	*this=*this/a;
	return *this;
}

bool ComplexNumber::operator !=(const ComplexNumber & a)
{
	return !(*this==a);
}
