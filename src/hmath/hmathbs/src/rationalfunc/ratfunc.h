

#if !defined(__ALMA_RATIONAL_FUNCTIONS_H__)
#define __ALMA_RATIONAL_FUNCTIONS_H__

#include "../hmathbs_global.h"
#include "../cdsrnumbers/number.h"

//////////////////////////////////////////////////////////////////////


MATHBASE_API 
void _calcFraction(CDSRArray<CDSRReal>* pNumerator, CDSRArray<CDSRReal>* pDenominator, CDSRReal rlArg, CDSRReal& rlResult);
MATHBASE_API 
void _calcFraction(CDSRArray<CDSRReal>* pNumerator, CDSRArray<CDSRReal>* pDenominator, CDSRComplex rlArg, CDSRComplex& rlResult);
MATHBASE_API 
void _calcFraction(CDSRArray<CDSRComplex>* pNumerator, CDSRArray<CDSRComplex>* pDenominator, CDSRComplex rlArg, CDSRComplex& rlResult);


MATHBASE_API
void _partFractDecompos(CDSRArray<CDSRReal>* pNumerator, CDSRArray<CDSRReal>* pDenominator, CDSRArray<CDSRArray<CDSRReal>*>& partNums, CDSRArray<CDSRArray<CDSRReal>*>& partDenoms, CDSRArray<unsigned long>& MultiplicityArray);
MATHBASE_API
void _partFractDecomposComplex(CDSRArray<CDSRReal>* pNumerator, CDSRArray<CDSRReal>* pDenominator, CDSRArray<CDSRComplex>& numCoefs, CDSRArray<CDSRComplex>& denomRoots, CDSRArray<unsigned long>& MultiplicityArray);


MATHBASE_API
void _rationalFuncDeriv(CDSRArray<CDSRReal>* pNum, CDSRArray<CDSRReal>* pDen, CDSRArray<CDSRReal>* pNumRes, CDSRArray<CDSRReal>* pDenRes);
MATHBASE_API
void _fractDeriativeComplex(CDSRArray<CDSRComplex>* pNumerator, CDSRArray<CDSRComplex>* pDenominator, CDSRArray<CDSRComplex>* pResNum, CDSRArray<CDSRComplex>* pResDenom);
MATHBASE_API
void _fractDeriativeComplex(CDSRArray<CDSRComplex>* pNumerator, CDSRArray<CDSRComplex>* pDenominator, long nDerivative, CDSRComplex arg, CDSRComplex& res);


MATHBASE_API
void _rationalFuncsSum(CDSRArray<CDSRReal>* pNum1, CDSRArray<CDSRReal>* pDen1, CDSRArray<CDSRReal>* pNum2, CDSRArray<CDSRReal>* pDen2, CDSRArray<CDSRReal>* pNumRes, CDSRArray<CDSRReal>* pDenRes);
MATHBASE_API
void _rationalFuncsSum(CDSRArray<CDSRComplex>* pNum1, CDSRArray<CDSRComplex>* pDen1, CDSRArray<CDSRComplex>* pNum2, CDSRArray<CDSRComplex>* pDen2, CDSRArray<CDSRComplex>* pNumRes, CDSRArray<CDSRComplex>* pDenRes);


MATHBASE_API
void _rationalFuncsMult(CDSRArray<CDSRReal>* pNum1, CDSRArray<CDSRReal>* pDen1, CDSRArray<CDSRReal>* pNum2, CDSRArray<CDSRReal>* pDen2, CDSRArray<CDSRReal>* pNumRes, CDSRArray<CDSRReal>* pDenRes);

MATHBASE_API
void _rationalFuncReduce(CDSRArray<CDSRReal>* pNum, CDSRArray<CDSRReal>* pDen, CDSRArray<CDSRReal>* pNumRes, CDSRArray<CDSRReal>* pDenRes);

//////////////////////////////////////////////////////////////////////
#endif //__ALMA_RATIONAL_FUNCTIONS_H__
