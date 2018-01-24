

#include <math.h>
#include "../cdsrnumbers/cdsrreal.h"
#include "../cdsrarrays/cdsrmmatrix.h"
#include "matrix_internal.h"

double SumOffdiagonalSqrs( CDSRMMatrix<CDSRReal>& A )
{
	CDSRReal	t2 = 0.0;
	long i, j;

	for( i = 0; i < A.n_row() - 1 ; i++ )
		for( j = i + 1; j < A.n_column(); j++ )
			t2 += A(i, j) * A(i, j);
	t2 *= 2;
	return t2;
}
