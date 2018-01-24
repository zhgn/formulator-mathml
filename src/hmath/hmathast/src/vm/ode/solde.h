

#ifndef __ODE_SOLDE_H__
#define __ODE_SOLDE_H__

#include "../../hmathast_global.h"
#include "HMathBS/inumber.h"
#include "HMathBS/imathconst.h"
#include "HMathBS/iarray.h"
#include "../vmeval.h"

__HMATHLNGDLL__
int _solde( CDSR_VMEval *pOdeRTI, 
	CDSRArray<CDSRReal> *pInitials, 
	CDSRArray<CDSRReal> *pArg, 
	CDSRMatrix<CDSRReal > *pFunc, 
	CDSRReal rlPrec = ALMA_ODE_PREC, 
	unsigned long nMaxIteration = 2048 );

__HMATHLNGDLL__
void _solde( CDSR_VMEval *pOdeRTI, 
	CDSRArray<CDSRReal>* pInitials, 
	CDSRArray<CDSRReal> *pArg, 
	CDSRArray<CDSRArray<CDSRReal>*> *pX, 
	CDSRArray<CDSRArray<CDSRReal>*> *pDerX = NULL, 
	CDSRArray<CDSRArray<CDSRReal>*> *pMis = NULL, 
	CDSRReal rlPrec = ALMA_ODE_PREC, 
	unsigned long nMaxIteration = 2048 );

/////////////////////////////////////////////////////////////////////////////
#endif //__ODE_SOLDE_H__
