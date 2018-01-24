

#ifndef __ODE_SOLDE_INTERNAL_H__
#define __ODE_SOLDE_INTERNAL_H__

#include "HMathBS/inumber.h"
#include "HMathBS/iarray.h"
#include "odeonestepparam.h"
#include "../vmeval.h"

void RunOneStep( CDSR_VMEval *pOdeRTI, CDSRReal& time, 
	CDSRArray<CDSRReal>* pFunc, CDSRArray<CDSRReal>* pFuncD );

bool SoldeOneStep( CDSR_VMEval *pOdeRTI, CDSRReal& time, 
	CDSRArray<CDSRReal>* pFunc, CDSRArray<CDSRReal>* pFuncD, 
	COdeOneStepParam& param, CDSRReal& rlError, CDSRReal rlPrec );

/////////////////////////////////////////////////////////////////////////////
#endif // __ODE_SOLDE_INTERNAL_H__
