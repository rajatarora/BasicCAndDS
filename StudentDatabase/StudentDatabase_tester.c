/**
  * StudentDatabase_tester.
  * Tester program for a file based Student Database
  * 
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * December 5, 2010
  *
  **/

#include "StudentDatabase.c"

int main()
{
    int choice;
    do
    {
    	system("clear");
    	printf("STUDENT DATABASE\n\n1. Register a Student\n2. Display all Students\n3. Exit\n\nYour Choice: ");
    	scanf("%d",&choice);
    	getch();
    	switch(choice)
    	{
    		case 1:
    			inputstu(); break;
    		case 2:
    			dispstu(); break;
    		case 3: 
    			break;
    		default:
    			printf("\nWrong choice. Try again...");
    			break;
    	}
    }while(choice!=3);
    putchar('\n');
    return 0;
}
