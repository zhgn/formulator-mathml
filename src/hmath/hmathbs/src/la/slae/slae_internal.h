

#ifndef __ALMASLAE_INTERNAL_INDEX_H__
#define __ALMASLAE_INTERNAL_INDEX_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrnumbers/mathconst.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

//////////////////////////////////////////////////////////////////////

void _IndexCR( long i, CDSRMMatrix<CDSRReal> *pMatrix, CDSRMVector<long> *pRow, CDSRMVector<long> *pCol );
void _IndexR( long i, CDSRMMatrix<CDSRReal> *pMatrix, CDSRMVector<long> *pRow );
void _IndexC( long i, CDSRMMatrix<CDSRReal> *pMatrix, CDSRMVector<long> *pCol );

//////////////////////////////////////////////////////////////////////

inline 
bool IsNull( const CDSRReal& value )
{
	return ( fabs( value ) < MATH_REAL_EPSILON );
}

inline 
bool IsOne( const CDSRReal& value )
{
	return ( fabs( value - 1.0 ) < MATH_REAL_EPSILON );
}

inline 
bool IsNotNull( const CDSRReal& value )
{
	return ( fabs( value ) > MATH_REAL_EPSILON );
}

inline 
bool IsNotOne( const CDSRReal& value )
{
	return ( fabs( value - 1.0 ) > MATH_REAL_EPSILON );
}

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_INTERNAL_INDEX_H__
