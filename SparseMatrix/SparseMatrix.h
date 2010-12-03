/**
  * SparseMatrix.h
  * Defines the structure and declares methods pertaining to a Sparse Matrix.
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
  **/
  
/* Define a Matrix and a Sparse Matrix */
typedef int** Matrix;
typedef int** SparseMatrix;

/* Method declarations */
Matrix Input(int,int); /* Input a Matrix and then return it */
int CountNonZero(Matrix,int,int); /* Count number of non-zero elements in a Matrix */
int ifSparse(Matrix,int,int); /* Check if a Matrix is sparse */
SparseMatrix Sparsify(Matrix,int,int); /* Convert a Matrix to a Sparse Matrix */
SparseMatrix Transpose(SparseMatrix); /* Normal transpose of a Sparse Matrix */
SparseMatrix FastTranspose(SparseMatrix); /* Fast transpose of a Sparse Matrix */
SparseMatrix Add(SparseMatrix,SparseMatrix); /* Add two Sparse Matrices */
Matrix Multiply(SparseMatrix,SparseMatrix); /* Multiply two Sparse Matrices */
void DisplayMatrix(Matrix,int,int); /* Display a Matrix */
void DisplaySparseMatrix(SparseMatrix); /* Display a Sparse Matrix */
