#pragma once
#include <iostream>
#include "BigDecimal.h"
#include "Utility.h"
#include <stdio.h>
#include <string>
#include<cstdio>
#include<cstdlib>


struct node
{
    BigDecimal info;
    struct node *next;
    struct node *prev;
};

class double_llist
{	
	node *start;
    public:
        void create(BigDecimal value); //creates a new list
        void add_begin(BigDecimal value); // adds the element to the begin of the list
        void add_after(BigDecimal value, int position); //adds the element to some position in the list
        void delete_element(int value);//delete element from the certain index
        void display_dlist();//displays list
        void count();//displays the number of elements
		void add_end(BigDecimal value);//add element to the end of the list
		int cnt();//return lits length
		void delete_begin();//deletes element from beginning of the list
		void delete_end();//deletes element from the end of the list
		void delete_list();//delete the list
		BigDecimal get_element(int i);//returns the element from i-th element
        double_llist()
        {
			
            start = NULL;  
        }
};
