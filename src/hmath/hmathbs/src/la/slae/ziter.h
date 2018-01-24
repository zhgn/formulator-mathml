

#ifndef __ALMASLAE_ZITER_H__
#define __ALMASLAE_ZITER_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrnumbers/mathconst.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

MATHBASE_API void _ZeidIterations( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _ZeidIterationsC( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _ZeidIterationsR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _ZeidIterationsCR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_ZITER_H__
