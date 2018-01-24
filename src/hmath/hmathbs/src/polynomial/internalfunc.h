

#if !defined(__ALMA_POLINOMS_INTERNAL_FUNC_H__)
#define __ALMA_POLINOMS_INTERNAL_FUNC_H__

#include "../cdsrnumbers/number.h"
#include "../cdsrnumbers/mathconst.h"
#include "../cdsrarrays/cdsrarray.h"
#include "../cdsrarrays/cdsrmatrix.h"

inline bool IsNoll(CDSRReal _arg)
{
	return (fabs(_arg) < MATH_REAL_EPSILON);
};

inline bool IsNoll(CDSRComplex _arg)
{
	return (abs(_arg) < MATH_REAL_EPSILON);
};

void GetHurwitzMatrix(CDSRArray<CDSRReal>& polynom, long order, CDSRMatrix<CDSRReal>& HurwitzMatrix);
void ComplexNumberNthRoot(CDSRComplex x, long power, CDSRArray<CDSRComplex>& roots);
double fact( long ii );
double C_nj( long n, long j);
void complexBinomNewton(CDSRArray<CDSRComplex>& nBinomial, long lPower, CDSRArray<CDSRComplex>& nResult);

class QString;
QString CreateComplexNumberString(CDSRComplex number);
QString CreatePolynomAnyPowerString(CDSRArray<CDSRComplex>& polynom);
#endif //__ALMA_POLINOMS_INTERNAL_FUNC_H__
