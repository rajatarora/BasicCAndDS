/**
  * HashTable.h
  * Declares a Hash Table, along with related methods.
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
  
#define MAXBUCKETS 10 /* Max 'Storage Areas' */
#define MAXWORD 10 /* Max characters in a single word */
#define MULTIPLIER 3 /* Used in the hash function */

/* List component of a Hash Table */
typedef struct node
{
	char Word[MAXWORD];
	int Count;
	struct node* Next;
}ListNode;

/* The Hash Table */
typedef struct
{
	ListNode* Table[MAXBUCKETS]; /* Array component of the Hash Table */
}HashTable;

/* Method definitions */
void Init(HashTable*); /* Initialize a Hash Table */
int ComputeHash(char*); /* The Hash function */
void Insert(HashTable*,int,char*); /* Insert into Hash Table */
void Display(HashTable*); /* Display a Hash Table */
