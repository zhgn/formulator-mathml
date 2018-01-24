

#ifndef __ALMASLAE_JORDANGAUSS_H__
#define __ALMASLAE_JORDANGAUSS_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

MATHBASE_API void _JordanGauss( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _JordanGaussC( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _JordanGaussR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _JordanGaussCR( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_JORDANGAUSS_H__
