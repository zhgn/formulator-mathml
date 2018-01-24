

#ifndef __ALMASLAE_RELAXATION_H__
#define __ALMASLAE_RELAXATION_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrnumbers/mathconst.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

MATHBASE_API void _Relaxation( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, unsigned long nRelaxCount = 1, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _RelaxationC( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, unsigned long nRelaxCount = 1, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _RelaxationR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, unsigned long nRelaxCount = 1, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );
MATHBASE_API void _RelaxationCR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX, unsigned long nRelaxCount = 1, CDSRReal rlPrecision = ALMASLAE_SITER_PREC );

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_RELAXATION_H__
