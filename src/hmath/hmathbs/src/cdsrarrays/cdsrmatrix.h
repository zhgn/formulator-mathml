

#ifndef __COMMON_CDSRMATRIX_H__
#define __COMMON_CDSRMATRIX_H__

#include "cdsrbasematrix.h"

template<class T> class CDSRMatrix : public CDSRBaseMatrix<T>
{
public:
	CDSRMatrix( const CDSRMatrix& matrix )
		: CDSRBaseMatrix<T>( matrix )
	{
	}
	CDSRMatrix( typename CDSRBaseMatrix<T>::iterator first, long row, long col )
		: CDSRBaseMatrix<T>( first, row, col )
	{
	}
	CDSRMatrix( typename CDSRBaseMatrix<T>::const_iterator first, long row, long col )
		: CDSRBaseMatrix<T>( first, row, col )
	{
	}
	CDSRMatrix( long row = 0, long col = 0, const T& val = T() )
		: CDSRBaseMatrix<T>( row, col, val )
	{
	}
	CDSRMatrix( T **first, long row, long col )
		: CDSRBaseMatrix<T>( first, row, col )
	{
	}
	CDSRMatrix( const T **first, long row, long col )
		: CDSRBaseMatrix<T>( first, row, col )
	{
	}
	virtual ~CDSRMatrix()
	{
	}
};

//////////////////////////////////////////////////////////////////////

#endif // __COMMON_ÑDSRMATRIX_H__
