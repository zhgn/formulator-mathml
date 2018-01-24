

#include "jordangauss.h"
#include "slae_internal.h"

//////////////////////////////////////////////////////////////////////

MATHBASE_API 
void _JordanGauss( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, k;
	CDSRReal value;
	CDSRMMatrix<CDSRReal> matrix( (*pA) );
	CDSRMVector<CDSRReal> vector( (*pB) );
	
	pX->resize( pB->size() );

	for( i = 0; i < pA->n_row(); i++ )
	{
		if( IsNull( matrix( i, i ) ) )
			throw "SLAE cannot be solved by this method or matrix is singular";

		for( k = i; k < pA->n_row(); k++ )
		{
			value = matrix( k, i );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ k ] /= value;
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( k, j ) /= value;
				matrix( k, i ) = 1.0;
			}
		}

		for( k = i + 1; k < pA->n_row(); k++ )
		{
			value = matrix( k, i );
			if( IsNotNull( value ) )
			{
				vector[ k ] -= vector[ i ];
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( k, j ) -= matrix( i, j );
				matrix( k, i ) = 0.0;
			}
		}
	}

	for( i = pA->n_row() - 1; i > 0; i-- )
	{
		for( k = 0; k < i + 1; k++ )
		{
			value = matrix( k, i );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ k ] /= value;
		   		for( j = k; j < i; j++ )
		   			matrix( k, j ) /= value;
			}
		}
		for( k = 0; k < i; k++ )
		{
			value = matrix( k, i );
			if( IsNotNull( value ) )
			{
				vector[ k ] -= vector[ i ];
				matrix( k, i ) = 0.0;
			}
		}
	}

	vector[ 0 ] /= matrix( 0, 0 );
	matrix( 0, 0 ) = 1.0;

	for( i = 0 ; i < pA->n_row(); i++ )
		( *pX )[ i ] = vector[ i ];
}

//////////////////////////////////////////////////////////////////////
// Метод Жордана - Гаусса с выбором по столбцу

MATHBASE_API 
void _JordanGaussC( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, k;
	CDSRReal value;
	CDSRMMatrix<CDSRReal> matrix( (*pA) );
	CDSRMVector<CDSRReal> vector( (*pB) );
	CDSRMVector<long> col( pA->n_row() );

	pX->resize( pB->size() );

	for( i = 0; i < pA->n_row(); i++ )
		col[ i ] = i;

	for( i = 0; i < pA->n_row(); i++ )
	{
		if( IsNull( matrix( i, col[ i ] ) ) )
			_IndexC( i, &matrix, &col );

		for( k = i; k < pA->n_row(); k++ )
		{
			value = matrix( k, col[ i ] );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ k ] /= value;
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( k, col[ j ] ) /= value;
				matrix( k, col[ i ] ) = 1.0;
			}
		}

		for( k = i + 1; k < pA->n_row(); k++ )
		{
			value = matrix( k, col[ i ] );
			if( IsNotNull( value ) )
			{
				vector[ k ] -= vector[ i ];
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( k, col[ j ] ) -= matrix( i, col[ j ] );
				matrix( k, col[ i ] ) = 0.0;
			}
		}
	}

	for( i = pA->n_row() - 1; i > 0; i-- )
	{
		for( k = 0; k < i + 1; k++ )
		{
			value = matrix( k, col[ i ] );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ k ] /= value;
		   		for( j = k; j < i; j++ )
		   			matrix( k, col[ j ] ) /= value;
				matrix( k, col[ i ] ) = 1.0;
			}
		}
		for( k = 0; k < i; k++ )
		{
			value = matrix( k, col[ i ] );
			if( IsNotNull( value ) )
			{
				vector[ k ] -= vector[ i ];
				matrix( k, col[ i ] ) = 0.0;
			}
		}
	}

	vector[ 0 ] /= matrix( 0, col[ 0 ] );
	matrix( 0, col[ 0 ] ) = 1.0;

	for( i = 0; i < pA->n_row(); i++ )
		( *pX )[ col[ i ] ] = vector[ i ];
}

//////////////////////////////////////////////////////////////////////
// Метод Жордана - Гаусса с выбором по строке

