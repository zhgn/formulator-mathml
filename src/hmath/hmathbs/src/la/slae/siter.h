

#ifndef __ALMASLAE_SITER_H__
#define __ALMASLAE_SITER_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrnumbers/mathconst.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

MATHBASE_API void _SimpleIterations( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _SimpleIterationsC( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _SimpleIterationsR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _SimpleIterationsCR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_SITER_H__
