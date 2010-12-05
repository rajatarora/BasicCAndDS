/**
  * Hanoi.c
  * Solves the Tower of Hanoi problem.
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
  
#define SRC  1
#define AUX  2
#define DEST 3

#include <stdio.h> /* printf, scanf */

/* Function declaration */
void Hanoi(int,int,int,int);

/* Main */
int main()
{
	int Total;
	printf("How many pegs? ");
	scanf("%d",&Total);
	Hanoi(Total,SRC,AUX,DEST);
	return 0;
}

/* Solve the problem! */
void Hanoi(int Total, int Source, int Auxilliary, int Destination)
{
	if(Total>0)
	{
		Hanoi(Total-1,Source,Destination,Auxilliary);
		printf("Move %d -> %d\n",Source,Destination);
		Hanoi(Total-1,Auxilliary,Source,Destination);
	}
}
