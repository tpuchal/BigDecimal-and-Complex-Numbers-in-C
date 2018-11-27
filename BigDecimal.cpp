#include <iostream>
#include "BigDecimal.h"
#include "Utility.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include "MyList.h"


BigDecimal::BigDecimal()
{
	wrt = new char[2];
	wrt[0] = '0';
	wrt[1] = '\0';
	sign = true;
	size=2;
}
BigDecimal::BigDecimal(const int &number) 
{

	std::stringstream ss;
	std::string s;
	ss << number;
	ss >> s;
	if (number < 0)
	{
		sign = false;
		s.erase(0,1);
		size=s.size()+1;
		wrt = new char[size];
		std::copy(s.begin(), s.end(), wrt);
		wrt[size-1] = '\0';
	}
	else 
	{
		sign = true;
		wrt = new char[s.size() + 1];
		std::copy(s.begin(), s.end(), wrt);
		size=s.size()+1;
		wrt[size-1] = '\0';
	}
}
BigDecimal::BigDecimal(const char * number)
{
	wrt=NULL;
	from_str(number);
}
BigDecimal::BigDecimal(const BigDecimal & BD)
{		
	size=BD.size;
	wrt = new char[strlen(BD.wrt)+1];
	strcpy(wrt,BD.wrt);
	sign = BD.sign;
}
BigDecimal::~BigDecimal()
{
	delete[] wrt;
	wrt = NULL;
}

void BigDecimal::from_str(const char * number)
{
	if(wrt)
		delete[] wrt;
	
	sign = true;
	std::string str(number);
	if (str == "")
	{	
		wrt = new char[2];
		wrt[0] = '0';
		wrt[1] = '\0';
		sign = true;
		size=2;
	}
	if (str.at(0) == '0')
	{
		wrt = new char[2];
		wrt[0] = '0';
		wrt[1] = '\0';
		sign = true;
		size=2;
	}
	if (str.at(0) == '-')
	{
		str.erase(0,1);
		sign = false;
	}
	wrt = new char[str.length() + 1];
	memcpy(wrt, str.c_str(), str.size());
	size=str.length()+1;
	wrt[size-1] = '\0';
}
	

BigDecimal BigDecimal::operator !()
{
	if (*this == 0)
		return BigDecimal("1");
	else
	{
		BigDecimal l((*this) * !(*this-BigDecimal("1")));		
		return l;
	}
}

bool BigDecimal::operator==(const BigDecimal & a)
{
	return strcmp(this->wrt,a.wrt)==0 && this->sign == a.sign;
}

BigDecimal & BigDecimal::operator=(const BigDecimal & a)
{
	if (this == &a)
		return *this;
	
	delete[] this->wrt;
	this->wrt=dup(a.wrt);
	this->sign = a.sign;
	this->size=a.size;
	return *this;
}

BigDecimal BigDecimal::operator+(const BigDecimal & a)
{
	if (this->sign == a.sign)
		return add(*this, a);
	return substract(*this, a);
}

BigDecimal BigDecimal::operator-(const BigDecimal & a)
{
	if (this->sign == a.sign)
		return substract(*this, a);
	return(add(*this, a));

}
BigDecimal BigDecimal::operator-()
{
	this->sign=-this->sign;
	return *this;
}
BigDecimal & BigDecimal::operator+=(const BigDecimal & a)
{
	*this = *this + a;
	return *this;
}

BigDecimal & BigDecimal::operator-=(const BigDecimal & a)
{
	*this = *this - a;
	return *this;
}

BigDecimal BigDecimal::operator*(const BigDecimal & a) 
{	
	BigDecimal ret;
	BigDecimal iterator("1");
	BigDecimal tcpy = absl(*this);
	
	while (tcpy > BigDecimal())
	{	
		ret += a;
		tcpy -=iterator;
	}
	
	ret.sign = (this->sign == a.sign);
	
	return ret;
}

BigDecimal BigDecimal::operator/(const BigDecimal & a)
{
	BigDecimal ret;
	BigDecimal iterator("1");
	BigDecimal tcpy = absl(*this);
	BigDecimal acpy = absl(a);

	while (tcpy >= acpy)
	{	
		ret += iterator;
		tcpy -=acpy;
	}
	
	ret.sign = (this->sign == a.sign);
	
	return ret;
}

bool BigDecimal::operator<(const BigDecimal & a)
{
	if(*this==a)
		return false;
	
	int tl=strlen(this->wrt);
	int al=strlen(a.wrt);
	
	if (this->sign == a.sign)
	{
		if (this->sign)
			return al>tl || strcmp(a.wrt,this->wrt)>0;
		else
			return al<tl || strcmp(a.wrt,this->wrt)<0;	
	}
	
	return !this->sign;
}

bool BigDecimal::operator>(const BigDecimal & a)
{
	if(*this==a)
		return false;
	
	int tl=strlen(this->wrt);
	int al=strlen(a.wrt);
	
	if (this->sign == a.sign)
	{
		if (this->sign)
			return al<tl || strcmp(a.wrt,this->wrt)<0;
		else
			return al>tl || strcmp(a.wrt,this->wrt)>0;	
	}
	
	return this->sign;
}

bool BigDecimal::operator<=(const BigDecimal & a)
{
	return *this==a || *this<a;
}

bool BigDecimal::operator>=(const BigDecimal & a)
{
	return *this==a || *this>a;
}

BigDecimal & BigDecimal::operator*=(const BigDecimal & a)
{
	*this = (*this) *a;
	return *this;
}

BigDecimal & BigDecimal::operator/=(const BigDecimal & a)
{
	*this = (*this) / a;
	return *this;
}

bool BigDecimal::operator!=(const BigDecimal & a)
{
	if (*this == a)
		return false;
	return true;
}










