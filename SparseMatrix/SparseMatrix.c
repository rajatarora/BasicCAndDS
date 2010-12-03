/**
  * SparseMatrix.c
  * Implements various operations pertaining to a Sparse Matrix.
  * see SparseMatrix.h
  * 
  * Rajat Arora
  * rajat@rajatarora.info
  * http://github.com/rajatarora
  * 
  * Usage of this file is subject to license terms.
  * See https://github.com/rajatarora/BasicCAndDS/blob/master/LICENSE 
  * for more info.
  *
  * December 2, 2010
  *
  * Note: This file is incomplete. More function definitions will be added in future.
  *
  **/
  
#include "SparseMatrix.h" /* Duh! */
#include <stdio.h> /* printf, scanf */
#include <stdlib.h> /* malloc, free */

/* Input a Matrix */
Matrix Input(int Rows, int Cols)
{
	int i,j; /* For matrix traversal */
	
	/* Allocate memory for our Matrix */
	Matrix m;
	m=(int**)malloc(Rows*sizeof(int*));
	for(i=0;i<Cols;i++)
		m[i]=(int*)malloc(Cols*sizeof(int));
	
	/* Input values */
	system("clear");
	for(i=0;i<Rows;i++)
	{
		printf("INPUT VALUES ROW WISE\nRow %d:\n",i+1);
		for(j=0;j<Cols;j++)
			scanf("%d",&m[i][j]);
		system("clear");
	}
	
	/* Time to return! */
	return m;
}

/* Count number of non-zero elements in a Matrix */
int CountNonZero(Matrix m, int Rows, int Cols)
{
	int Count=0; /* Let it be zero, initially */
	int i,j; /* For traversal */
	
	/* Count non-zero elements */
	for(i=0;i<Rows;i++)
		for(j=0;j<Cols;j++)
			if(m[i][j]!=0)
				Count++;
	
	/* Time to return! */
	return Count;
}

/* Check if a Matrix is sparse */
int ifSparse(Matrix m, int Rows, int Cols)
{
	unsigned long Total=Rows*Cols; /* Total elements in the Matrix */
	int Sparse=0; /* Assume that the matrix is not sparse, initially */
	
	/* Check for sparsity:
	   A matrix can be considered as "sparse" if less than 1/3 of its elements
	   are non-zero. Anything more than that won't save any memory when implemented
	   as a Sparse Matrix. */
	if((CountNonZero(m,Rows,Cols)*3)<=Total)
		Sparse=1;
		
	/* Time to return! */
	return Sparse;
}

/* Sparsify a Matrix */
SparseMatrix Sparsify(Matrix m, int Rows, int Cols)
{
	int i,j,k; /* For traversal */
	
	/* Count non-zero elements */
	int NonZero=CountNonZero(m,Rows,Cols);
	
	/* Allocate memory for the Sparse Matrix */
	SparseMatrix spm;
	spm=(int**)malloc((NonZero+1)*sizeof(int*));
	for(i=0;i<NonZero+1;i++)
		spm[i]=(int*)malloc(3*sizeof(int));
	
	/* Fill the first row of the sparse matrix */
	spm[0][0]=Rows;
	spm[0][1]=Cols;
	spm[0][2]=NonZero;
	
	/* Sparsify! */
	k=1; /* This will take care of the sparse matrix array */
	
	/* Traverse the matrix, and insert every non-zero term into the sparse matrix */
	for(i=0;i<Rows;i++)
		for(j=0;j<Cols;j++)
			if(m[i][j]!=0)
				{
					spm[k][0]=i;
					spm[k][1]=j;
					spm[k][2]=m[i][j];
					k++;
				}
	
	/* Time to return! */
	return spm;
}

