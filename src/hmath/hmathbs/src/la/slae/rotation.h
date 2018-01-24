

#ifndef __ALMASLAE_ROTATION_H__
#define __ALMASLAE_ROTATION_H__

#include "../../hmathbs_global.h"
#include "../../cdsrnumbers/number.h"
#include "../../cdsrnumbers/mathconst.h"
#include "../../cdsrarrays/cdsrmvector.h"
#include "../../cdsrarrays/cdsrmmatrix.h"

MATHBASE_API void _Rotation( CDSRMMatrix<CDSRReal> *pA, CDSRMVector<CDSRReal> *pB, CDSRMVector<CDSRReal> *pX );

//////////////////////////////////////////////////////////////////////
#endif // __ALMASLAE_ROTATION_H__
