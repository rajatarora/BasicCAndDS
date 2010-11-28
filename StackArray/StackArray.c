/**
  * StackArray.c
  * Defines a Stack using an Array, along with related methods.
  * see StackArray.h
  * 
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * November 27, 2010
  *
  **/
  
#include "StackArray.h"
#include <stdio.h>

/* Initialize Stack's Top to -1 to indicate an empty stack.
   Call this everytime after creating a new instance of Stack. */
void init(Stack* ps)
{
	ps->Top=-1;
}

/* Push a value 'val' to the top of a Stack pointed to by 'ps' */
void push(Stack* ps, int val)
{
	/* Check if the stack is full */
	if(ps->Top==MAX-1)
		printf("Stack Overflow.");
	
	/* Push if the stack is not full */
	else
	{
		/* Since Top!=MAX-1, we can safely increment it */
		ps->Top++;
		
		/* Insert into the Array */
		ps->Array[ps->Top]=val;
		
		printf("Successfully Pushed.");
	}
}

/* Pop out a value from the top of a Stack pointed to by 'ps' */
int pop(Stack* ps)
{
	int val; /* Value to be popped out */
	
	/* Check if the stack is empty */
	if(ps->Top==-1)
	{
		printf("Stack Underflow.");
		val=ERROR; /* Error condition */
	}
		
	/* Pop if the stack is not empty */
	else
	{
		/* Pop out! */
		val=ps->Array[ps->Top];
		
		/* Since Top!=-1, we can safely decrement it */
		ps->Top--;
	}
	
	/* Return the popped value */
	return val;
}

/* Display the contents of a Stack pointed to by 'ps' */
void display(Stack* ps)
{
	int tmp=ps->Top; /* Used for traversing the stack */
	
	/* Check if the Stack is empty */
	if(tmp==-1)
		printf("Nothing to Display.");
	
	/* Display if stack is not empty */
	else
	{
		for(;tmp>=0;tmp--)
			printf("%d ", ps->Array[tmp]);
	}
}
