

#ifndef __ALMASLAE_GAUSS_H__
#define __ALMASLAE_GAUSS_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

MATHBASE_API void _Gauss( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _GaussC( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _GaussR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _GaussCR (CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_GAUSS_H__
