/**
  * MergeSort.c
  * Implements the Merge sorting technique
  * Includes code from Public Domain. see getch_.c
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

#define MAXELEMENTS 20 /* Max elements in an array for sorting */

#include <stdio.h> /* printf, scanf */
#include "getch_.c" /* getch */

/* Function declarations */
void MergeSort(int*,int,int);
void Merge(int*,int,int,int);

/* Main function */
int main()
{
	/* Some local vars */
	int Array[MAXELEMENTS];
	int NumElements;
	int i;
	
	/* Populate the array from user input */
	printf("How many elements (<=20)? ");
	scanf("%d",&NumElements);
	printf("Enter %d elements, one-by-one:\n",NumElements);
	for(i=0;i<NumElements;i++)
		scanf("%d",&Array[i]);
	
	/* Call MergeSort */
	MergeSort(Array,0,NumElements-1);
	
	/* Display sorted Array */
	printf("\nSorted Array:\n");
	for(i=0;i<NumElements;i++)
		printf("%d ",Array[i]);
	
	/* Goodbye! */
	return 0;
}

/* Merge Sort */
void MergeSort(int* Array, int Low, int High)
{
	int Mid;
	if(Low<High)
	{
		Mid=(Low+High)/2;
		MergeSort(Array,Low,Mid);
		MergeSort(Array,Mid+1,High);
		Merge(Array,Low,Mid,High);
	}
}

/* Merge two sorted arrays */
void Merge(int* Array, int Low, int Mid, int High)
{
	int TmpArray[MAXELEMENTS]; /* For temporary storage */
	int i,j,k; /* For traversal */
	
	/* Initialize variables */
	i=Low; /* For lower part of array */
	j=Mid+1; /* For upper part of array */
	k=Low; /* For TmpArray */
	
	/* Merge! */
	while(i<=Mid&&j<=High)
	{
		if(Array[i]<Array[j])
		{
			TmpArray[k]=Array[i];
			i++; k++;
		}
		else
		{
			TmpArray[k]=Array[j];
			j++; k++;
		}
	}
	while(i<=Mid)
	{
		TmpArray[k]=Array[i];
		i++; k++;
	}
	while(j<=High)
	{
		TmpArray[k]=Array[j];
		j++; k++;
	}
	
	/* At this point, the merged array resides in TmpArray. Transfer it back
	   to Array */
	for(i=Low;i<=High;i++)
		Array[i]=TmpArray[i];
}
