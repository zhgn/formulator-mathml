

#if !defined(__ALMA_POLINOMS_H__)
#define __ALMA_POLINOMS_H__

#include "../hmathbs_global.h"
#include "../cdsrnumbers/number.h"
#include "../cdsrnumbers/rootinfo.h"
#include "../cdsrnumbers/mathconst.h"
#include "../cdsrarrays/cdsrarray.h"
#include "../cdsrarrays/cdsrmatrix.h"

//////////////////////////////////////////////////////////////////////

MATHBASE_API void _calcPolinom(CDSRArray<CDSRReal>*& pPolinom, CDSRReal rlArg, CDSRReal& rlResult);
MATHBASE_API void _calcPolinom(CDSRArray<CDSRReal>*& pPolinom, CDSRComplex cxArg, CDSRComplex& cxResult);
MATHBASE_API void _calcPolinom(CDSRArray<CDSRComplex>* pPolinom, CDSRComplex cxArg, CDSRComplex& cxResult);
MATHBASE_API void _calcPolinom(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRReal>*& pArg, CDSRArray<CDSRReal>*& pResPolinom);
MATHBASE_API void _calcPolinom(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRComplex>*& pArg, CDSRArray<CDSRComplex>*& pResPolinom);


MATHBASE_API
void _derivativePolinom(CDSRArray<CDSRReal>* pPolinom, unsigned long nDerivative, CDSRArray<CDSRReal>* pDerivative);
MATHBASE_API
void _derivativePolinom(CDSRArray<CDSRReal>*& pPolinom, unsigned long nDerivative, CDSRReal rlArg, CDSRReal& rlResult);
MATHBASE_API
void _derivativePolinom(CDSRArray<CDSRReal>*& pPolinom, unsigned long nDerivative, CDSRComplex cxArg, CDSRComplex& cxResult);
MATHBASE_API
void _derivativePolinom(CDSRArray<CDSRComplex>* pPolinom, unsigned long nDerivative, CDSRArray<CDSRComplex>* pDerivative);
MATHBASE_API
void _derivativePolinom(CDSRArray<CDSRComplex>* pPolinom, unsigned long nDerivative, CDSRComplex cxArg, CDSRComplex& cxResult);
MATHBASE_API
void _derivativePolinom(CDSRArray<CDSRReal>*& pPolinom, unsigned long nDerivative, CDSRArray<CDSRReal>*& rlArg, CDSRArray<CDSRReal>*& rlResult);
MATHBASE_API
void _derivativePolinom(CDSRArray<CDSRReal>*& pPolinom, unsigned long nDerivative, CDSRArray<CDSRComplex>*& cxArg, CDSRArray<CDSRComplex>*& cxResult);


MATHBASE_API
void _newtonPolinomsRoot(CDSRArray<CDSRReal>*& pPolinom, CDSRReal& rlRoot, unsigned long nMaxItrs, CDSRReal rlPrec);
MATHBASE_API
void _newtonPolinomsRoot(CDSRArray<CDSRReal>*& pPolinom, CDSRComplex& cxRoot, unsigned long nMaxItrs, CDSRReal rlPrec);
MATHBASE_API
void _newtonPolinomsRoot(CDSRArray<CDSRComplex>* pPolinom, CDSRComplex& cxRoot, unsigned long nMaxItrs, CDSRReal rlPrec);


MATHBASE_API
void _divOnRoot(CDSRArray<CDSRReal>*& pPolinom, CDSRReal rlRoot, CDSRArray<CDSRReal>*& pResPolinom);
MATHBASE_API
void _divOnRoot(CDSRArray<CDSRComplex>* pPolinom, CDSRComplex root, CDSRArray<CDSRComplex>* pResPolinom);


MATHBASE_API
void _replaceX(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRReal>*& pResPolinom);

MATHBASE_API
CDSRReal _maxElement(CDSRArray<CDSRReal>*& pPolinom);

MATHBASE_API
void _sumOfPoly(CDSRArray<CDSRReal>* pPolinom1, CDSRArray<CDSRReal>* pPolinom2, CDSRArray<CDSRReal>* pResPolinom);
MATHBASE_API
void _sumOfPoly(CDSRArray<CDSRComplex>* pPolinom1, CDSRArray<CDSRComplex>* pPolinom2, CDSRArray<CDSRComplex>* pResPolinom);

MATHBASE_API
void _divOfPoly(CDSRArray<CDSRReal>* pDivPolinom, CDSRArray<CDSRReal>* pDevPolinom, CDSRArray<CDSRReal>* pResPolinom, CDSRArray<CDSRReal>* pOstPolinom);
MATHBASE_API
void _divOfPoly(CDSRArray<CDSRComplex>* pDivPolinom, CDSRArray<CDSRComplex>* pDevPolinom, CDSRArray<CDSRComplex>* pResPolinom, CDSRArray<CDSRComplex>* pOstPolinom);