/* Add two sparse matrices */
SparseMatrix Add(SparseMatrix spma, SparseMatrix spmb)
{
	SparseMatrix spmc=NULL;
	int i,j,k; /* Take care of Matrix A, B and C respectively */
	
	/* First of all, check for compatibility */
	if(spma[0][0]!=spmb[0][0]||spma[0][1]!=spmb[0][1])
		fprintf(stderr,"Non compatible matrices");
	
	/* Matrices are compatible */
	else
	{
		/* Allocate memory for the third matrix */
		spmc=(int**)malloc((spma[0][2]+spmb[0][2]+1)*sizeof(int*));
		for(i=0;i<spma[0][2]+spmb[0][2]+1;i++)
			spmc[i]=(int*)malloc(3*sizeof(int));
				/* Why spma[0][2]+spmb[0][2] locations?
				   Because even if no two terms are combined in Matrix A and B,
				   they can't have more than (non-zero terms in A) + (non-zero
				   terms in B) terms. */
				   
		/* Populate Rows and Columns in Row 0 */
		spmc[0][0]=spma[0][0];
		spmc[0][1]=spma[0][1];
		
		/* Add! */
		i=j=k=1;
		
		/* Strategy for Adding:
		   Start from the first 3-tuples of both Matrix A and B. 
		   If their row numbers are equal
		   		If their column numbers are equal
		   			Add their values and store in Mat C.
		   		If Column number of Mat A is less than that of B
		   			Transfer that tuple of Mat A to Mat C
		   		else
		   			Transfer that tuple of Mat B to Mat C
		   	If Row number of Mat A is less than that of B
		   		Transfer that tuple of Mat A to Mat C
		   	else
		   		Transfer that tuple of Mat B to Mat C 
		   		
		This thorough procedure ensures that the tuples in Mat C are entered
		sorted first by rows and then by columns, and no further sorting is 
		necessary. */
		while(i<=spma[0][2]&&j<=spmb[0][2])
		{
			if(spma[i][0]==spmb[j][0])
			{
				if(spma[i][1]==spmb[j][1])
				{
					spmc[k][0]=spma[i][0];
					spmc[k][1]=spma[i][1];
					spmc[k][2]=spma[i][2]+spmb[j][2];
					i++; j++; k++;
				}
				else if(spma[i][1]<spmb[j][1])
				{
					spmc[k][0]=spma[i][0];
					spmc[k][1]=spma[i][1];
					spmc[k][2]=spma[i][2];
					i++; k++;
				}
				else
				{
					spmc[k][0]=spmb[j][0];
					spmc[k][1]=spmb[j][1];
					spmc[k][2]=spmb[j][2];
					j++; k++;
				}
			}
			else if(spma[i][0]<spmb[j][0])
			{
				spmc[k][0]=spma[i][0];
				spmc[k][1]=spma[i][1];
				spmc[k][2]=spma[i][2];
				i++; k++;
			}
			else
			{
				spmc[k][0]=spmb[j][0];
				spmc[k][1]=spmb[j][1];
				spmc[k][2]=spmb[j][2];
				j++; k++;
			}
		}
		while(i<=spma[0][2])
		{
			spmc[k][0]=spma[i][0];
			spmc[k][1]=spma[i][1];
			spmc[k][2]=spma[i][2];
			i++; k++;
		}
		while(j<=spmb[0][2])
		{
			spmc[k][0]=spmb[j][0];
			spmc[k][1]=spmb[j][1];
			spmc[k][2]=spmb[j][2];
			j++; k++;
		}
		spmc[0][2]=k-1;
	}
	   
	/* Time to return! */	
	return spmc;
}

/* Display a Matrix */
void DisplayMatrix(Matrix m, int Rows, int Cols)
{
	int i,j; /* For matrix traversal */
	
	/* Display matrix */
	for(i=0;i<Rows;i++)
	{
		for(j=0;j<Cols;j++)
			printf("%d ",m[i][j]);
		putchar('\n');
	}
}

/* Display a Sparse Matrix */
void DisplaySparseMatrix(SparseMatrix spm)
{
	int i; /* For traversal */
	int Total; /* No. of non-zero terms in the sparse matrix */
	
	/* Read the total no. of non-zero terms */
	Total=spm[0][2];
	
	/* Start the display */
	for(i=1;i<=Total;i++)
		printf("m[%d][%d] = %d\n",spm[i][0],spm[i][1],spm[i][2]);
}
