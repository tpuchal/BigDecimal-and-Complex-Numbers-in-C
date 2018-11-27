#pragma once

#include <iostream>
#include "BigDecimal.h"
#include <stdio.h>
#include <string>

//All methods necessary to create a class
BigDecimal add(const BigDecimal & a, const BigDecimal & b); //adds two BigDecimals
BigDecimal substract(const BigDecimal & a, const BigDecimal & b); //subtracts two BigDecimals
char* strrev2(char* s); //reverses two bigdecimals
char* zeroes(const int n); //fill the array with zeroes
char* dup(const char* str); //duplicates array
bool compare(const BigDecimal & a, const BigDecimal & b); //comparing two Bigdecimals to get the sign
BigDecimal absl(const BigDecimal & a); //returns absolute value of BigDecimal
