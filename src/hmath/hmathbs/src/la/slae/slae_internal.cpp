

#include "slae_internal.h"

//////////////////////////////////////////////////////////////////////

void _IndexCR( long i, CDSRMMatrix<CDSRReal> *pMatrix, CDSRMVector<long> *pRow, CDSRMVector<long> *pCol )
{
	long j, k;
	long J = i;
	long K = i;
	CDSRReal max = fabs( (*pMatrix)( (*pRow)[ i ], (*pCol)[ i ] ) );

	for( j = i; j < pMatrix->n_row(); j++ )
		for( k = i; k < pMatrix->n_row(); k++ )
			if( fabs( (*pMatrix)( (*pRow)[ j ], (*pCol)[ k ] )) > max )
			{
				max = fabs( (*pMatrix)( (*pRow)[ j ], (*pCol)[ k ] ) );
				J = j;
				K = k;
			}

	if( IsNotNull( max ) )
	{
		j = (*pRow)[ i ];
		k = (*pCol)[ i ];
		(*pRow)[ i ] = (*pRow)[ J ];
		(*pCol)[ i ] = (*pCol)[ K ];
		(*pRow)[ J ] = j;
		(*pCol)[ K ] = k;
	}
	else
		throw "Matrix is singular";
}

//////////////////////////////////////////////////////////////////////

void _IndexR( long i, CDSRMMatrix<CDSRReal> *pMatrix, CDSRMVector<long> *pRow )
{
	long j;
	long J = i;
	CDSRReal max = fabs( (*pMatrix)( (*pRow)[ i ], i ) );

	for( j = i + 1; j < pMatrix->n_row(); j++ )
		if( fabs( (*pMatrix)( (*pRow)[ j ], i ) ) > max )
		{
			max = fabs( (*pMatrix)( (*pRow)[ j ], i ) );
			J = j;
		}

	if( IsNotNull( max ) )
	{
		j = (*pRow)[ i ];
		(*pRow)[ i ] = (*pRow)[ J ];
		(*pRow)[ J ] = j;
	}
	else
		throw "Matrix is singular";
}

//////////////////////////////////////////////////////////////////////

void _IndexC( long i, CDSRMMatrix<CDSRReal> *pMatrix, CDSRMVector<long> *pCol )
{
	long j;
	long J = i;
	CDSRReal max = fabs( (*pMatrix)(i, (*pCol)[ i ]) );

	for( j = i + 1; j < pMatrix->n_row(); j++ )
		if( fabs( (*pMatrix)( i, (*pCol)[ j ] ) ) > max )
		{
			max = fabs( (*pMatrix)( i, (*pCol)[ j ] ) );
			J = j;
		}

	if( IsNotNull( max ) )
	{
		j = (*pCol)[ i ];
		(*pCol)[ i ] = (*pCol)[ J ];
		(*pCol)[ J ] = j;
	}
	else
		throw "Matrix is singular";
}

//////////////////////////////////////////////////////////////////////
