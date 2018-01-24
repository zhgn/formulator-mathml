

#if !defined(__ALMA_RF_INTERNAL_FUNC_H__)
#define __ALMA_RF_INTERNAL_FUNC_H__

#include "../cdsrnumbers/number.h"
#include "../cdsrnumbers/mathconst.h"

inline bool IsNoll(CDSRComplex _arg)
{
	return (abs(_arg) < MATH_REAL_EPSILON);
};

double factor( long ii );

#endif //__ALMA_RF_INTERNAL_FUNC_H__
