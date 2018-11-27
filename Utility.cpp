
#include <iostream>
#include "BigDecimal.h"
#include "Utility.h"
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "MyList.h"
#include "ComplexNumber.h"


char* zeroes(const int n) //fill the array with zeroes
{
	char* tmp = new char[n+1];
	memset(tmp, '0', n+1);
	tmp[n] = '\0';

	return tmp;
}

char* dup(const char* str) //duplicate array
{
	int length=strlen(str)+1;
	char* tmp = new char[length];
	strcpy(tmp,str);
	return tmp;
}

bool compare(const BigDecimal & a, const BigDecimal & b) //compare two numbers
{
	char* astr = a.wrt;
	char* bstr = b.wrt;
	bool asign = a.sign;
	bool bsign = b.sign;

	if (strlen(astr) > strlen(bstr))
	{
		std::swap(astr, bstr);
		std::swap(asign, bsign);//this is going to be useful later
	}
	int al = strlen(astr);
	int bl = strlen(bstr);

	char* acpy = zeroes(bl);
	char* bcpy = zeroes(bl);
	char* ctmp = dup(astr); //temporary array in which we will be holding the shorter BigDecimal variable
	strrev2(ctmp); //first ctmp reverse
	strcpy(bcpy, bstr);

	for (int i = 0; i < al; i++)
		acpy[bl - i - 1] = ctmp[i]; //matching the correct digits

	strrev2(acpy);
	strrev2(bcpy);
	
	for (int i = bl-1; i > 0; i--)
	{
		if (acpy[i] - '0' < bcpy[i] - '0')
		{	
			delete[] acpy;
			delete[] bcpy;
			delete[] ctmp;
			return bsign;
		}
	}
	
	delete[] acpy;
	delete[] bcpy;
	delete[] ctmp;
	
	return asign;
}


BigDecimal absl(const BigDecimal & a) //returns absolute value of a BigDecimal
{
	return BigDecimal(a.wrt);
}

BigDecimal add(const BigDecimal & a, const BigDecimal & b)
{	
	char* astr=a.wrt;
	char* bstr=b.wrt;
	bool aznk = a.sign;

	BigDecimal c;
	c.set_sign(aznk);

	if (strlen(astr) > strlen(bstr)) 
		std::swap(astr, bstr); //swapujemy by nie pisac tego samego kodu dla dwoch przypadkow

	int al = strlen(astr);
	int bl = strlen(bstr);

	char* acpy = zeroes(bl); //create copies of a and b arrays and fill them with zeroes
	char* bcpy = zeroes(bl);
	char* wynik = zeroes(bl + 1); //create an output array
	char* ctmp = dup(astr); //temporary array to hold the shorter BigDecimal variable
	strrev2(ctmp); //first reverse of ctmp
	strcpy(bcpy, bstr);

	for (int i = 0; i < al; i++)
		acpy[bl - i - 1] = ctmp[i]; 
	
	strrev2(acpy); //another reverse so the digits match
	strrev2(bcpy);

	
	//przechowujemy wartoœci cyfr z danego miejsca
	
	int tmp = 0; //digit adding output is stored here 
	//iterator will show us from which place we should get rid of unnecessary zeroes
	//adding process
	for (int i = 0; i < strlen(acpy); i++)
	{
		int ia = acpy[i] - '0';
		int ib = bcpy[i] - '0';
		tmp += ia + ib;
		wynik[i] = tmp%10 + '0';
		tmp = tmp/10;
	}
	wynik[strlen(wynik)-1]=tmp + '0';
	std::string str(wynik);
	if (str.at(bl) == '0') //we delete 0 from the beginning if it exists
		str.erase(str.length()-1,str.length()); 
		
	delete[] wynik;
	int length = str.length()+1;
	wynik = new char[length]; 
	strcpy(wynik, str.c_str());
	c.set_wrt(strrev2(wynik));
	delete[] bcpy; //clearing memory to avoid memory leaks
	delete[] acpy;
	delete[] ctmp;
	
	return c;
}

BigDecimal substract(const BigDecimal & a, const BigDecimal & b)
{	//it works similarly to add method
	
	
	char* astr = a.wrt;
	char* bstr = b.wrt;
	BigDecimal c;



	if (strlen(astr) > strlen(bstr))
	{
		std::swap(astr, bstr);
	}
	int al = strlen(astr);
	int bl = strlen(bstr);

	char* acpy = zeroes(bl);
	char* bcpy = zeroes(bl);
	char* wynik = zeroes(bl + 1);
	char* ctmp = dup(astr);
	strrev2(ctmp);
	strcpy(bcpy, bstr);

	for (int i = 0; i < al; i++)
		acpy[bl - i - 1] = ctmp[i];

	strrev2(acpy);
	strrev2(bcpy);

	int tmp = 0;
	int iterator1 = 0;
	c.sign = const_cast<BigDecimal&>(a)>=const_cast<BigDecimal&>(b);
	
	if (acpy[bl - 1] != '0' && bcpy[bl - 1] != '0') //if both numbers have the same length
	{
		for (int j = bl - 1; j >= 0; j--)
		{
			if ((acpy[j] - '0') > (bcpy[j] - '0'))
			{
				std::swap(acpy, bcpy);
				break;
			}
		}
	}
	for (int i = 0; i < strlen(wynik) - 1; i++)
	{
		int ia = acpy[i] - '0'; //works nearly the same as adding
		int ib = bcpy[i] - '0';

		tmp += ib - ia;
		if (tmp < 0)
		{
			tmp += 10;
			wynik[i] = tmp + '0';
			tmp = -1;
		}
		else
		{
			wynik[i] = tmp + '0';
			tmp = 0;
		}
	}
	
	int i=strlen(wynik)-1;
	for(;i>0;i--)
		if(wynik[i]!='0')
			break;
	
	std::string str(wynik);
	str.erase(i+1,str.length());
	delete[] wynik;
	int length = str.length() + 1;
	wynik = new char[length];
	strcpy(wynik, str.c_str());
	c.set_wrt(strrev2(wynik));
	delete[] bcpy; //memory clear to avoid leaks
	bcpy = NULL;
	delete[] acpy;
	acpy = NULL;
	delete[] ctmp;
	ctmp = NULL;
	delete[] ctmp;
	ctmp = NULL;
	return c;
}

std::ostream & operator<<(std::ostream &s,const BigDecimal &a)
{
	if (a.sign == false)
		s << "-";
	s << a.wrt;
	return s;
}

std::istream & operator>>(std::istream & s, BigDecimal &a)
{
		std::string b;
		s >> b;
		a.from_str(b.c_str());
	return s;
}

std::ostream& operator<<(std::ostream&s, const ComplexNumber & a)
{
	s << a.real << " + " << a.imaginary << "i";
}

std::istream& operator>>(std::istream & s, ComplexNumber &a)
{
	s >> a.real;
	s >> a.imaginary;
}

char * strrev2(char* s) //method which reverses array
{
	char  c;
	char* s0 = s - 1;
	char* s1 = s;

	while (*s1) ++s1;

	while (s1-- > ++s0)
	{
		c = *s0;
		*s0 = *s1;
		*s1 = c;
	}

	return s;
}






