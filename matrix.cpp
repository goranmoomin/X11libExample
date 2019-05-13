#include <stdio.h>
#include <stdlib.h>
#include "../Toy/matrix.h"

int main(int, char **)
{
    Vector A;		// declation of a double type vector
    FVector B(10);	// declation of a float type vector of size 10
			// with elements B[0]..B[9]
    IVector C(1,10);	// declation of a integer type vector of size 10
			// with elements C[1]..C[10]
    Matrix D(10, 10);	// declation of a double size matrix of size 10 by 10
			// with elements E[0][0]..E[9][9]
    IMatrix E;		// declation of a integer type matrix

    A.Alloc(10);	// Allocation of the vector size as 10
			// Matrix A has the elements A[0]..A[9]
    E.Alloc(-5, 5, -5, 5);	// Allocation of the matrix size as 11 by 11
				// Matgrix E has the elements E[-5][-5]..E[5][5]

    Vector F("test.dat");
    double *f = F();

    printf("Size of matrix a is %d\n", F.Size());
    printf("%f\n", F.GetMax());

    for (int i = 0;  i < F.Size();  i++)
	printf("F[%d] = %f\t%f\n", i, F[i], F.m_buf[i], f[i]);
}