MATHBASE_API 
void _JordanGaussR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, k;
	CDSRReal value;
	CDSRMMatrix<CDSRReal> matrix( (*pA) );
	CDSRMVector<CDSRReal> vector( (*pB) );
	CDSRMVector<long> row( pA->n_row() );

	pX->resize( pB->size() );

	for( i = 0; i < pA->n_row(); i++ )
		row[ i ] = i;

	for( i = 0; i < pA->n_row(); i++ )
	{
		if( IsNull( matrix( row[ i ], i ) ) )
			_IndexR( i, &matrix, &row );

		for( k = i; k < pA->n_row(); k++ )
		{
			value = matrix( row[ k ], i );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ row[ k ] ] /= value;
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( row[ k ], j ) /= value;
				matrix( row[ k ], i ) = 1.0;
			}
		}

		for( k = i + 1; k < pA->n_row(); k++ )
		{
			value = matrix( row[ k ], i );
			if( IsNotNull( value ) )
			{
				vector[ row[ k ] ] -= vector[ row[ i ] ];
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( row[ k ], j ) -= matrix( row[ i ], j );
				matrix( row[ k ], i ) = 0.0;
			}
		}
	}

	for( i = pA->n_row() - 1; i > 0; i-- )
	{
		for( k = 0; k < i + 1; k++ )
		{
			value = matrix( row[ k ], i );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ row[ k ] ] /= value;
	   			for( j = k; j < i; j++ )
   					matrix( row[ k ], j ) /= value;
				matrix( row[ k ], i ) = 1.0;
			}
		}

		for( k = 0; k < i; k++ )
		{
			value = matrix( row[ k ], i );
			if( IsNotNull( value ) )
			{
				vector[ row[ k ] ] -= vector[ row[ i ] ];
				matrix( row[ k ], i ) = 0.0;
			}
		}
	}

	vector[  row[ 0 ] ] /= matrix( row[ 0 ], 0 );
	matrix(  row[ 0 ], 0 ) = 1.0;

	for( i = 0; i < pA->n_row(); i++ )
		( *pX )[ i ] = vector[ row[ i ] ];
}

//////////////////////////////////////////////////////////////////////
// Метод Жордана - Гаусса с выбором по столбцу и строке

MATHBASE_API 
void _JordanGaussCR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX )
{
	if( pA->n_row() != pA->n_column() )
		throw "The matrix is not square";
	if( pA->n_row() != (long) pB->size() )
		throw "Internal problem - sizes of the source and destination matrix are not equal";

	long i, j, k;
	CDSRReal value;
	CDSRMMatrix<CDSRReal> matrix( (*pA) );
	CDSRMVector<CDSRReal> vector( (*pB) );
	CDSRMVector<long> row( pA->n_row() );
	CDSRMVector<long> col( pA->n_row() );

	pX->resize( pB->size() );

	for( i = 0; i < pA->n_row(); i++ )
		col[ i ] = row[ i ] = i;

	for( i = 0; i < pA->n_row(); i++ )
	{
		if( IsNull( matrix( row[ i ], col[ i ] ) ) )
			_IndexCR(i, &matrix, &row, &col );

		for( k = i; k < pA->n_row(); k++ )
		{
			value = matrix( row[ k ], col[ i ] );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ row[ k ] ] /= value;
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( row[ k ], col[ j ] ) /= value;
				matrix( row[ k ], col[ i ] ) = 1.0;
			}
		}

		for( k = i + 1; k < pA->n_row(); k++ )
		{
			value = matrix( row[ k ], col[ i ] );
			if( IsNotNull( value ) )
			{
				vector[ row[ k ] ] -= vector[ row[ i ] ];
				for( j = i + 1; j < pA->n_row(); j++ )
					matrix( row[ k ], col[ j ] ) -= matrix( row[ i ], col[ j ] );
				matrix( row[ k ], col[ i ] ) = 0.0;
			}
		}
	}

	for( i = pA->n_row() - 1; i > 0; i-- )
	{
		for( k = 0; k < i + 1; k++ )
		{
			value = matrix( row[ k ], col[ i ] );
			if( IsNotNull( value ) && IsNotOne( value ) )
			{
				vector[ row[ k ] ] /= value;
	   			for( j = k; j < i; j++ )
   					matrix( row[ k ], col[ j ] ) /= value;
				matrix( row[ k ], col[ i ] ) = 1.0;
			}
		}

		for( k = 0; k < i; k++ )
		{
			value = matrix( row[ k ], col[ i ] );
			if( IsNotNull( value ) )
			{
				vector[ row[ k ] ] -= vector[ row[ i ] ];
				matrix( row[ k ], col[ i ] ) = 0.0;
			}
		}
	}

	vector[ row[ 0 ] ] /= matrix( row[ 0 ], col[ 0 ] );
	matrix( row[ 0 ], col[ 0 ] ) = 1.0;

	for( i = 0; i < pA->n_row(); i++ )
		( *pX )[ col[ i ] ] = vector[ row[ i ] ];
}

//////////////////////////////////////////////////////////////////////
