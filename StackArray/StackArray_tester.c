/**
  * StackArray_tester.c
  * Tester program for a Stack using an Array.
  * see StackArray.h, StackArray.c
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
  * November 27, 2010
  *
  **/
  
#include "StackArray.c"
#include "../getch_.c"

int main()
{
	/* Declare a stack and a pointer that points to it, then initialize it */
	Stack s;
	Stack* ps=&s;
	init(ps);
	
	/* Declare some local variables */
	int choice;
	int val;
	
	/* Start a do..while for the main menu */
	do
	{
		system("clear");
		printf("STACK\n\n1. Push\n2. Pop\n3. Display\n4. Exit\n\nYour Choice? ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getch(); /* For catching the stray '\n' */
				system("clear");
				printf("PUSH\n\nEnter a value: ");
				scanf("%d",&val);
				push(ps,val);
				printf("\nPress ENTER to continue...");
				while(getch()!='\n');
				break;
				
			case 2:
				system("clear");
				printf("POP\n\n");
				val=pop(ps);
				if(val!=ERROR)
					printf("Value popped: %d",val);
				printf("\nPress ENTER to continue...");
				while(getch()!='\n');
				break;
				
			case 3:
				system("clear");
				printf("CURRENT STACK CONTENTS\n\n");
				display(ps);
				printf("\nPress ENTER to continue...");
				while(getch()!='\n');
				break;
				
			case 4:
				break;
				
			default:
				printf("Wrong choice. Please try again...");
				getch();
				break;
		}
		while(getch()!='\n');
	}while(choice!=4);
	putchar('\n'); /* For inserting a newline before the next command prompt in bash */
	return 0;
}
