

#include "../execop_call.h"
#include "../../vmevallink.h"

///////////////////////////////////////////////////////////////////////////////

__HMATHLNGDLL__
void _call_dsrop_Sub_integer( UniWord *arg )
{
	_dsrop_Sub_integer( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Sub_rational( UniWord *arg )
{
	_dsrop_Sub_rational( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Sub_real( UniWord *arg )
{
	_dsrop_Sub_real( *(arg - 2), *(arg - 2), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Sub_complex( UniWord *arg )
{
	_dsrop_Sub_complex( *(arg - 2), *(arg - 2), *(arg - 1) );
}

__HMATHLNGDLL__
void _call_dsrop_PolynomialSub_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialSub_integer( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialSub_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialSub_real( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialSub_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_PolynomialSub_complex( (arg - 2)->getPolynomial(), (arg - 1)->getPolynomial() );
}

__HMATHLNGDLL__
void _call_dsrop_RationalFunSub_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunSub_integer( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunSub_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunSub_real( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunSub_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_RationalFunSub_complex( (arg - 2)->getRationalFun(), (arg - 1)->getRationalFun() );
}

__HMATHLNGDLL__
void _call_dsrop_VectorSub_integer( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorSub_integer( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorSub_rational( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorSub_rational( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorSub_real( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorSub_real( (arg - 2)->getVector(), (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorSub_complex( UniWord *arg )
{
	*(arg - 2) = _dsrop_VectorSub_complex( (arg - 2)->getVector(), (arg - 1)->getVector() );
}

__HMATHLNGDLL__
void _call_dsrop_Minus_integer( UniWord *arg )
{
	_dsrop_Minus_integer( *(arg - 1), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Minus_rational( UniWord *arg )
{
	_dsrop_Minus_rational( *(arg - 1), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Minus_real( UniWord *arg )
{
	_dsrop_Minus_real( *(arg - 1), *(arg - 1) );
}
__HMATHLNGDLL__
void _call_dsrop_Minus_complex( UniWord *arg )
{
	_dsrop_Minus_complex( *(arg - 1), *(arg - 1) );
}

__HMATHLNGDLL__
void _call_dsrop_PolynomialMinus_integer( UniWord *arg )
{
	*(arg - 1) = _dsrop_PolynomialMinus_integer( (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialMinus_real( UniWord *arg )
{
	*(arg - 1) = _dsrop_PolynomialMinus_real( (arg - 1)->getPolynomial() );
}
__HMATHLNGDLL__
void _call_dsrop_PolynomialMinus_complex( UniWord *arg )
{
	*(arg - 1) = _dsrop_PolynomialMinus_complex( (arg - 1)->getPolynomial() );
}

__HMATHLNGDLL__
void _call_dsrop_RationalFunMinus_integer( UniWord *arg )
{
	*(arg - 1) = _dsrop_RationalFunMinus_integer( (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunMinus_real( UniWord *arg )
{
	*(arg - 1) = _dsrop_RationalFunMinus_real( (arg - 1)->getRationalFun() );
}
__HMATHLNGDLL__
void _call_dsrop_RationalFunMinus_complex( UniWord *arg )
{
	*(arg - 1) = _dsrop_RationalFunMinus_complex( (arg - 1)->getRationalFun() );
}

__HMATHLNGDLL__
void _call_dsrop_VectorMinus_integer( UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorMinus_integer( (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMinus_rational( UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorMinus_rational( (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMinus_real( UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorMinus_real( (arg - 1)->getVector() );
}
__HMATHLNGDLL__
void _call_dsrop_VectorMinus_complex( UniWord *arg )
{
	*(arg - 1) = _dsrop_VectorMinus_complex( (arg - 1)->getVector() );
}

__HMATHLNGDLL__
void _call_dsrop_SetSub( UniWord *arg )
{
	*(arg - 2) = _dsrop_SetSub( (arg - 2)->getSet(), (arg - 1)->getSet() );
}

///////////////////////////////////////////////////////////////////////////////

typedef void (*SUBCALL_SUB)( UniWord *arg );
#define __Call_Sub_subcalls_LENGTH	29
static SUBCALL_SUB __Call_Sub_subcalls[ __Call_Sub_subcalls_LENGTH ] = 
{
	_call_dsrop_Sub_integer,
	_call_dsrop_Sub_rational,
	_call_dsrop_Sub_real,
	_call_dsrop_Sub_complex,
	_call_dsrop_PolynomialSub_integer,
	_call_dsrop_PolynomialSub_real,
	_call_dsrop_PolynomialSub_complex,
	_call_dsrop_RationalFunSub_integer,
	_call_dsrop_RationalFunSub_real,
	_call_dsrop_RationalFunSub_complex,
	_call_dsrop_VectorSub_integer,
	_call_dsrop_VectorSub_rational,
	_call_dsrop_VectorSub_real,
	_call_dsrop_VectorSub_complex,
	_call_dsrop_Minus_integer,
	_call_dsrop_Minus_rational,
	_call_dsrop_Minus_real,
	_call_dsrop_Minus_complex,
	_call_dsrop_PolynomialMinus_integer,
	_call_dsrop_PolynomialMinus_real,
	_call_dsrop_PolynomialMinus_complex,
	_call_dsrop_RationalFunMinus_integer,
	_call_dsrop_RationalFunMinus_real,
	_call_dsrop_RationalFunMinus_complex,
	_call_dsrop_VectorMinus_integer,
	_call_dsrop_VectorMinus_rational,
	_call_dsrop_VectorMinus_real,
	_call_dsrop_VectorMinus_complex,
	_call_dsrop_SetSub
};
long __Call_Sub( CDSR_VMEval& /*vm*/, MMD_Address& addr, UniWord *arg )
{
#if _DEBUG
	if( addr.param2 < 0 || 
		addr.param2 >= __Call_Sub_subcalls_LENGTH )
		throw _T("__Call_Sub : internal error, out of range");
#endif
	__Call_Sub_subcalls[ addr.param2 ]( arg );
	return 1 - addr.param3;
}

///////////////////////////////////////////////////////////////////////////////
