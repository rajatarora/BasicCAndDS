/**
  * CircularQueueArray.c
  * Defines a Circular Queue using an Array, along with related methods.
  * see CircularQueueArray.h
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
  
#include "CircularQueueArray.h" /* Queue */
#include <stdio.h> /* printf, scanf */

/* Initialize the Queue (Queue->Front, Queue->Rear = -1) 
   Call this everytime you declare a new Queue */
void Init(Queue* pq)
{
	pq->Front=-1;
	pq->Rear=-1;
}

/* Insert into the Queue (aka, add at end) */
void Insert(Queue* pq, int val)
{
	/* Check if the Queue is full */
	if((pq->Rear+1)%MAX==pq->Front)
		printf("Queue overflow.");
		
	/* Insert if not */
	else
	{
		/* Check if Rear is at the last position of the Array */
		if(pq->Rear==MAX-1)
			
			/* Make Rear = 0 */
			pq->Rear=0;
			
		/* Increment if not */
		else
			pq->Rear++;
			
		/* Used for first insertion */
		if(pq->Front==-1)
			pq->Front=0;
			
		/* Finally, insert the element */
		pq->Array[pq->Rear]=val;
		printf("Successfully inserted at position %d.",pq->Rear);
	}
}

/* Delete from the Queue (aka, remove from beginning) */
int Delete(Queue* pq)
{
	int val; /* Local var for deletion */
	
	/* Check if the Queue is empty */
	if(pq->Front==-1)
	{
		printf("Queue underflow");
		val=ERROR; /* ERROR condition */
	}
			
	/* Delete if not */
	else
	{
		val=pq->Array[pq->Front]; /* Deleted! */
		
		/* Check if there's only one element in the Queue */
		if(pq->Front==pq->Rear)
		{
			/* Make Queue empty */
			pq->Front=-1;
			pq->Rear=-1;
		}
		
		/* Check if Front is in the last position in the Array */
		else if(pq->Front==MAX-1)
			pq->Front=0;
			
		/* Else, increment Front */
		else
			pq->Front++;
	}
	
	/* Time to return! */
	return val;
}

/* Display the Queue contents */
void Display(Queue* pq)
{
	/* Check if the Queue is empty */
	if(pq->Front==-1)
		printf("Nothing to display.");
		
	/* Display if not */
	else
	{
		int i; /* Local var for looping */
		
		/* Check if the Queue is linear */
		if(pq->Front<=pq->Rear)
			
			/* Just one loop! */
			for(i=pq->Front;i<=pq->Rear;i++)
				printf("%d ",pq->Array[i]);
				
		/* If the Queue is circular */
		else
		{
			/* Two loops */
			for(i=pq->Front;i<MAX;i++) /* Front to the end of Array */
				printf("%d ",pq->Array[i]);
			for(i=0;i<=pq->Rear;i++) /* Start of Array to Rear */
				printf("%d ",pq->Array[i]);
		}
	}
}
