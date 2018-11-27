#include <iostream>
#include "MyList.h"
#include "BigDecimal.h"
#include <stdio.h>
#include <string>
#include<cstdio>
#include<cstdlib>


using namespace std;

void double_llist::create(BigDecimal value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 
void double_llist::add_begin(BigDecimal value)
{
    if (start == NULL)
    {
        cout<<"Create list"<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element added"<<endl;
}
 
void double_llist::add_after(BigDecimal value, int pos)
{
	if(pos<0)
	{
		add_begin(value);
		return;
	}
	if(pos>cnt())
	{
		add_end(value);
	}
    if (start == NULL)
    {
        cout<<"Create list"<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There is less than ";
            cout<<pos<<" elements"<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element added"<<endl;
}
 

void double_llist::delete_element(int value)
{
    struct node *tmp, *q;
//deleting the first element
	 
    if (start->info == double_llist::get_element(value))
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Element deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
    //deleting some middle element
        if (q->next->info == double_llist::get_element(value))  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
  //deleting the last element
    if (q->next->info == double_llist::get_element(value))    
    { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}
 

void double_llist::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    q = start;
    cout<<"List :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
 

void double_llist::count()
{ 	
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Number of elements: "<<cnt<<endl;
}

int double_llist::cnt()
{
	struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
	return cnt;
}

void double_llist::add_end(BigDecimal value)
{
	add_after(value,cnt());
}

void double_llist::delete_begin()
{
	delete_element(0);
}

void double_llist::delete_end()
{
	delete_element(cnt());
}
BigDecimal double_llist::get_element(int i)
{
	struct node *tmp, *q;
	int j=i;
	q=start;
	while(j>0)
	{
		q=q->next;
	}
	return q->info;
} 

void double_llist::delete_list()
{
	int j=cnt();
	for(int i=0;i<j;i++)
	{
		delete_element(i);
	}
}
 