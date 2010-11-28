/**
  * StackLinkedList.c
  * Defines a Stack using a Linked List along with related methods
  * see StackLinkedList.h
  *
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * November 28, 2010
  *
  **/
  
#include "StackLinkedList.h"
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */

/* Initialize Stack->Top to NULL.
   Call it everytime after declaring a new instance of Stack */
void init(Stack* ps)
{
	ps->Top=NULL;
}

/* Push an element into a Stack */
void push(Stack* ps, int val)
{
	/* Allocate memory for a new ListNode */
	ListNode* ln=(ListNode*)malloc(sizeof(ListNode));
	
	/* Check for successful allocation of memory */
	if(ln==NULL)
		printf("Error allocating memory.");
		
	/* Push if memory successfully allocated */
	else
	{
		ln->Data=val;
		ln->Next=ps->Top;
		ps->Top=ln;
	}
}

/* Pop out an element from a Stack */
int pop(Stack* ps)
{
	int val; /* This will pop out */
	
	/* Check if the Stack is empty */
	if(ps->Top==NULL)
	{
		printf("Stack Underflow");
		val=ERROR;
	}
	
	/* Pop out if not */
	else
	{
		ListNode* tmp=ps->Top; /* Local var for deletion */
		val=ps->Top->Data;
		ps->Top=ps->Top->Next;
		free(tmp); /* Here goes our friend! */
	}
	
	/* Return that value */
	return val;
}

/* Display a Stack */
void display(Stack* ps)
{
	ListNode* tmp=ps->Top; /* Local var for traversal */
	
	/* Check if Stack is empty */
	if(ps->Top==NULL)
		printf("Nothing to display.");
	
	/* Display if non-empty */
	else
	{
		while(tmp!=NULL)
		{
			printf("%d ",tmp->Data);
			tmp=tmp->Next; /* List traversal */
		}
	}
}
