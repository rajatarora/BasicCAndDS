/**
  * CircularQueueArray_tester.c
  * Tester program for a Circular Queue using an Array.
  * see CircularQueueArray.h, CircularQueueArray.c
  * Includes code from Public Domain. see ../getch_.c
  * 
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * November 29, 2010
  *
  **/
  
#include "CircularQueueArray.c" /* Duh! */
#include "../getch_.c" /* getch for Linux */

int main()
{
	/* Declare a Queue, a pointer to it, and initialize it */
	Queue q;
	Queue* pq=&q;
	Init(pq);
	
	/* Declare some local variables */
	int choice;
	int val;
	
	/* Start a do..while for the main menu */
	do
	{
		system("clear");
		printf("CIRCULAR QUEUE\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\n\nYour Choice: ");
		scanf("%d",&choice);
		getch(); /* To catch the stray '\n' */
		switch(choice)
		{
			case 1:
				system("clear");
				printf("INSERT\n\nEnter a value: ");
				scanf("%d",&val);
				Insert(pq,val);
				getch(); /* To catch the stray '\n' */
				printf("\nPress ENTER to continue...");
				while(getch()!='\n');
				break;
				
			case 2:
				system("clear");
				printf("DELETE\n\n");
				val=Delete(pq);
				if(val!=ERROR)
					printf("Value deleted: %d",val);
				printf("\nPress ENTER to continue...");
				while(getch()!='\n');
				break;
				
			case 3:
				system("clear");
				printf("CURRENT CONTENTS OF QUEUE\n\n");
				Display(pq);
				printf("\nPress ENTER to continue...");
				while(getch()!='\n');
				break;
				
			case 4:
				break;
				
			default:
				printf("Invalid input. Try again...");
				break;
		}
	}while(choice!=4);
	return 0;
}
