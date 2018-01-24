

#ifndef __ALMASLAE_COMMONSLAE_H__
#define __ALMASLAE_COMMONSLAE_H__

#include "HMathBS/iarray.h"
#include "HMathBS/inumber.h"
#include "../../hmathbs_global.h"

//////////////////////////////////////////////////////////////////////

MATHBASE_API void _Inverse( CDSRMMatrix<CDSRComplex> *pA, CDSRMMatrix<CDSRComplex> *pInv );
MATHBASE_API void _DeterminantCR( CDSRMMatrix<CDSRInteger> *pA, CDSRInteger& rlDet );
MATHBASE_API void _DeterminantCR( CDSRMMatrix<CDSRComplex> *pA, CDSRComplex& rlDet );

MATHBASE_API void _Inverse( CDSRMMatrix<CDSRReal> *pA, CDSRMMatrix<CDSRReal> *pInv );
MATHBASE_API void _InverseC( CDSRMMatrix<CDSRReal> *pA, CDSRMMatrix<CDSRReal> *pInv );
MATHBASE_API void _InverseR( CDSRMMatrix<CDSRReal> *pA, CDSRMMatrix<CDSRReal> *pInv );
MATHBASE_API void _InverseCR( CDSRMMatrix<CDSRReal> *pA, CDSRMMatrix<CDSRReal> *pInv );

MATHBASE_API void _Determinant( CDSRMMatrix<CDSRReal> *pA, CDSRReal& rlDet );
MATHBASE_API void _DeterminantC( CDSRMMatrix<CDSRReal> *pA, CDSRReal& rlDet );
MATHBASE_API void _DeterminantR( CDSRMMatrix<CDSRReal> *pA, CDSRReal& rlDet );
MATHBASE_API void _DeterminantCR( CDSRMMatrix<CDSRReal> *pA, CDSRReal& rlDet );

MATHBASE_API void _LSolve(CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, std::string _method = "" );

//////////////////////////////////////////////////////////////////////

#endif // __ALMASLAE_COMMONSLAE_H__
