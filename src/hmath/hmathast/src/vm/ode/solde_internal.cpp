

#include "solde_internal.h"

/////////////////////////////////////////////////////////////////////////////

void RunOneStep( CDSR_VMEval *pOdeRTI, CDSRReal& time, 
	CDSRArray<CDSRReal>* pFunc, CDSRArray<CDSRReal>* pFuncD )
{
	unsigned long i;

#ifdef _DEBUG
        if ( (long) pFunc->size() != pOdeRTI->getEquation_Number() ||
                (long) pFunc->size() != pOdeRTI->getEquation_UnknownNumber() )
		throw _T("::RunOneStep : internal error");
#endif

/*
	if( pOdeRTI->getEquation_Type() != DSRDATA_TYPE_REAL )
		throw _T("SODE must be of real type");
*/
	UniWord uw( time );
	pOdeRTI->getEquation_setTimeVar( uw );

	for ( i = 0; i < pFunc->size(); i++ )
	{
		UniWord uw2( (*pFunc)[ i ] );
		pOdeRTI->getEquation_setInitialXVar( i, uw2 );
	}

	UniWord dx = CDSRReal( 0.0 );
	for ( i = 0; i < pFunc->size(); i++ )
	{
		pOdeRTI->execEquationRight( i, &dx );
		(*pFuncD)[ i ] = dx.getReal();
	}
};

/////////////////////////////////////////////////////////////////////////////

bool SoldeOneStep( CDSR_VMEval *pOdeRTI, CDSRReal& time, 
	CDSRArray<CDSRReal>* pFunc, CDSRArray<CDSRReal>* pFuncD, 
	COdeOneStepParam& param, CDSRReal& rlError, CDSRReal rlPrec )
{
	CDSRArray<CDSRReal> func( (*pFunc) );
	CDSRArray<CDSRReal> funcD1( pFunc->size() );
	CDSRArray<CDSRReal> funcD2( pFunc->size() );

	unsigned long i;
	for ( i = 0; i < pFunc->size(); i++ )
		(*pFunc)[ i ] = func[ i ] + param.b21h * (*pFuncD)[ i ];

	//
	RunOneStep( pOdeRTI, time, pFunc, &funcD1 );
	rlError = 0.0;
	for ( i = 0; i < pFunc->size(); i++ )
	{
		(*pFunc)[ i ] = func[ i ] + param.p21h * (*pFuncD)[ i ] + param.p22h * funcD1[ i ];
		rlError = qMax( rlError, fabs( param.p22h * (funcD1[ i ] - (*pFuncD)[ i ]) ) );
	}
	if ( rlError < rlPrec )
	{
		RunOneStep( pOdeRTI, time, pFunc, pFuncD );
		return true;
	}

	//
	RunOneStep( pOdeRTI, time, pFunc, &funcD2 );
	rlError = 0.0;
	for ( i = 0; i < pFunc->size(); i++ )
	{
		(*pFunc)[ i ] = func[ i ] + param.p31h * (*pFuncD)[ i ] + param.p32h * funcD1[ i ] + param.p33h * funcD2[ i ];
		rlError = qMax( rlError, fabs( param.pe31h * (*pFuncD)[ i ] + param.pe32h * funcD1[ i ] + param.p33h * funcD2[ i ] ) );
	}
	if ( rlError < rlPrec )
	{
		RunOneStep( pOdeRTI, time, pFunc, pFuncD );
		return true;
	}

	return false;
}

/////////////////////////////////////////////////////////////////////////////
