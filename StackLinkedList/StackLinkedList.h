/**
  * StackLinkedList.h
  * Declares a Stack using a Linked List along with related methods
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

#define ERROR -32767 /* ERROR Condition */
  
typedef struct node /* One node of the list */
{
	int Data;
	struct node* Next;
}ListNode;

/* A stack is nothing but a link to the topmost element.
   Rest all elements point to the next one in the list,
   the last one pointing to NULL */
typedef struct 
{
	ListNode* Top;
}Stack;

/* Here come the methods */
void init(Stack*); /* Initialize Stack->Top to NULL */
void push(Stack*,int); /* Push an 'int' to a 'Stack' */
int pop(Stack*); /* Pop out a value */
void display(Stack*); /* Display a Stack's contents */
