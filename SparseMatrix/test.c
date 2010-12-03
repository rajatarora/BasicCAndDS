#include "SparseMatrix.c"
#include "../getch_.c"

int main()
{
	Matrix m;
	SparseMatrix spma,spmb,spmc;
	m=Input(3,3);
	DisplayMatrix(m,3,3);
	if(ifSparse(m,3,3))
		printf("Its a sparse matrix!.\n");
	else
		printf("Its not a sparse matrix.\n");
	spma=Sparsify(m,3,3);
	DisplaySparseMatrix(spma);
	getch(); getch();
	m=Input(3,3);
	DisplayMatrix(m,3,3);
	if(ifSparse(m,3,3))
		printf("Its a sparse matrix!.\n");
	else
		printf("Its not a sparse matrix.\n");
	spmb=Sparsify(m,3,3);
	DisplaySparseMatrix(spmb);
	getch(); getch();
	spmc=Add(spma,spmb);
	putchar('\n');
	DisplaySparseMatrix(spmc);
	return 0;
}
