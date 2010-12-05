/**
  * Fibonacci.c
  * Prints out the Fibonacci series upto a particular term.
  *
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * December 4, 2010
  *
  **/
  
#include <stdio.h> /* printf, scanf */

/* Function declatations */
int FibonacciTerm(int);

/* Main */
int main()
{
	int Number;
	int i;
	printf("Upto which term? ");
	scanf("%d",&Number);
	for(i=1;i<=Number;i++)
		printf("%d",FibonacciTerm(i));
	putchar('\n');
	return 0;
}

/* Calculate a fibonacci term */
int FibonacciTerm(int Number)
{
	if(Number==1||Number==2)
		return 1;
	else return FibonacciTerm(Number-1)+FibonacciTerm(Number-2);
}
