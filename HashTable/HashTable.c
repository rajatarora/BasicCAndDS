/**
  * HashTable.c
  * Defines a Hash Table, along with related methods.
  * see HashTable.h
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
  
#include "HashTable.h" /* Duh! */
#include <stdio.h> /* printf, scanf, fscanf */
#include <string.h> /* strcmp, strcpy */
#include <stdlib.h> /* malloc */

/* Initialize a Hash Table. Call this everytime you 
   create a new Hash Table */
void Init(HashTable* pht)
{
	int i; /* Local var for looping */
	for(i=0;i<MAXBUCKETS;i++)
		pht->Table[i]=NULL; /* Make every bucket empty */
}

/* Compute the hash of a given word */
int ComputeHash(char* c)
{
	int i; /* Local var for looping */
	unsigned long TmpHash=0; /* Used during calculation of hash */
	
	/* Start calculating */
	for(i=0;c[i]!='\0';i++)
		TmpHash=TmpHash*MULTIPLIER+c[i];
	
	/* Time to return! */
	return TmpHash%MAXBUCKETS;
}

/* Insert a word into a Hash Table */
void Insert(HashTable* pht, int hash, char* c)
{
	/* Find if the word exists in the Hash Table */
	ListNode* t=pht->Table[hash];
	while(t!=NULL)
	{
		if(strcmp(t->Word,c)==0) /* Word found! */
		{
			t->Count++; /* Increment count and, */
			return; /* Goodbye Function! */
		}
		t=t->Next;
	}
	
	/* Allocate memory for the new node */
	ListNode* w=(ListNode*)malloc(sizeof(ListNode));
	
	/* Check if successfully allocated */
	if(w==NULL)
		printf("Error allocating memory.");
		
	/* Insert if allocation successful */
	else
	{
		/* Populate the node */
		strcpy(w->Word,c);
		w->Count=1;
		w->Next=NULL;
		
		/* Insert where ought to */
		if(pht->Table[hash]==NULL)
			pht->Table[hash]=w;
			
		else
		{
			t=pht->Table[hash];
			while(t->Next!=NULL)
				t=t->Next;
			t->Next=w;
		}
	}
}

/* Display a Hash Table */
void Display(HashTable* pht)
{
	int i=0; /* Local var for looping */
	ListNode* t; /* Local var for traversal */
	
	/* Start reading each bucket */
	for(i=0;i<MAXBUCKETS;i++)
	{
		t=pht->Table[i];
		if(t!=NULL)
			printf("%d. ",i+1); /* Display bucket number if it has data */
		
		while(t!=NULL)
		{
			printf("%s(%d) ",t->Word,t->Count); /* Print each word and its frequency */
			t=t->Next;
		}
		if(pht->Table[i]!=NULL)
			putchar('\n'); /* Add a newline only if the bucket had data.
							  Saves on multiple empty newlines */
	}
}
