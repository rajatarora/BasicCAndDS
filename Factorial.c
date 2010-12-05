/**
  * Factorial.c
  * Finds out the factorial of a number <13 
  * (after that, unsigned long int overflows)
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

/* Function definitions */
unsigned long Factorial(int);

int main()
{
	int Number;
	printf("Enter a number: ");
	scanf("%d",&Number);
	printf("%d! = %ld",Number,Factorial(Number));
	putchar('\n');
	return 0;
}

/* Calculate factorial */
unsigned long Factorial(int Number)
{
	unsigned long Factorial=1;
	int i;
	for(i=Number;i>1;i--)
		Factorial*=i;
	return Factorial;
}
