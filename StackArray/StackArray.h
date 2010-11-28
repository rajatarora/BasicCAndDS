/**
  * StackArray.h
  * Declares a Stack using an Array, along with related methods.
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
 
#define MAX 100	/* Max Elements */				
#define ERROR -32767 /* Error Condition */			
 
typedef struct 
{
	int Array[MAX];	 /* The Array */			
	int Top; /* Points to the topmost element */					
}Stack;

/* Method Declarations */
void init(Stack*);	/* Initialize Stack->Top to -1 */			
void push(Stack*,int);	/* Push into */		
int pop(Stack*); /* Pop out */				
void display(Stack*); /* Display contents */			
