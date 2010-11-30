/**
  * HashTable_tester.c
  * Tester program for a Hash Table.
  * see HashTable.h, HashTable.c
  *
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * November 30, 2010
  *
  **/
  
#include "HashTable.c" /* Duh! */

int main()
{
	/* Declare a Hash Table, a pointer to it, and initialize it */
	HashTable ht;
	HashTable* pht=&ht;
	Init(pht);
	
	/* Some local vars */
	char c[MAXWORD];
	int hash;
	
	/* Open target file */
	FILE* fp=fopen("TesterText.txt","r+");
	
	/* Read it word-by-word, compute hash of each, and insert in the Hash Table */
	while(fscanf(fp,"%s",c)!=EOF)
	{
		hash=ComputeHash(c);
		Insert(pht,hash,c);
	}
	
	/* Display the result */
	Display(pht);
	
	/* Close file, and Goodbye! */
	fclose(fp);
	return 0;
}
