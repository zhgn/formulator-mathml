

//////////////////////////////////////////////////////////////////////

#include "ziter.h"
#include "slae_internal.h"

MATHBASE_API 
void _ZeidIterations( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, counter = 0;
	bool bPrecision = false;
	CDSRReal value;
	CDSRMVector<CDSRReal> vector;

	for( i = 0; i < pA->n_row(); i++ )
	{
		if( IsNull( (*pA)( i, i ) ) )
			throw "SLAE cannot be solved by this method or matrix is singular";

		value = fabs( (*pA)( i, i ) );
		for( j = 0; j < pA->n_row(); j++ )
			if( i != j && value < fabs( (*pA)( i, j ) ) )
				throw "SLAE cannot be solved by iteration method or matrix is singular";
	}

	pX->resize( pA->n_row() );
	vector.resize( pA->n_row(), 1.0 );

	while( !bPrecision )
	{
		for( i = 0; i < pA->n_row(); i++ )
		{
			(*pX)[ i ] = -(*pB)[ i ];
			for( j = 0; j < i; j++ )
	 			(*pX)[ i ] += (*pA)( i, j ) * (*pX)[ j ];
			for( j = i; j < pA->n_row(); j++ )
	 			(*pX)[ i ] += (*pA)( i , j ) * vector[ j ];

			(*pX)[ i ] = vector[ i ] - (*pX)[ i ] / (*pA)( i, i );
		}

		counter++;
		bPrecision = true;
		for( i = 0; i < pA->n_row(); i++ )
			if( fabs( (*pX)[ i ] - vector[ i ] ) > rlPrecision )
			{
				bPrecision = false;
				vector = (*pX);
				break;
			}

		if( counter > ALMASLAE_MAX_ITER_COUNT )
			throw "Iteration counter limit exceeded";
	}
}

//////////////////////////////////////////////////////////////////////

MATHBASE_API 
void _ZeidIterationsC( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, counter = 0;
	bool bPrecision = false;
	CDSRReal value;
	CDSRMVector<long> col( pA->n_row() );
	CDSRMVector<CDSRReal> vector;

	for( i = 0; i < pA->n_row(); i++ )
		col[ i ] = i;

	for( i = 0; i < pA->n_row(); i++ )
	{
		_IndexC( i, pA, &col );

		value = fabs( (*pA)( i, col[ i ] ) );
		for( j = 0; j < pA->n_row(); j++ )
			if( i != j && value < fabs( (*pA)( i, col[ j ] ) ) )
				throw "SLAE cannot be solved by iteration method or matrix is singular";
	}

	pX->resize( pA->n_row() );
	vector.resize( pA->n_row(), 1.0 );

	while( !bPrecision )
	{
		for( i = 0; i < pA->n_row(); i++ )
		{
			(*pX)[ col[ i ] ] = -(*pB)[ i ];
			for( j = 0; j < i; j++ )
				(*pX)[ col[ i ] ] += (*pA)( i, col[ j ] ) * (*pX)[ col[ j ] ];
			for( j = i; j < pA->n_row(); j++ )
				(*pX)[ col[ i ] ] += (*pA)( i, col[ j ] ) * vector[ col[ j ] ];

			(*pX)[ col[ i ] ] = vector[ col[ i ] ] - (*pX)[ col[ i ] ] / (*pA)( i, col[ i ] );
		}

		counter++;
		bPrecision = true;
		for( i = 0; i < pA->n_row(); i++ )
			if( fabs( (*pX)[ col[ i ] ] - vector[ col[ i ] ] ) > rlPrecision )
			{
				bPrecision = false;
				vector = (*pX);
				break;
			}

		if( counter > ALMASLAE_MAX_ITER_COUNT )
			throw "Iteration counter limit exceeded";
	}
}

//////////////////////////////////////////////////////////////////////

