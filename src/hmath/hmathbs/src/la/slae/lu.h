

#ifndef __ALMASLAE_LU_H__
#define __ALMASLAE_LU_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

MATHBASE_API void _LU( CDSRMMatrix<CDSRReal> *pA );
MATHBASE_API void _LU_Result( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _LU( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );

/*

//////////////////////////////////////////////////////////////////////

MATHBASE_API void _LU( CDSRBlkDMatrix<CDSRReal> *pA );
MATHBASE_API void _LU_Result( CDSRBlkDMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _LU( CDSRBlkDMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );

//////////////////////////////////////////////////////////////////////

MATHBASE_API void _LU( CDSRSplineMatrix<CDSRReal> *pA );
MATHBASE_API void _LU_Result( CDSRSplineMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );
MATHBASE_API void _LU( CDSRSplineMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );

MATHBASE_API void _LU_Result( CDSRSplineMatrix<CDSRReal> *pA, CDSRMMatrix<CDSRReal> *pB, CDSRMMatrix<CDSRReal> *pX );
MATHBASE_API void _LU( CDSRSplineMatrix<CDSRReal> *pA, CDSRMMatrix<CDSRReal> *pB, CDSRMMatrix<CDSRReal> *pX );

*/

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_LU_H__
