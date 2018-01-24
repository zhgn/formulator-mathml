

#if !defined(__ALMA_EIGENVAL_H__)
#define __ALMA_EIGENVAL_H__

#include "../hmathbs_global.h"
#include "../cdsrnumbers/number.h"
#include "../cdsrnumbers/rootinfo.h"
#include "../cdsrnumbers/mathconst.h"
#include "../cdsrarrays/cdsrmmatrix.h"

//////////////////////////////////////////////////////////////////////

MATHBASE_API
void _eigenValLevere( CDSRMMatrix<CDSRReal>& A, CDSRArray<ROOT_INFO>& Lyambda, CDSRArray<CDSRReal>& polynom, CDSRReal rlPrec = EIGENVALUES_PRECISION);

MATHBASE_API
void _eigenValFadeev( CDSRMMatrix<CDSRReal>& A, CDSRArray<ROOT_INFO>& Lyambda, CDSRArray<CDSRReal>& polynom, CDSRReal rlPrec = EIGENVALUES_PRECISION);

MATHBASE_API
void _eigenValDanilev( CDSRMMatrix<CDSRReal>& A, CDSRArray<ROOT_INFO>& Lyambda, CDSRReal rlPrec = EIGENVALUES_PRECISION);

MATHBASE_API
void _eigenValKrilov( CDSRMMatrix<CDSRReal>& A, CDSRArray<ROOT_INFO>& Lyambda, CDSRArray<CDSRReal>& polynom, CDSRReal rlPrec = EIGENVALUES_PRECISION);

MATHBASE_API
void _eigenValJacobi( CDSRMMatrix<CDSRReal>& A, CDSRArray<CDSRReal>& Lyambda, CDSRReal rlPrec = EIGENVALUES_PRECISION);

//////////////////////////////////////////////////////////////////////

#endif //__ALMA_EIGENVAL_H__ corollary