MATHBASE_API 
void _ZeidIterationsR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, counter = 0;
	bool bPrecision = false;
	CDSRReal value;
	CDSRMVector<long> row( pA->n_row() );
	CDSRMVector<CDSRReal> vector;

	for( i = 0; i < pA->n_row(); i++ )
		row[ i ] = i;

	for( i = 0; i < pA->n_row(); i++ )
	{
		_IndexR( i, pA, &row );

		value = fabs( (*pA)( row[ i ], i ) );
		for( j = 0; j < pA->n_row(); j++ )
			if( i != j && value < fabs( (*pA)( row[ i ], j ) ) )
				throw "SLAE cannot be solved by iteration method or matrix is singular";
	}

	pX->resize( pA->n_row() );
	vector.resize( pA->n_row(), 1.0 );

	while( !bPrecision )
	{
		for( i = 0; i < pA->n_row(); i++ )
		{
			(*pX)[ i ] = -(*pB)[ row[ i ] ];
			for( j = 0; j < i; j++ )
				(*pX)[ i ] += (*pA)( row[ i ], j ) * (*pX)[ j ];
			for( j = i; j < pA->n_row(); j++ )
				(*pX)[ i ] += (*pA)( row[ i ], j ) * vector[ j ];

			(*pX)[ i ] = vector[ i ] - (*pX)[ i ] / (*pA)( row[ i ], i );
		}

		counter++;
		bPrecision = true;
		for( i = 0; i < pA->n_row(); i++ )
			if( fabs( (*pX)[ i ] - vector[ i ] ) > rlPrecision )
			{
				bPrecision = false;
				vector = (*pX);
				break;
			}

		if( counter > ALMASLAE_MAX_ITER_COUNT )
			throw "Iteration counter limit exceeded";
	}
}

//////////////////////////////////////////////////////////////////////

MATHBASE_API 
void _ZeidIterationsCR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, counter = 0;
	bool bPrecision = false;
	CDSRReal value;
	CDSRMVector<long> row( pA->n_row() );
	CDSRMVector<long> col( pA->n_row() );
	CDSRMVector<CDSRReal> vector;

	for( i = 0; i < pA->n_row(); i++ )
		row[ i ] = col[ i ] = i;

	for( i = 0; i < pA->n_row(); i++ )
	{
		_IndexCR( i, pA, &row, &col );

		value = fabs( (*pA)( row[ i ], col[ i ] ) );
		for( j = 0; j < pA->n_row(); j++ )
			if( i != j && value < fabs( (*pA)( row[ i ], col[ j ]) ) )
				throw "SLAE cannot be solved by iteration method or matrix is singular";
	}

	pX->resize( pA->n_row() );
	vector.resize( pA->n_row(), 1.0 );

	while( !bPrecision )
	{
		for( i = 0; i < pA->n_row(); i++ )
		{
			(*pX)[ col[ i ] ] = -(*pB)[ row[ i ] ];
			for( j = 0; j < i; j++ )
				(*pX)[ col[ i ] ] += (*pA)( row[ i ], col[ j ] ) * (*pX)[ col[ j ] ];
			for( j = i; j < pA->n_row(); j++ )
				(*pX)[ col[ i ] ] += (*pA)( row[ i ], col[ j ] ) * vector[ col[ j ] ];

			(*pX)[ col[ i ] ] = vector[ col[ i ] ] - (*pX)[ col[ i ] ] / (*pA)( row[ i ], col[ i ] );
		}

		counter++;
		bPrecision = true;
		for( i = 0; i < pA->n_row(); i++ )
			if( fabs( (*pX)[ col[ i ] ] - vector[ col[ i ] ] ) > rlPrecision )
			{
				bPrecision = false;
				vector = (*pX);
				break;
			}

		if( counter > ALMASLAE_MAX_ITER_COUNT )
			throw "Iteration counter limit exceeded";
	}
}

//////////////////////////////////////////////////////////////////////