MATHBASE_API
void _greatCommonDevider(CDSRArray<CDSRReal>* pFstPolinom, CDSRArray<CDSRReal>* pSecPolinom, CDSRArray<CDSRReal>* pResPolinom);
MATHBASE_API
void _greatCommonDevider(CDSRArray<CDSRComplex>* pFstPolinom, CDSRArray<CDSRComplex>* pSecPolinom, CDSRArray<CDSRComplex>* pResPolinom);
MATHBASE_API
void _leastCommonMultiple(CDSRArray<CDSRReal>*& pFstPolinom, CDSRArray<CDSRReal>*& pSecPolinom, CDSRArray<CDSRReal>*& pResPolinom);

MATHBASE_API
void _linSqrPolinoms(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRReal>*& pSqrPolinom, CDSRArray<CDSRReal>*& pResPolinom, CDSRReal rlPres, unsigned long nMaxItrs);

MATHBASE_API
void _multyOfPoly(CDSRArray<CDSRReal>* pFstPolinom, CDSRArray<CDSRReal>* pSecPolinom, CDSRArray<CDSRReal>* pResPolinom);
MATHBASE_API
void _multyOfPoly(CDSRArray<CDSRComplex>* pFstPolinom, CDSRArray<CDSRComplex>* pSecPolinom, CDSRArray<CDSRComplex>* pResPolinom);

MATHBASE_API
void _sqrPoly(CDSRArray<CDSRReal>*& pSqrPolinom, CDSRReal& rlFstRoot, CDSRReal& rlSecRoot, bool& bFeature);
MATHBASE_API
void _divOnSquarePoli(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRReal>*& pSqrPolinom, CDSRArray<CDSRReal>*& pResPolinom);

MATHBASE_API
void _mutuallySimple(CDSRArray<CDSRReal>*& pFstPolinom, CDSRArray<CDSRReal>*& pSecPolinom, bool& bSimple);

MATHBASE_API
void _isSimple(CDSRArray<CDSRReal>*& pPolinom, bool& bSimple);

MATHBASE_API
void _rootsOfPolinom(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<ROOT_INFO>*& pRootsArray, CDSRReal rlPrec = POLYNOM_PRECISION);

MATHBASE_API
void _poly4ComplexRoots(CDSRArray<ROOT_INFO>* pRootsArray, CDSRArray<CDSRComplex>* pPolynom);

MATHBASE_API 
void _integral(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRReal>*& pIntegral, CDSRReal rlBegX = 0, CDSRReal rlBegY = 0);

MATHBASE_API 
void _defIntegral(CDSRArray<CDSRReal>*& pPolinom, CDSRReal rlLo, CDSRReal rlHi, CDSRReal& rlRes);

MATHBASE_API 
void _extremum(CDSRArray<CDSRReal>*& pPolinom, CDSRMatrix<CDSRReal>*& pResMatrix);

MATHBASE_API 
void _undefIntegral(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRReal>*& pIntegral, CDSRArray<CDSRReal>*& pBegPolinom);

MATHBASE_API 
void _monteCarloPolinomRoot(CDSRArray<CDSRReal>*& pPolinom, CDSRReal& rlLo, CDSRReal& rlHi, CDSRReal rlPrec);

MATHBASE_API 
void _inequality(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRReal>*& pChangeSignPoints, CDSRReal rlPrec = 1e-6);

MATHBASE_API
void _factorisationOfPolinom(CDSRArray<CDSRReal>*& pPolinom, CDSRArray<CDSRArray<CDSRReal>*>& MultipliersArray, CDSRArray<unsigned long>& MultiplicityArray, CDSRReal rlPrec = 1e-6);

MATHBASE_API
void _rootsOfCubEquation(CDSRArray<CDSRReal>* pPolynom, CDSRArray<ROOT_INFO>*& pRootsArray);

MATHBASE_API
void _rootsOfQuartEquation(CDSRArray<CDSRReal>* pPolynom, CDSRArray<ROOT_INFO>*& pRootsArray);

MATHBASE_API
void _rootsOfSqrEquation(CDSRArray<CDSRReal>* pPolynom, CDSRArray<ROOT_INFO>*& pRootsArray);

MATHBASE_API
void _powPoly(CDSRArray<CDSRReal>* pPolynom, unsigned power, CDSRArray<CDSRReal>* pResult);

MATHBASE_API
void _firstOrderEquation(CDSRArray<CDSRComplex>& polynom, CDSRComplex& result);

MATHBASE_API
void _secondOrderEquation(CDSRArray<CDSRComplex>& polynom, CDSRArray<CDSRComplex>& result);

MATHBASE_API
void _thirdOrderEquation(CDSRArray<CDSRComplex>& polynom, CDSRArray<CDSRComplex>& result);

MATHBASE_API
void _fourthOrderEquation(CDSRArray<CDSRComplex>& polynom, CDSRArray<CDSRComplex>& result);

MATHBASE_API
void _nthOrderEquation(CDSRArray<CDSRComplex>& polynom, CDSRArray<CDSRComplex>& result, CDSRReal rlPrec = 1e-6);

//////////////////////////////////////////////////////////////////////
#endif //__ALMA_POLINOMS_H__
